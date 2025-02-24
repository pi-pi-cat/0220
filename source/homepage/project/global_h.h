#ifndef GLOBAL_H_H
#define GLOBAL_H_H

#include <QtCore/qglobal.h>

#if defined(PROJECT_LIBRARY)
#  define PROJECT_EXPORT Q_DECL_EXPORT
#else
#  define PROJECT_EXPORT Q_DECL_IMPORT
#endif

#endif // GLOBAL_H_H
