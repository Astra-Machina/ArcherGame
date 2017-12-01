#ifndef ENEMYMOB_H
#define ENEMYMOB_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>


class EnemyMob : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QVector2D *velocity;
public:
    explicit EnemyMob(QObject *parent = 0);
    ~EnemyMob();

signals:

public slots:
    void UpdateState();
};

#endif // ENEMYMOB_H
