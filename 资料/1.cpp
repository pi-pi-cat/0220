#include <QTreeView>
#include <QEvent>
#include <QApplication>
#include <QScrollBar>

// 创建事件过滤器类
class ScrollBarHider : public QObject
{
    Q_OBJECT
public:
    ScrollBarHider(QTreeView *treeView) : QObject(treeView), m_treeView(treeView)
    {
        // 初始化时隐藏滚动条
        m_treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        
        // 安装事件过滤器
        m_treeView->viewport()->installEventFilter(this);
    }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override
    {
        if (watched == m_treeView->viewport()) {
            if (event->type() == QEvent::Enter) {
                // 鼠标进入时显示滚动条
                m_treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
                m_treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
                return true;
            } else if (event->type() == QEvent::Leave) {
                // 鼠标离开时隐藏滚动条
                m_treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                m_treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                return true;
            }
        }
        return QObject::eventFilter(watched, event);
    }

private:
    QTreeView *m_treeView;
};

// 在使用时创建
QTreeView *treeView = new QTreeView(this);
// 安装事件过滤器
ScrollBarHider *hider = new ScrollBarHider(treeView);