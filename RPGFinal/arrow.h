#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <QTimer>
#include "enemymob.h"
#include "enemyboss.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>

class Arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QVector2D *velocity;
public:
    explicit Arrow(QObject *parent = 0);
    void setVelocity(float newX, float newY);
    ~Arrow();

signals:

public slots:
    void UpdateState();
};

#endif // ARROW_H
