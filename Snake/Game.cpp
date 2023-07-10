#include "Game.h"
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>

Game::Game()
{
    this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
    this->setWindowTitle("The Snake");
    initGame();
}

void Game::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if(m_inGame)
    {
        checkApple();
        move();
        checkField();
    }

    this->repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_Left  && m_dir != right) m_dir = left;
    if(key == Qt::Key_Right && m_dir != left)  m_dir = right;
    if(key == Qt::Key_Up    && m_dir != down)  m_dir = up;
    if(key == Qt::Key_Down  && m_dir != up)    m_dir = down;
    switch(key)
    {
    case Qt::Key_Left :
        qDebug() << "Key_Left";
        break;
    case Qt::Key_Right :
        qDebug() << "Key_Right";
        break;
    }


}

void Game::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    doDrawing();
}

void Game::initGame(void)
{
    m_inGame = true;
    m_dir = right;
    m_dots.resize(3);

    for(int i = 0; i < m_dots.size(); ++i)
    {
        m_dots[i].rx() = m_dots.size() - i - 1;
        m_dots[i].ry() = 0;
    }

    localApple();
    m_timerId = startTimer(DELAY);
}

void Game::doDrawing()
{
    QPainter qp(this);
    if(m_inGame)
    {
        qp.setBrush(Qt::red);
        qp.drawEllipse(m_apple.x() * DOT_WIDTH, m_apple.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);

        for(int i = 0; i < m_dots.size(); ++i)
        {
            if(i == 0)
            {
                qp.setBrush(Qt::white);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            } else {
                qp.setBrush(Qt::green);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
        }
    } else {
        gameOver();
    }
}

void Game::localApple(void)
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
    m_apple.rx() = qrand() % DOT_WIDTH;
    m_apple.ry() = qrand() % DOT_HEIGHT;
}

void Game::move(void)
{
    for(int i = m_dots.size() - 1; i > 0; --i) m_dots[i] = m_dots[i-1];
    switch(m_dir)
    {
    case left  : {m_dots[0].rx() -= 1; break; }
    case right : {m_dots[0].rx() += 1; break; }
    case up    : {m_dots[0].ry() -= 1; break; }
    case down  : {m_dots[0].ry() += 1; break; }
    }
}

void Game::checkField()
{
    if(m_dots.size() > 4)
    {
        for(int i = 1; i < m_dots.size(); ++i)
        {
            if(m_dots[0] == m_dots[i])
            {
                m_inGame = false;
            }
        }
    }
    auto elem = m_dots[0];
    if(elem.x() >= FIELD_WIDTH || elem.x() < 0 || elem.y() >= FIELD_HEIGHT || elem.y() < 0)
    {
        m_inGame = false;
    }

    if(!m_inGame)
    {
        killTimer(m_timerId);
    }
}

void Game::gameOver()
{
    QMessageBox msgb;
    msgb.setText("Game Over!");
    msgb.exec();

    initGame();
}

void Game::checkApple()
{
    if(m_apple == m_dots[0])
    {
        m_dots.push_back(QPoint(0,0));
        localApple();
    }
}
