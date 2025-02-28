#include "projectgalleryview.h"
#include "../../layouts/flowlayout.h"
#include "../../components/projectcard/projectcard.h"
#include "../../../models/internal/projectitem.h"
#include <QDebug>

ProjectGalleryView::ProjectGalleryView(QWidget *parent) : QWidget(parent),
    m_addCard(nullptr)
{
    // Main horizontal layout
    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    // Create left panel (contains buttons)
    m_leftPanel = createLeftPanel();
    m_leftPanel->setFixedWidth(150);
    m_leftPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    // Create right panel (contains toolbar and scrollarea)
    m_rightPanel = new QWidget(this);
    m_rightLayout = new QVBoxLayout(m_rightPanel);
    m_rightLayout->setContentsMargins(10, 10, 10, 10);
    m_rightLayout->setSpacing(10);

    // Create toolbar
    m_toolbar = createToolbar();
    m_rightLayout->addWidget(m_toolbar);

    // Create scroll area with flow layout
    m_scrollArea = new QScrollArea(m_rightPanel);
    m_scrollArea->setWidgetResizable(true);

    m_scrollContent = new QWidget(m_scrollArea);
    m_flowLayout = new FlowLayout(m_scrollContent, 10, 10, 10);
    m_scrollContent->setLayout(m_flowLayout);

    m_scrollArea->setWidget(m_scrollContent);
    m_rightLayout->addWidget(m_scrollArea);

    // Add panels to main layout
    m_mainLayout->addWidget(m_leftPanel);
    m_mainLayout->addWidget(m_rightPanel);

    // Create "add new project" card
    m_addCard = new ProjectCard(m_scrollContent);
    m_addCard->setIsCreateCard(true);
    addProjectCard(m_addCard);

    // Connect signals
    connect(m_newProjectButton, &QPushButton::clicked, this, &ProjectGalleryView::newProjectClicked);
    connect(m_openProjectButton, &QPushButton::clicked, this, &ProjectGalleryView::openProjectClicked);
    connect(m_sortComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ProjectGalleryView::sortOrderChanged);
    connect(m_searchLineEdit, &QLineEdit::textChanged, this, &ProjectGalleryView::searchTextChanged);
}

ProjectGalleryView::~ProjectGalleryView()
{
    // No need to delete child widgets, Qt will handle that
}

QWidget *ProjectGalleryView::createLeftPanel()
{
    QWidget *panel = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(panel);
    layout->setContentsMargins(10, 10, 10, 10);
    layout->setSpacing(10);

    m_newProjectButton = new QPushButton("新建工程", panel);
    m_openProjectButton = new QPushButton("打开工程", panel);

    // Apply styles to buttons
    QString buttonStyle =
        "QPushButton {"
        "   background-color: #2196F3;"
        "   border-radius: 4px;"
        "   color: white;"
        "   padding: 5px 10px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #1976D2;"
        "}";

    m_newProjectButton->setStyleSheet(buttonStyle);
    m_openProjectButton->setStyleSheet(buttonStyle);

    layout->addWidget(m_newProjectButton);
    layout->addWidget(m_openProjectButton);
    layout->addStretch();

    return panel;
}

QWidget *ProjectGalleryView::createToolbar()
{
    QWidget *toolbar = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(toolbar);
    layout->setContentsMargins(0, 0, 0, 0);

    m_sortComboBox = new QComboBox(toolbar);
    m_sortComboBox->addItem("最近使用");
    m_sortComboBox->addItem("名称");
    m_sortComboBox->addItem("大小");

    QLabel *searchLabel = new QLabel("查找文件：", toolbar);
    m_searchLineEdit = new QLineEdit(toolbar);
    m_searchLineEdit->setPlaceholderText("输入关键字搜索");

    layout->addWidget(m_sortComboBox);
    layout->addStretch();
    layout->addWidget(searchLabel);
    layout->addWidget(m_searchLineEdit);

    return toolbar;
}

