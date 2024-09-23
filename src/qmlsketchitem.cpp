#include <QPainter>

#include "qmlsketchitem.h"

namespace QmlItems {

QmlSketchItem::QmlSketchItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void QmlSketchItem::paint(QPainter *painter)
{
    painter->setPen(Qt::red);
    painter->drawRect(0, 0, width() - 1, height() - 1);
}

void QmlSketchItem::mousePressEvent(QMouseEvent *event)
{
    qDebug();

    _delta.start();
    event->accept();
}

void QmlSketchItem::mouseMoveEvent(QMouseEvent *event)
{
    if (!_delta.hasExpired(1000))
        return;

    auto const pos = event->localPos();
    qDebug() << pos.x() << pos.y();

    _delta.start();
    event->accept();
}

}
