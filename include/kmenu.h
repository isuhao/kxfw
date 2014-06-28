#pragma once;

class KAction;
class KMenuPrivate;
class KWidget;

struct MenuStyleData 
{
	QPixmap frame;//�˵��߿��ͼƬ������ִ���Ĺ������졣
	QPixmap mask;//����ͼ�����Ʊ���ɫ����䣬ȷ�����������߿����򣬽���ִ���Ĺ������죬ȷ�������������
	QMargins maskMargin;//�˵��߿�Ŀհ�����
	int menuHMargin; //�˵����ݿհ�����
	int menuVMargin;
	int leftFrameThinkness; //Hover�Ļ��Ƶ���΢����
	int rightFrameThinkness;//Hover�Ļ��Ƶ���΢��
	QColor background;//�˵�����ɫ��
	QPixmap check;//�˵�Check����ͼ��
	QPixmap checkDisable;//�˵�ѡ��Ϊ�����õ�״̬��
	int iconMinimumSize; //�˵�ͼ��Ĵ�С��
	int itemMinimumHeight; //�˵����Ĭ�ϸ߶ȣ�����Ϊ0ʱ����ʾʹ��ϵͳĬ�ϵĸ߶ȡ�
	int menuMinimumWidth;// �˵�����С���ȡ�
	int overlapSize; //���Ӳ˵��ص���С��
	QPixmap hovered; //Hover״̬�µ�ͼƬ
	QPixmap seperator; //�ָ���ͼƬ
	QPixmap arrow; //�Ӳ˵��ļ�ͷ��
	QColor textColor; //���������������ɫ
	QColor textColorDisable; //���������������ɫ��

	MenuStyleData()
	{
		iconMinimumSize = 0;
		overlapSize = 10;
		itemMinimumHeight = 0;
		menuHMargin = 3;
		menuVMargin = 5;
		leftFrameThinkness = 2;
		rightFrameThinkness = 2;
		menuMinimumWidth = 100;
	}
};

class KXFW_API KMenu : public QMenu
{
	Q_OBJECT
public:
	enum Direction
	{
		NotDefine,
		TopLeft,
		TopCenter,
		TopRight,
		BottomLeft,
		BottomCenter,
		BottomRight,
		LeftTop,
		LeftCenter,
		LeftBottom,
		RightTop,
		RightCenter,
		RightBottom
	};
public:
	explicit KMenu(QWidget *parent = NULL);
	~KMenu();

	static bool addMenuStyle(int key, MenuStyleData& style);
	static KMenu *createPopupMenu(int stylekey = 0);

	void setTextAlignCenter(bool on);
	void setBackgroundColor(const QColor &clr);
	void setTextColor(const QColor& clr);
	void setTextDisableColor(const QColor& clr);

	QAction* exec();
	QAction* exec(KWidget *target, Direction direction, const QPoint& offset=QPoint(0,0));


signals:
	void aboutToAdjust(QWidget *w, bool *pbHandled);

private slots:
	void on_aboutToShow();

protected:
	virtual void showEvent(QShowEvent *event);
	virtual void resetGeometry();

private:
	KMenuPrivate *d;

	friend class KMenuStyleHandler;
};