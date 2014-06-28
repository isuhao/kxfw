#pragma once;

#include "kwidget.h"

/*
�ο���C:\Qt\4.7.1\examples\widgets\calendarwidget��ֱ�ӰѸ�������proxy�������ɡ�
*/


class KCalendarPrivate;

class KXFW_API KCalendar : public KWidget
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(KCalendar)

public:
	explicit KCalendar(QGraphicsItem *parent=NULL);
	~KCalendar();
protected:
	virtual void resizeEvent(QGraphicsSceneResizeEvent * event);
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
	void updateLayout();
};