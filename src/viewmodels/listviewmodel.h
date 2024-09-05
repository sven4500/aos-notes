#ifndef LIST_VIEW_MODEL_H_
#define LIST_VIEW_MODEL_H_

#include <QAbstractListModel>
#include <QObject>

class ListViewModel: public QAbstractListModel
{
    Q_OBJECT

signals:
    void rowCountChanged();

public:
    enum RoleNames {
        DateTimeRole = Qt::UserRole + 0,
        // NOTE: remove HeightRole later
        HeightRole = Qt::UserRole + 1,
        NoteType = Qt::UserRole + 2
    };

    // INFO: https://stackoverflow.com/questions/51728264/model-rowcount-wont-bind-to-items-property
    Q_PROPERTY(int length READ rowCount NOTIFY rowCountChanged)

    explicit ListViewModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

};

#endif
