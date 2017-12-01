#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>
#include <QObject>
#include "player.h"
#include "enemymob.h"
#include "enemyboss.h"

class Game : public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    QMediaPlayer *music;
public:
    explicit Game(QObject *parent = 0);
    ~Game();

signals:

public slots:
    void spawnMob();
    void spawnBoss();
};

#endif // GAME_H
