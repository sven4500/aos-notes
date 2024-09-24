#include <QPainter>
#include <QPen>

#include "qmlitems/sketchitem.h"

namespace QmlItems {

SketchQmlItem::SketchQmlItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void SketchQmlItem::paint(QPainter *painter)
{
    if (!m_image.isNull())
        painter->drawImage(0, 0, m_image);

    painter->setPen(QPen(Qt::black, 3));
    //painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    //painter->setRenderHint(QPainter::HighQualityAntialiasing, true);

    for (auto& points : m_points) {
        painter->drawLines(points);
    }
}

void SketchQmlItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";

    m_points.append(QVector<QPointF>{});

    m_delta.start();
    event->accept();
}

void SketchQmlItem::mouseMoveEvent(QMouseEvent *event)
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

void SketchQmlItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";

    update();

    emit grabChanged();
    emit emptyChanged();
    event->accept();
}

bool SketchQmlItem::empty() const
{
    return m_points.empty() && m_image.isNull();
}

QSharedPointer<QQuickItemGrabResult> SketchQmlItem::grab()
{
    return grabToImage();
}

void SketchQmlItem::setImage(const QImage &newImage)
{
    qDebug() << newImage;
    m_image = newImage;
}

}
