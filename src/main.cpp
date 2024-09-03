#include <QQmlEngine>
#include <QtQuick>

#include <auroraapp.h>

#include "headerviewmodel.h"
#include "listviewmodel.h"
#include "textnoteviewmodel.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.ivars.rozhleys"));
    application->setApplicationName(QStringLiteral("notes"));

    auto const headerViewModel = new HeaderViewModel(/*&*application*/);
    auto const listViewModel = new ListViewModel(/*&*application*/);
    auto const textNoteViewModel = new ViewModels::TextNoteViewModel();

    qmlRegisterUncreatableType<HeaderViewModel>("ViewModels", 1, 0, "HeaderViewModel", "");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->rootContext()->setContextProperty("_headerViewModel", headerViewModel);
    view->rootContext()->setContextProperty("_listViewModel", listViewModel);
    view->rootContext()->setContextProperty("_textNoteViewModel", textNoteViewModel);
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/notes.qml")));
    view->show();

    return application->exec();
}
