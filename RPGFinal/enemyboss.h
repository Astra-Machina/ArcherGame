#ifndef ENEMYBOSS_H
#define ENEMYBOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>

class EnemyBoss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QVector2D *velocity;
public:
    explicit EnemyBoss(QObject *parent = 0);
    ~EnemyBoss();

signals:

public slots:
    void UpdateState();
};
#endif // ENEMYBOSS_H
