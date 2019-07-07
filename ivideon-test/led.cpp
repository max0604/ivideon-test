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
    if (state_)
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
    qDebug() << "timerEvent";
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

