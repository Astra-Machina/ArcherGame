#include "game.h"
#include <stdlib.h>


Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    player = new Player();
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1000,800);
    view->setSceneRect(0,0,800,600);
    view->setBackgroundBrush( QBrush( QImage(":/images/SnowRoad.png") ) );
    view->show();

    int count = 0;
    while(count < 30)
    {
//    QTimer *spawnTimer = new QTimer(this);
//    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnMob()));
//    spawnTimer->start(2000);
        count++;
    }
    //QTimer *spawnTimer = new QTimer(this);
    //connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnBoss()));
    //spawnTimer->start(1000000000);


    //music = new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/Audio/Stage1.wav"));
    //music->play();


}

Game::~Game()
{
    delete player;
}

void Game::spawnMob()
{
    EnemyMob *em = new EnemyMob(this);
    scene->addItem(em);
    int xPos = rand()%view->width();

    em->setPos(xPos, -200);

}

void Game::spawnBoss()
{
    EnemyBoss *eb = new EnemyBoss(this);
    scene->addItem(eb);
    int xPos = rand()%view->width();

    eb->setPos(xPos, -200);
}
