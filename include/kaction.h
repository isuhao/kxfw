#pragma once;

class KMenuPrivate;

class KXFW_API KAction : public QAction
{
	Q_OBJECT
public:
	explicit KAction(QObject *parent);
	~KAction();
protected:
	//ֻ�践�ص�ǰ��������Ĵ�С��
	virtual QSize contentSize() = 0;
	//tabWidth:Ϊ��ݼ����򳤶ȡ�
	//tabSpace:Ϊ��ݼ�������֮������򳤶ȡ�
	//textWidth:Ϊ���ֳ�������
	//iconWidth:Ϊͼ����ʾ���򳤶ȡ�
	virtual void paint(QPainter *p, const QRectF& drawRt, int iconWidth, int textWidth, int tabSpace, int tabWidth) = 0;
private:
	friend class KMenuPrivate;
};