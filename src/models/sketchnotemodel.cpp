#include "sketchnotemodel.h"

namespace Models {

SketchNoteModel::SketchNoteModel(DAO::DatabaseDAO* databaseDAO, QObject *parent)
    : QObject(parent)
    , m_databaseDAO(databaseDAO)
{

}

}
