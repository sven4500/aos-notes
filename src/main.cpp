#include <QQmlEngine>
#include <QtQuick>

#if defined(auroraos)
#include <auroraapp.h>
namespace platformNamespace = Aurora::Application;
#elif defined(sailfishos)
#include <sailfishapp.h>
namespace platformNamespace = SailfishApp;
#endif

#include "audiorecorder.h"
#include "dao/databasedao.h"
#include "dto/databaseentry.h"
#include "models/audionotemodel.h"
#include "models/sketchnotemodel.h"
#include "models/textnotemodel.h"
#include "qmlitems/sketchitem.h"
#include "viewmodels/audionoteviewmodel.h"
#include "viewmodels/listviewmodel.h"
#include "viewmodels/sketchnoteviewmodel.h"
#include "viewmodels/textnoteviewmodel.h"

int main(int argc, char** argv)
{
    QScopedPointer<QGuiApplication> application(platformNamespace::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.ivars.rozhleys"));
    application->setApplicationName(QStringLiteral("notes"));

    qmlRegisterType<Managers::AudioRecorder>("Managers", 1, 0, "AudioRecorder");
    qmlRegisterType<QmlItems::SketchQmlItem>("QmlItems", 1, 0, "Sketch");
    qmlRegisterUncreatableType<DTO::DatabaseEntry>("DTO", 1, 0, "DatabaseEntry", "DTOs can not be created on QML side");
    qmlRegisterUncreatableType<Models::AudioNoteModel>("Models", 1, 0, "AudioNoteModel", "models can not be created on QML side");

    auto const databaseDAO = new DAO::DatabaseDAO(&*application);

    auto const textNoteModel = new Models::TextNoteModel(databaseDAO, &*application);
    auto const audioNoteModel = new Models::AudioNoteModel(databaseDAO, &*application);
    auto const sketchNoteModel = new Models::SketchNoteModel(databaseDAO, &*application);

    auto const audioNoteViewModel = new ViewModels::AudioNoteViewModel(audioNoteModel, &*application);
    auto const listViewModel = new ViewModels::ListViewModel(databaseDAO, &*application);
    auto const sketchNoteViewModel = new ViewModels::SketchNoteViewModel(sketchNoteModel, &*application);
    auto const textNoteViewModel = new ViewModels::TextNoteViewModel(textNoteModel, &*application);

    QScopedPointer<QQuickView> view(platformNamespace::createView());
    view->rootContext()->setContextProperty("_audioNoteViewModel", audioNoteViewModel);
    view->rootContext()->setContextProperty("_listViewModel", listViewModel);
    view->rootContext()->setContextProperty("_sketchNoteViewModel", sketchNoteViewModel);
    view->rootContext()->setContextProperty("_textNoteViewModel", textNoteViewModel);
    view->setSource(platformNamespace::pathTo(QStringLiteral("qml/notes.qml")));
    view->show();

    return application->exec();
}
