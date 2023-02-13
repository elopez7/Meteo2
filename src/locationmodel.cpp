#include "locationmodel.h"
#include "enumconverters.h"
#include "locationdto.h"

LocationModel::LocationModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int LocationModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_dataSource->getLocationsList().count();
}

QVariant LocationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    LocationDTO* retrievedLocation{m_dataSource->getLocationsList().at(index.row())};

    switch (role) {
    case +LocationModelRoles::LocationNameRole:
        return retrievedLocation->m_locationName;
        break;
    case +LocationModelRoles::LocationCountryNameRole:
        return retrievedLocation->m_countryName;

    default:
        break;
    }
    return QVariant();
}

Qt::ItemFlags LocationModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> LocationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[+LocationModelRoles::LocationNameRole] = "name";
    roles[+LocationModelRoles::LocationCountryNameRole] = "country";
    return roles;
}

DataSource *LocationModel::getDataSource() const
{
    return m_dataSource;
}

void LocationModel::setDataSource(DataSource *newDataSource)
{
    beginResetModel();
    if(m_dataSource && m_isConnectedToSignals)
    {
        m_dataSource->disconnect(this);
    }
    m_dataSource = newDataSource;

    connect(m_dataSource, &DataSource::preResetModel, this, [=](){
        beginResetModel();
    });
    connect(m_dataSource, &DataSource::postResetModel, this, [=](){
        endResetModel();
    });

    connect(m_dataSource, &DataSource::preAddLocationToModel, this, [=](){
        const int index = m_dataSource->getLocationsList().count();
        beginInsertRows(QModelIndex(), index, index);
    });

    connect(m_dataSource, &DataSource::postAddLocationToModel, this, [=](){
        endInsertRows();
    });
    endResetModel();
}
