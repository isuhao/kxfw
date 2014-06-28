#pragma once;

#include "kwidget_p.h"

class KAbstractTreeModel;
class KTreeItem;
class KScrollBar;
class KListItemCreator;

class KXFW_API KTreeWidgetPrivate : public KWidgetPrivate
{
	Q_DECLARE_PUBLIC(KTreeWidget)
public:
	QBasicTimer m_layoutTimer;
	QBasicTimer m_areaResizeTimer;//���ؼ���С��Items���������ӻ����ʱ���á�
	QBasicTimer m_makeListTimer;//����ģ���н����б�
	qint64 m_nodeIdSelect;//���б�ѡ�еġ�
	int m_heightItem;
	QVariant m_variantUnselect;
	QVariant m_variantSelected;
	QVariant m_variantHovered;
	QMargins m_itemMargins;
	KTreeItemCreator *m_creator;
	int m_indexWidgetItemBegin;//��ʾm_widgetItems�ɼ��б��еĵ�һ�
	QHash<qint64,QPointer<KTreeItem>> m_widgetItems;
	QRectF m_contentArea;//�б���ʾ������
	QRectF m_vscrollArea;//��������ʾ������

	int m_valueCurrentScroll;//��ǰ�б������λ�á�
	int m_heightContentTopHidden;
	int m_heightContentBottomHidden;
	QPointer<KScrollBar> m_scrollbar;
	int m_thinknessScrollbar;

	QVariant m_cfgCustom;

	QPointer<KAbstractTreeModel> m_model;

	QSet<qint64> m_itemsExpanded;//չ����״̬��
	QList<qint64> m_itemsTree;//����ת�����б��Ӷ��γɵ��б�s
	int m_styleTree;//���ķ��
	int m_depthIndentation;//ÿһ���������
	QColor m_colorBranch; // ���ߵ���ɫ

	bool m_bDbClickedAsCollapsedOrExpanded;
public:
	KTreeWidgetPrivate();
	~KTreeWidgetPrivate();
	void init( );
	KAbstractTreeModel* setModel(KAbstractTreeModel *model);
	void itemsInserted(const QList<qint64>& ids);
	void itemsRemoved(const QList<qint64>& ids);
	void itemsChanged(const QList<qint64>& ids, const QList<Qt::ItemDataRole> &roles);
	void modelReset();

	bool isNodeVisible(qint64 nodeid);


	void updateLayout();
	void updateArea();
	void updateList();

	void makeList();
	void resetAreas();
	void doLayout();

	void doItemExpanded(qint64 nodeid);
	void doItemCollapsed(qint64 nodeid);

	void doMousePress(QGraphicsSceneMouseEvent *event);
	void doMouseRelease(QGraphicsSceneMouseEvent *event);
	void doMouseWheel(QGraphicsSceneWheelEvent *event);
	void doMouseDbClick(QGraphicsSceneMouseEvent *event);
	
	qreal itemsHeight();
	qreal maxScrollValue();

	void calcLayoutFirstItem(int &itemIdxFirst, qreal &itemPosVisibleFirst, int iFrom, int iTo);

	/*����������ڽ���ʱ���Ż���Ч��������Ч��*/
	bool tryToSetAction(qint64 nodeid, int id, const QVariant& val, QVariant& result);
};

