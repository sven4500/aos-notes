#ifndef QMLSKETCHITEM_H
#define QMLSKETCHITEM_H

#include <QElapsedTimer>
#include <QList>
#include <QPointF>
#include <QQuickItemGrabResult>
#include <QQuickPaintedItem>
#include <QSharedPointer>
#include <QVector>

namespace QmlItems {

class QmlSketchItem: public QQuickPaintedItem
{
    Q_OBJECT

signals:
    void grabChanged();
    void emptyChanged();

public:
    Q_PROPERTY(QSharedPointer<QQuickItemGrabResult> grab READ grab NOTIFY grabChanged)
    Q_PROPERTY(QImage image WRITE setImage)
    Q_PROPERTY(bool empty READ empty NOTIFY emptyChanged)

    QmlSketchItem(QQuickItem *parent = nullptr);

    virtual void paint(QPainter *painter);

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    bool empty() const;

    QSharedPointer<QQuickItemGrabResult> grab();

    void setImage(const QImage &newImage);

protected:
    QList<QVector<QPointF>> m_points;
    QImage m_image;
    QElapsedTimer m_delta;

};

}

#endif // QMLSKETCHITEM_H
