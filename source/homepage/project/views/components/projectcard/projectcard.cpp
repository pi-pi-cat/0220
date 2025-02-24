#include "projectcard.h"
#include "ui_projectcard.h"

ProjectCard::ProjectCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectCard)
{
    ui->setupUi(this);
}

ProjectCard::~ProjectCard()
{
    delete ui;
}
