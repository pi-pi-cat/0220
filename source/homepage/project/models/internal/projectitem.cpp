#include "projectitem.h"

ProjectItem::ProjectItem()
{

}

ProjectItem::ProjectItem(const QString &name, const QString &path)
{
    m_name = name;
    m_path = path;
}

QString ProjectItem::name() const
{
    return m_name;
}

void ProjectItem::setName(const QString &name)
{
    m_name = name;
}

QString ProjectItem::path() const
{
    return m_path;
}

void ProjectItem::path(const QString &path)
{
    m_path = path;
}
