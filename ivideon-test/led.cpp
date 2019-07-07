#include "led.h"
#include <qdebug.h>

///----------------------------------------------------------------------------
Led::Led(QWidget *parent)
    : QWidget(parent), color_(red),
      state_(false), rate_(0), timer_id(0), rate_flag(false)
{
    if (rate_) { timer_id = startTimer(1000/rate_); }
}

///----------------------------------------------------------------------------
Led::~Led() {}

///----------------------------------------------------------------------------
void Led::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // Создаём объект отрисовщика
    QPainter painter(this);

    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    // Включен, выбираем один из цветов rgb
    if (state_ && rate_flag)
    {
        switch (color_)
        {
            case red:
            {
                painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
                painter.drawEllipse(250, 150, 150, 150);
            }
            break;

            case green:
            {
                painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
                painter.drawEllipse(250, 150, 150, 150);
            }
            break;

            case blue:
            {
                painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
                painter.drawEllipse(250, 150, 150, 150);
            }
            break;

            case last: break;
        }
    }
    // Выключен, рисую фоном виджета
    else
    {
        painter.setBrush(QBrush(QWidget::palette().color(QWidget::backgroundRole()),
                                Qt::SolidPattern));
        painter.drawEllipse(250, 150, 150, 150);
    }
}

///----------------------------------------------------------------------------
void Led::timerEvent(QTimerEvent* event)
{
    Q_UNUSED(event);

    if (!state_) { return; }

    rate_flag = !rate_flag;

    repaint();
}

///----------------------------------------------------------------------------
void Led::on_state_changed()
{
    repaint();
}

///----------------------------------------------------------------------------
void Led::on_color_changed()
{
    repaint();
}

///----------------------------------------------------------------------------
void Led::on_rate_changed()
{
    killTimer(timer_id);
    if (rate_) { timer_id = startTimer(1000/rate_); }
}

bool Led::setColor(int color)
{
    if ( color < 0 || color >= Color::last ) { return false; }

    color_ = static_cast<Color>(color);

    qDebug() << static_cast<int>(color_);

    return true;
}

int Led::getColor()
{
    return color_;
}

bool Led::setState(bool state)
{
    state_ = state;
    return true;
}

bool Led::getState()
{
    return state_;
}

bool Led::setRate(int rate)
{
    rate_ = rate;                   /// !!! add checking for unavaliable rate and return false
    return true;
}

int Led::getRate()
{
    return rate_;
}

