#include <QQmlEngine>
#include <QtQuick>

#include <auroraapp.h>

#include "audiorecorder.h"
#include "dao/databasedao.h"
#include "dto/databaseentry.h"
#include "models/audionotemodel.h"
#include "models/textnotemodel.h"
#include "viewmodels/audionoteviewmodel.h"
#include "viewmodels/listviewmodel.h"
#include "viewmodels/textnoteviewmodel.h"

int main(int argc, char** argv)
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.ivars.rozhleys"));
    application->setApplicationName(QStringLiteral("notes"));

    qmlRegisterType<Managers::AudioRecorder>("Managers", 1, 0, "AudioRecorder");
    qmlRegisterUncreatableType<DTO::DatabaseEntry>("DTO", 1, 0, "DatabaseEntry", "DTOs can not be created on QML side");
    qmlRegisterUncreatableType<Models::AudioNoteModel>("Models", 1, 0, "AudioNoteModel", "models can not be created on QML side");

    auto const databaseDAO = new DAO::DatabaseDAO(&*application);

    auto const textNoteModel = new Models::TextNoteModel(databaseDAO, &*application);
    auto const audioNoteModel = new Models::AudioNoteModel(databaseDAO, &*application);
    // TODO: sketchNoteModel

    auto const listViewModel = new ViewModels::ListViewModel(databaseDAO, &*application);
    auto const textNoteViewModel = new ViewModels::TextNoteViewModel(textNoteModel, &*application);
    auto const audioNoteViewModel = new ViewModels::AudioNoteViewModel(audioNoteModel, &*application);
    // TODO: sketchNoteViewModel

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->rootContext()->setContextProperty("_listViewModel", listViewModel);
    view->rootContext()->setContextProperty("_audioNoteViewModel", audioNoteViewModel);
    view->rootContext()->setContextProperty("_textNoteViewModel", textNoteViewModel);
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/notes.qml")));
    view->show();

    return application->exec();
}
