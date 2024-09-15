#ifndef LIST_VIEW_MODEL_H_
#define LIST_VIEW_MODEL_H_

#include <QAbstractListModel>
#include <QList>
#include <QObject>

#include <dto/databaseentry.h>

namespace DAO {
class DatabaseDAO;
}

namespace ViewModels {

class ListViewModel: public QAbstractListModel
{
    Q_OBJECT

signals:
    void rowCountChanged();

public:
    enum RoleNames {
        IdRole = Qt::UserRole + 0,
        NoteTypeRole  = Qt::UserRole + 1,
        TitleRole = Qt::UserRole + 2,
        MediaRole = Qt::UserRole + 3,
        CreatedAtRole = Qt::UserRole + 4,
        ModifiedAtRole = Qt::UserRole + 5
    };

    // INFO: https://stackoverflow.com/questions/51728264/model-rowcount-wont-bind-to-items-property
    Q_PROPERTY(int length READ rowCount NOTIFY rowCountChanged)

    explicit ListViewModel(DAO::DatabaseDAO* databaseDAO, QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private slots:
    void onNoteInserted(qint64 id);
    void onNoteRemoved(qint64 id);
    void onNoteUpdated(qint64 id);

private:
    QList<DTO::DatabaseEntry> m_notes;
    DAO::DatabaseDAO* m_databaseDAO = nullptr;

};

}

#endif
