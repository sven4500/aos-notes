#include <QQmlEngine>
#include <QtQuick>

#include <auroraapp.h>

#include "dao/databasedao.h"
#include "dto/databaseentry.h"
#include "models/textnotemodel.h"
#include "viewmodels/listviewmodel.h"
#include "viewmodels/textnoteviewmodel.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.ivars.rozhleys"));
    application->setApplicationName(QStringLiteral("notes"));

    qmlRegisterUncreatableType<DTO::DatabaseEntry>("DTO", 1, 0, "DatabaseEntry", "DTO can not be created on QML side");

    auto const databaseDAO = new DAO::DatabaseDAO(&*application);

    auto const textNoteModel = new Models::TextNoteModel(databaseDAO, &*application);
    // TODO: sketchNoteModel
    // TODO: audioNoteModel

    auto const listViewModel = new ViewModels::ListViewModel(databaseDAO, &*application);
    auto const textNoteViewModel = new ViewModels::TextNoteViewModel(textNoteModel, &*application);
    // TODO: sketchNoteViewModel
    // TODO: audioNoteViewModel

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->rootContext()->setContextProperty("_listViewModel", listViewModel);
    view->rootContext()->setContextProperty("_textNoteViewModel", textNoteViewModel);
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/notes.qml")));
    view->show();

    return application->exec();
}
