#pragma once;

#include "kwidget.h"

class KFrameItemPrivate;

class KXFW_API KFrameItem : public KWidget
{
	Q_OBJECT
	Q_DISABLE_COPY(KFrameItem)
	Q_DECLARE_PRIVATE(KFrameItem)

	Q_ENUMS(FrameType)
	Q_ENUMS(FrameState)
	Q_ENUMS(DefaultFrame)

	Q_PROPERTY(DefaultFrame defaultFrame READ defaultFrame WRITE setDefaultFrame)
	Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath)
	Q_PROPERTY(FrameType frameType READ frameType WRITE setFrameType)
	Q_PROPERTY(QString frameColor READ frameColor WRITE setFrameColor)
	Q_PROPERTY(int framePixel READ framePixel WRITE setFramePixel)
	Q_PROPERTY(FrameState frameState READ frameState WRITE setFrameState)
	Q_PROPERTY(bool acceptClick READ acceptClick WRITE setAcceptClick)
	Q_PROPERTY(bool frameSwitch READ frameSwitch WRITE setFrameSwitch)
	Q_PROPERTY(bool acceptHover READ acceptHover WRITE setAcceptHover)
	Q_PROPERTY(int index READ frameIndex WRITE setFrameIndex)
	Q_PROPERTY(bool smooth READ smooth WRITE setSmooth)
	Q_PROPERTY(int count READ frameCount)
public:
	enum FrameType
	{
		OneTopLeft = 0,			/*���Ͻ�*/
		OneTopRight,		/*���Ͻ�*/
		OneBotLeft,			/*���½�*/
		OneBotRight,		/*���½�*/
		OneHCenter,			/*ˮƽ�м�*/
		OneVCenter,			/*�����м�*/
		OneHVCenter,		/*������*/
		TileH,			/*ˮƽƽ��һ��*/
		TileV,		/*��ֱƽ��һ��*/
		TileHV,		/*ˮƽƽ�̶��У�ֱ������*/
		StretchH,	/*ˮƽ���죬����߶ȳ���ͼƬ�߶ȣ���հס�*/
		StretchV,	/*��ֱ���죬�����ȳ���ͼƬ��ȣ���հס�*/
		StretchVTwoSize,
		StretchVMiddle,
		StretchHV,	/*ˮƽ��ֱ�����죬��ȫ�����ؼ���*/
		StretchHTwoSize,	/*ˮƽ����ͼƬ���ߵı����ҽ���һ����ͼ���м䲻���졣*/
		StretchHMiddle, /*ˮƽ����ͼƬ���м�һ�����أ����˲����졣*/
		GridFour,	/*4����*/	
		GridFrameFour, /*����4����*/
		GridNine,
		BitmapEnd,
		Rectangle,		/*ֱ����ɫ*/
		RoundRect,		/*Բ����ɫ*/
		RoundRect4Pixel,  /*Բ����ɫ*/
		RoundRect5Pixel,  /*Բ����ɫ*/
		RoundRect6Pixel,  /*Բ����ɫ*/
		RoundRect7Pixel,  /*Բ����ɫ*/
		ColorFrameEnd
	};

	enum DefaultFrame
	{
		BadDefalut,
		RoundWhite,
		RoundTranparent,
		RoundFlatTranslucent,
		RoundRaiseTranslucent,
		RoundSunkenTranslucent,
		RectWhite
	};

	enum FrameState
	{
		Normal = 0,
		Hover = 1,
		Down = 2,
		Selected = Down,
		Disable = 3,
		CheckNormal = 4,
		CheckHover = 5,
		CheckDown = 6,
		CheckSelected = CheckDown,
		CheckDisable = 7,
		StateMax
	};

public:
	explicit KFrameItem(QGraphicsItem *parent = NULL);
	explicit KFrameItem(const QString& path, KFrameItem::FrameType type, QGraphicsItem *parent = NULL);
	~KFrameItem();
	
	KFrameItem::FrameType frameType() const;
	void setFrameType(KFrameItem::FrameType type);

	QString frameColor() const;
	void setFrameColor(const QString& clr);

	DefaultFrame defaultFrame() const;
	void setDefaultFrame(DefaultFrame type);

	int framePixel();
	void setFramePixel(int iPixel);

	bool frameSwitch();
	void setFrameSwitch(bool bSwitch);

	QString imagePath() const;
	void setImagePath(const QString& path);

	QPixmap currentPixmap();
	void appendPixmap(const QPixmap& img);

	void setFixSizeByPixmapSize();
	void setFixWidthByPixmapWidth();
	void setFixHeightByPixmapHeight();
	
	int frameCount();
	QSizeF pixmapSize();

	void setFrameIndex(int idx);
	int frameIndex() const;

	bool smooth() const;
	void setSmooth(bool on);

	bool acceptClick();
	void setAcceptClick(bool bClick);

	bool acceptHover();
	void setAcceptHover(bool bHover);

	/*������4̬*/
	void setNormal();
	void setHover();
	void setDown();
	void setSelected();
	void setDisable();
	bool hasChecked();
	void setChecked(bool bCheck);

	void setEnabled(bool enabled);

	FrameState frameState() const;
	void setFrameState(FrameState state);

signals:
	void enter();
	void leave();
	void pressed();
	void released();
	void clicked();
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
	void doThemeChange();
private:
	void drawOneTopLeft(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneTopRight(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneBotLeft(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneBotRight(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneHCenter(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneVCenter(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawOneHVCenter(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawTileH(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawTileV(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawTileHV(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchH(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchV(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchHV(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchHTwo(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchHMiddle(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchVTwo(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawStretchVMiddle(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawGridFour(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawGridFrameFour(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawGridNine(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawRectangle(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	void drawRoundRect(QPainter *painter, const int iRadio, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
	void init();
	int normalIndex(int idx);
	void updateTheme();
};