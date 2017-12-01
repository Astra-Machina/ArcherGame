#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <QTimer>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>

#include "enemymob.h"
#include "enemyboss.h"
#include "arrow.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QVector2D *velocity;
public:
    explicit Player(QObject *parent = 0);
    ~Player();
    void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:
      void UpdateState();
};

#endif // PLAYER_H
