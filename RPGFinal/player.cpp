#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    velocity = new QVector2D(0, 0);
    setPixmap( QPixmap(":/images/Archer.png") );
    setTransformOriginPoint(6, 9);
    setScale(3);
    //setRotation(180);
    setPos(400, 600);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateState()));
    timer->start(50);
}

Player::~Player()
{
    delete velocity;
}


void Player::keyPressEvent(QKeyEvent *event)
{
    velocity->setX(0);
    velocity->setY(0);
    if(event->key() == Qt::Key_Up)
    {
       velocity->setY( velocity->y() - 5 );
    }
//    if(event->key() == Qt::Key_Up)
//    {
//        velocity->setY( velocity->y() + 5);
//    }
    if(event->key() == Qt::Key_Down)
    {
       velocity->setY( velocity->y() + 5 );
    }
    if(event->key() == Qt::Key_Left)
    {
       velocity->setX( velocity->x() - 5 );
    }
    if(event->key() == Qt::Key_Right)
    {
       velocity->setX( velocity->x() + 5 );
    }
    if(event->key() == Qt::Key_Space)
    {
       Arrow * a = new Arrow();
       a->setPos(x()+4, y());
       a->setVelocity(0, -10);
       scene()->addItem(a);
    }

    int maxVelocity = 10;
    if(velocity->length() > maxVelocity)
    {
        velocity->normalize();
        velocity->operator *=(maxVelocity);
    }
    update();
}

void Player::UpdateState()
{
    setPos(x()+ velocity->x(), y() + velocity->y());

    if(x() > 1000)
    {
        setX(1000);
        velocity->setX(0);
    }
    if(x() < -100)
    {
        setX(-100);
        velocity->setX(0);
    }
    if(y() > 750)
    {
        setY(750);
        velocity->setY(0);
    }
    if(y() < 0)
    {
        setY(0);
        velocity->setY(0);
    }


    QList<QGraphicsItem*> colliders = collidingItems();
    int n = colliders.size();

    for(int i=0; i<n; i++)
    {
        if(typeid(*(colliders[i])) == typeid(EnemyMob))
        {
            scene()->removeItem(this);
        }
    }

    for(int i=0; i<n; i++)
    {
        if(typeid(*(colliders[i])) == typeid(EnemyBoss))
        {
            scene()->removeItem(this);
        }
    }

}