void ProjectGalleryView::addProjectCard(ProjectCard *card)
{
    if (card) {
        // If it's a regular project card, insert before the "add new" card
        if (!card->isCreateCard()) {
            int lastIndex = m_flowLayout->count() - 1;
            if (lastIndex >= 0) {
                m_flowLayout->insertWidget(lastIndex, card);
            } else {
                m_flowLayout->addWidget(card);
            }
        } else {
            m_flowLayout->addWidget(card);
        }
        m_scrollContent->updateGeometry();
    }
}

void ProjectGalleryView::onProjectAdded(const ProjectItem &project)
{
    // Create a new project card
    ProjectCard *card = new ProjectCard(project, m_scrollContent);

    // Connect card signals
    connect(card, &ProjectCard::cardClicked, this, [this, project]() {
        emit projectCardClicked(project);
    });

    connect(card, &ProjectCard::cardDelete, this, [this, project]() {
        emit projectCardDelete(project);
    });

    // Add to layout
    addProjectCard(card);
}

void ProjectGalleryView::onProjectRemoved(const ProjectItem &project)
{
    for (int i = 0; i < m_flowLayout->count(); ++i) {
        ProjectCard *card = qobject_cast<ProjectCard*>(m_flowLayout->itemAt(i)->widget());
        if (card && !card->isCreateCard() && card->projectName() == project.name() && card->projectPath() == project.path()) {
            // Remove from layout
            QLayoutItem *item = m_flowLayout->takeAt(i);
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;

            // Update layout
            m_flowLayout->invalidate();
            m_scrollContent->updateGeometry();
            m_scrollContent->layout()->activate();
            break;
        }
    }
}

void ProjectGalleryView::sortCards(const QList<ProjectItem> &sortedProjects)
{
    // Store mapping of cards and their positions
    QMap<QString, ProjectCard*> cardMap;
    ProjectCard *createCard = nullptr;

    // First step: Find all existing cards and save the "add new" card
    for (int i = 0; i < m_flowLayout->count(); ++i) {
        ProjectCard *card = qobject_cast<ProjectCard*>(m_flowLayout->itemAt(i)->widget());
        if (card) {
            if (card->isCreateCard()) {
                createCard = card;
            } else {
                cardMap[card->uniqueId()] = card;
            }
        }
    }

    // Second step: Clear the layout (but don't delete cards)
    while (m_flowLayout->count() > 0) {
        m_flowLayout->takeAt(0);
    }

    // Third step: Add cards in sorted order
    for (int i = 0; i < sortedProjects.size(); ++i) {
        QString uniqueId = sortedProjects[i].path();
        if (cardMap.contains(uniqueId)) {
            m_flowLayout->addWidget(cardMap[uniqueId]);
            cardMap.remove(uniqueId);
        } else {
            // Create a new card if one doesn't exist
            ProjectCard *newCard = new ProjectCard(sortedProjects[i], m_scrollContent);
            connect(newCard, &ProjectCard::cardClicked, this,
                    [this, i, sortedProjects]() {
                        emit projectCardClicked(sortedProjects[i]);
                    });
            connect(newCard, &ProjectCard::cardDelete, this,
                    [this, i, sortedProjects]() {
                        emit projectCardDelete(sortedProjects[i]);
                    });
            m_flowLayout->addWidget(newCard);
        }
    }

    // Fourth step: Add the "add new" card back
    if (createCard) {
        m_flowLayout->addWidget(createCard);
    }

    // Fifth step: Delete unused cards
    for (auto card : cardMap.values()) {
        card->deleteLater();
    }

    // Update layout
    m_scrollContent->updateGeometry();
}

void ProjectGalleryView::clear()
{
    QLayoutItem *item;
    while ((item = m_flowLayout->takeAt(0))) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    // Recreate the "add new" card after clearing
    if (!m_addCard) {
        m_addCard = new ProjectCard(m_scrollContent);
        m_addCard->setIsCreateCard(true);
        addProjectCard(m_addCard);
    } else {
        addProjectCard(m_addCard);
    }
}
