#ifndef LOCATIONMODEL_H
#define LOCATIONMODEL_H

#include <QAbstractListModel>
#include "datasource.h"

class LocationModel : public QAbstractListModel
{
    Q_OBJECT
    QML_NAMED_ELEMENT(LocationModel)
    QML_SINGLETON
    Q_PROPERTY(DataSource* dataSource READ getDataSource WRITE setDataSource CONSTANT FINAL)
public:
    explicit LocationModel(QObject *parent = nullptr);

    enum class LocationModelRoles
    {
        LocationNameRole = Qt::UserRole,
        LocationCountryNameRole = Qt::UserRole+1
    };
    Q_ENUM(LocationModelRoles);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int , QByteArray> roleNames() const override;

    DataSource *getDataSource() const;
    void setDataSource(DataSource *newDataSource);

private:
    DataSource *m_dataSource = nullptr;
    bool m_isConnectedToSignals{false};
};

#endif // LOCATIONMODEL_H
