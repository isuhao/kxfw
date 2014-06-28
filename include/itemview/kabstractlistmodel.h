#pragma once;

class KXFW_API KAbstractListModel : public QObject
{
	Q_OBJECT
public:
	enum ItemUserRole
	{
		UserRoleOther = Qt::UserRole + 1,
	};
public:
	KAbstractListModel(QObject *parent = 0);
	virtual ~KAbstractListModel();

public:
	//���º������б����ģ�͡�

	inline bool isEmpty()
	{
		return count() == 0;
	}
	/*��ǰģ���е�������Ŀ*/
	virtual int count() const = 0;
	/*��ȡĳ��������Ϣ*/
	virtual QMap<Qt::ItemDataRole, QVariant> data(int index) const = 0;
	/*�޸�ĳ�������ڴ�*/
	virtual bool setData(int index, const QMap<Qt::ItemDataRole, QVariant> &val);
	virtual bool setAction(int id, const QVariant& val, QVariant& result);
signals:
	//���½ӿ���ģ��֪ͨ�б�
	void itemsInserted(int index, int n);
	void itemsRemoved(int index, int n);
	void itemsMoved(int from, int to, int n);
	void itemsChanged(int index, int n, const QList<Qt::ItemDataRole> &roles);
	void modelReset();
};