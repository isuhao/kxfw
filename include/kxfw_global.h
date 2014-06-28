#pragma once;


/*C Libarary*/

#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

// Windows ͷ�ļ�:
#include <windows.h>
#include <windowsx.h>
#include <shlobj.h>

/* Qt library */
#include <QtCore>
#include <QtGui>
#include <QtGlobal>
#include <QObject>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QMargins>
#include <QPointer>
#include <QColor>
#include <QIcon>
#include <QLatin1String>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QPair>
#include <QVariant>
#include <QPixmap>
#include <QEvent>
#include <QGraphicsWidget>
#include <QGraphicsView>
#include <QFontMetrics>
#include <QFontMetricsF>
#include <QGraphicsLinearLayout>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include <QTextFormat>
#include <QTextOption>
#include <QTextCursor>
#include <QFontDatabase>
#include <QFrame>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDebug>


#pragma comment(lib, "shell32.lib")

#define KX_SAFE_DELETE(p) {if (p != NULL) delete (p); p = NULL; }

#define KX_SAFE_GDIOBJ_DELETEOBJECT(obj) { if(obj) { ::DeleteObject(obj) ;obj =NULL;} }

#define KX_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#pragma warning(error: 4715)

#ifdef KXFW_LIB
# define KXFW_API Q_DECL_EXPORT
#else
# define KXFW_API Q_DECL_IMPORT
#endif


/* ��ȫ��ֻ���˷���SDK��ͷ�ļ��������KXXX��ͷ�ļ������ܻ��������	*/
/* ���⣬��Ҫ������														*/


/* private */
#include "kdatadef.h"

/*
��һЩ�������£�����IE��Flash��script�ص���ֱ�ӵ���deleteLater�������Ǹûص�����ͨ��Qtֱ�ӵ��õģ�
�ʵ�����deleteLater��������loopLevel��Ϊ1���Ӷ����¶����޷���ȷ���ͷţ�����ʹ�����¶��з�ʽ�����
*/
inline void qDeleteLater(QObject *obj)
{
	QMetaObject::invokeMethod(obj, "deleteLater", Qt::QueuedConnection);
}
