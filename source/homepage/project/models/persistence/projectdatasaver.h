#ifndef PROJECTDATASAVER_H
#define PROJECTDATASAVER_H

#include <QObject>

class ProjectDataSaver : public QObject
{
    Q_OBJECT
public:
    explicit ProjectDataSaver(QObject *parent = nullptr);

signals:

};

#endif // PROJECTDATASAVER_H
