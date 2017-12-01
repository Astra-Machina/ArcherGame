#include "enemyboss.h"

EnemyBoss::EnemyBoss(QObject *parent) : QObject(parent)
{
    velocity = new QVector2D(0, 2);
    //setPixmap( QPixmap(":/images/.png") );
    setTransformOriginPoint(85, 130);
    setRotation(180);


    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateState()));
    timer->start(50);
}

EnemyBoss::~EnemyBoss()
{
    delete velocity;
}


void EnemyBoss::UpdateState()
{
    setPos(x()+velocity->x(), y()+velocity->y());
    if(pos().y() > 1000)
    {
      scene()->removeItem(this);
      delete(this);
    }
}
