#include "enemymob.h"

EnemyMob::EnemyMob(QObject *parent) : QObject(parent)
{
    velocity = new QVector2D(0, 1);
    //setPixmap( QPixmap(":/images/.png") );
    setTransformOriginPoint(85, 130);
    setRotation(180);


    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateState()));
    timer->start(50);
}

EnemyMob::~EnemyMob()
{
    delete velocity;
}


void EnemyMob::UpdateState()
{
    setPos(x()+velocity->x(), y()+velocity->y());
    if(pos().y() > 1000)
    {
      scene()->removeItem(this);
      delete(this);
    }
}

