#pragma once;

#include "kwidget_p.h"

class KAbstractListModel;
class KScrollBar;

class KXFW_API KListWidgetPrivate : public KWidgetPrivate
{
	Q_DECLARE_PUBLIC(KListWidget)
public:
	QBasicTimer m_layoutTimer;
	QBasicTimer m_areaResizeTimer;//���ؼ���С��Items���������ӻ����ʱ���á�
	int m_indexSelect;//���б�ѡ�еġ�
	int m_heightUnselect;
	int m_heightSelect;
	QVariant m_variantUnselect;
	QVariant m_variantSelected;
	QVariant m_variantHovered;
	QMargins m_itemMargins;
	KListItemCreator *m_creator;
	int m_indexWidgetItemBegin;//��ʾm_widgetItems�ɼ��б��еĵ�һ�
	QHash<int,QPointer<KListItem>> m_widgetItems;
	QRectF m_contentArea;//�б���ʾ������
	QRectF m_vscrollArea;//��������ʾ������

	int m_valueCurrentScroll;//��ǰ�б������λ�á�
	int m_heightContentTopHidden;
	int m_heightContentBottomHidden;
	QPointer<KScrollBar> m_scrollbar;

	QVariant m_cfgCustom;

	QPointer<KAbstractListModel> m_model;
public:
	KListWidgetPrivate();
	~KListWidgetPrivate();
	void init();
	void itemsInserted(int index, int n);
	void itemsRemoved(int index, int n);
	void itemsMoved(int from, int to, int n);
	void itemsChanged(int index, int n, const QList<Qt::ItemDataRole> &roles);
	void modelReset();
	void updateLayout();
	void updateArea();
	qreal itemsHeight();
	qreal maxScrollValue();
	void resetAreas();
	void doLayout();
	void calcLayoutFirstItem(int &itemIdxFirst, qreal &itemPosVisibleFirst, int iFrom, int iTo);
	void doMousePress(QGraphicsSceneMouseEvent *event);
	void doMouseRelease(QGraphicsSceneMouseEvent *event);
	void doMouseDbClick(QGraphicsSceneMouseEvent *event);
	void doMouseWheel(QGraphicsSceneWheelEvent *event);
	int findOneIndexByText( const QString& txt );
	QList<int> findAllIndexByText( const QString& txt );
	KAbstractListModel* setModel(KAbstractListModel *model);
	bool tryToSetAction(int index, int id, const QVariant& val, QVariant& result);
};