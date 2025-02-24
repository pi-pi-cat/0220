#include "flowlayout.h"
#include <QWidget>

// FlowLayout构造函数,初始化布局管理器
// parent: 父组件
// margin: 边距
// hSpacing: 水平间距
// vSpacing: 垂直间距
FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

// 析构函数,清理所有布局项
FlowLayout::~FlowLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

// 添加布局项到布局管理器
void FlowLayout::addItem(QLayoutItem *item)
{
    itemList.append(item);
}

// 获取水平间距
// 如果设置了固定间距则返回该值,否则使用样式建议的间距
int FlowLayout::horizontalSpacing() const
{
    if (m_hSpace >= 0)
        return m_hSpace;
    return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
}

// 获取垂直间距
// 如果设置了固定间距则返回该值,否则使用样式建议的间距
int FlowLayout::verticalSpacing() const
{
    if (m_vSpace >= 0)
        return m_vSpace;
    return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
}

// 返回布局项数量
int FlowLayout::count() const
{
    return itemList.size();
}

// 返回指定索引的布局项
QLayoutItem *FlowLayout::itemAt(int index) const
{
    return itemList.value(index);
}

// 移除并返回指定索引的布局项
QLayoutItem *FlowLayout::takeAt(int index)
{
    if (index >= 0 && index < itemList.size())
        return itemList.takeAt(index);
    return nullptr;
}

// 返回布局可扩展的方向,流式布局不支持扩展
Qt::Orientations FlowLayout::expandingDirections() const
{
    return { };
}

// 指示布局的高度是否依赖于宽度
bool FlowLayout::hasHeightForWidth() const
{
    return true;
}

// 计算指定宽度下布局所需的高度
int FlowLayout::heightForWidth(int width) const
{
    int height = doLayout(QRect(0, 0, width, 0), true);
    return height;
}

// 设置布局的几何形状
void FlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

// 返回布局的建议大小
QSize FlowLayout::sizeHint() const
{
    return minimumSize();
}

// 计算布局的最小大小
// 基于所有子项的最小大小计算
QSize FlowLayout::minimumSize() const
{
    QSize size;
    for (const QLayoutItem *item : itemList)
        size = size.expandedTo(item->minimumSize());

    const QMargins margins = contentsMargins();
    size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
    return size;
}

// 执行实际的布局计算
// rect: 可用的矩形区域
// testOnly: 如果为true,只计算高度而不实际移动组件
int FlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    // 获取内容边距
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHeight = 0;

    // 遍历所有布局项进行排列
    for (QLayoutItem *item : itemList) {
        QWidget *wid = item->widget();
        // 计算水平间距
        int spaceX = horizontalSpacing();
        if (spaceX == -1)
            spaceX = wid->style()->layoutSpacing(
                QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        // 计算垂直间距
        int spaceY = verticalSpacing();
        if (spaceY == -1)
            spaceY = wid->style()->layoutSpacing(
                QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);

        // 计算下一个项的x坐标
        int nextX = x + item->sizeHint().width() + spaceX;
        // 如果超出右边界,换行
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0) {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        // 如果不是测试模式,设置项的几何形状
        if (!testOnly)
            item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }
    return y + lineHeight - rect.y() + bottom;
}

// 智能计算间距
// 根据父组件类型返回合适的间距值
int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parent = this->parent();
    if (!parent) {
        return -1;
    } else if (parent->isWidgetType()) {
        QWidget *pw = static_cast<QWidget *>(parent);
        return pw->style()->pixelMetric(pm, nullptr, pw);
    } else {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
