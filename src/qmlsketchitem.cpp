#include <QPainter>
#include <QPen>

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
    painter->setPen(QPen(Qt::black, 3));
    //painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    //painter->setRenderHint(QPainter::HighQualityAntialiasing, true);

    for (auto& points : m_points) {
        painter->drawLines(points);
    }
}

void QmlSketchItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";

    m_points.append(QVector<QPointF>{});

    m_delta.start();
    event->accept();
}

void QmlSketchItem::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_delta.hasExpired(10))
        return;

    auto const point = event->localPos();
    if (!m_points.back().empty())
        m_points.back().append(point);
    m_points.back().append(point);

    update();

    m_delta.start();
    event->accept();
}

void QmlSketchItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";

    update();

    emit grabChanged();
    event->accept();
}

bool QmlSketchItem::empty() const
{
    return !m_points.empty();
}

QSharedPointer<QQuickItemGrabResult> QmlSketchItem::grab()
{
    return grabToImage();
}

}
