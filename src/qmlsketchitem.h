#ifndef QMLSKETCHITEM_H
#define QMLSKETCHITEM_H

#include <QElapsedTimer>
#include <QList>
#include <QPointF>
#include <QQuickPaintedItem>
#include <QVector>

namespace QmlItems {

class QmlSketchItem: public QQuickPaintedItem
{
    Q_OBJECT

public:
    QmlSketchItem(QQuickItem *parent = nullptr);

    virtual void paint(QPainter *painter);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

protected:
    QList<QVector<QPointF>> m_points;
    QElapsedTimer m_delta;

};

}

#endif // QMLSKETCHITEM_H
