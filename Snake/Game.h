#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>

class Game : public QWidget
{
private:
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    static const int FIELD_WIDTH = 20;
    static const int FIELD_HEIGHT = 20;
    static const int DELAY = 150;

    enum Directions { left, right, up, down };

    Directions m_dir;

    int m_timerId;
    bool m_inGame;
    QVector<QPoint> m_dots;
    QPoint m_apple;

    void initGame(void);
    void doDrawing(void);
    void localApple(void);
    void move(void);
    void checkField(void);
    void gameOver(void);
    void checkApple(void);

protected:
    void timerEvent(QTimerEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
    void paintEvent(QPaintEvent *) override;

public:
    Game();
};

#endif // GAME_H
