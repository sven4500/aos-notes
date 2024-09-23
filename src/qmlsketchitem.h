#ifndef QMLSKETCHITEM_H
#define QMLSKETCHITEM_H

#include <QElapsedTimer>
#include <QQuickPaintedItem>

namespace QmlItems {

class QmlSketchItem: public QQuickPaintedItem
{
    Q_OBJECT

public:
    QmlSketchItem(QQuickItem *parent = nullptr);

    virtual void paint(QPainter *painter);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

protected:
    QElapsedTimer _delta;

};

}

#endif // QMLSKETCHITEM_H
