我可以帮你解决这个布局问题。在Qt中，当TreeView折叠状态变化时，保持固定间距需要一些特殊处理。

下面是一个解决方案，你可以使用QVBoxLayout并添加一个动态调整的spacer：

另一种方法是使用布局策略(QSizePolicy)，确保第一个TreeView在收缩和展开时都能正确响应：

如果你想要更灵活的解决方案，还可以完全自定义一个容器控件：

这三种解决方案各有特点：

1. **使用QSpacerItem**：最简单的解决方案，通过固定20px的spacer确保两个TreeView之间的间距恒定。

2. **使用QSizePolicy和重写sizeHint()**：更灵活的解决方案，通过自定义尺寸提示让第一个TreeView根据内容自动调整高度，同时保持布局间距。

3. **自定义容器控件**：最灵活的解决方案，完全控制子控件的位置和大小，但需要自己处理更多细节。

基于你的需求，我推荐使用第一种方案，因为它最简单且能满足你的要求。如果你的情况更复杂，或者需要更精确的控制，可以考虑第二或第三种方案。

你还需要注意的是，在使用这些方案时，确保你的QTreeView派生类能够正确报告其大小变化，这样布局才能及时更新。


#include <QWidget>
#include <QVBoxLayout>
#include <QTreeView>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        // 创建两个派生自QTreeView的控件
        m_treeView1 = new MyFirstTreeView(this);
        m_treeView2 = new MySecondTreeView(this);
        
        // 设置最大高度限制
        m_treeView1->setMaximumHeight(200);
        m_treeView2->setMaximumHeight(400);
        
        // 设置大小策略
        m_treeView1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        
        // 创建垂直布局
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(10, 10, 10, 10);
        mainLayout->setSpacing(20); // 直接设置为20px间距
        
        // 添加TreeView控件
        mainLayout->addWidget(m_treeView1);
        mainLayout->addWidget(m_treeView2);
        
        // 添加伸展因子
        mainLayout->addStretch();
    }

private:
    MyFirstTreeView *m_treeView1;
    MySecondTreeView *m_treeView2;
};

// 如果你的派生类需要更好地处理尺寸变化，可以重写sizeHint()方法
class MyFirstTreeView : public QTreeView
{
    Q_OBJECT
    
public:
    MyFirstTreeView(QWidget *parent = nullptr) : QTreeView(parent) {}
    
    // 根据展开/折叠状态提供正确的尺寸提示
    QSize sizeHint() const override
    {
        // 获取基类的尺寸提示
        QSize sh = QTreeView::sizeHint();
        
        // 如果想要紧凑显示，可以计算实际需要的高度
        // 这里是一个简单的示例，你可能需要基于实际内容调整
        int contentHeight = 0;
        for (int i = 0; i < model()->rowCount(); ++i) {
            if (isExpanded(model()->index(i, 0))) {
                // 计算展开项的高度
                contentHeight += sizeHintForRow(i);
                // 递归计算子项的高度
                // ...
            } else {
                // 只计算折叠项目的一行高度
                contentHeight += sizeHintForRow(i);
            }
        }
        
        // 加上边框、标题等固定高度
        contentHeight += frameWidth() * 2;
        contentHeight += header()->height();
        
        // 返回计算后的高度，但不超过最大高度限制
        sh.setHeight(qMin(contentHeight, maximumHeight()));
        return sh;
    }
    
    // 当内容变化时更新大小
    void updateGeometries() override
    {
        QTreeView::updateGeometries();
        updateGeometry(); // 这会触发父布局重新计算此控件的大小
    }
};

class MySecondTreeView : public QTreeView
{
    Q_OBJECT
    
public:
    MySecondTreeView(QWidget *parent = nullptr) : QTreeView(parent) {}
};