#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent)
{
    velocity = new QVector2D(0, 0);
    setPixmap( QPixmap(":/images/Arrow.png") );
    setTransformOriginPoint(6, 18);
    setScale(2);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateState()));
    timer->start(50);
}

Arrow::~Arrow()
{
    delete velocity;
}

void Arrow::UpdateState()
{
    setPos(x()+velocity->x(), y()+velocity->y());

    QList<QGraphicsItem*> colliders = collidingItems();
    int n = colliders.size();

    for(int i=0; i<n; i++)
    {
        if(typeid(*(colliders[i])) == typeid(EnemyMob))
        {
            scene()->removeItem(colliders[i]);
            delete(colliders[i]);
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }

    if(pos().y() > 1000 || pos().y() < -1000)
    {
      scene()->removeItem(this);
      delete(this);
    }

}
void Arrow::setVelocity(float newX, float newY)
{
    velocity->setX(newX);
    velocity->setY(newY);
}
