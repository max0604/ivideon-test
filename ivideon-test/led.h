#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class Led : public QWidget
{
    Q_OBJECT

public:
    explicit Led(QWidget *parent = nullptr);
    ~Led();

    enum Color {red, green, blue};

protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void timerEvent(QTimerEvent* event);

private:
    Color color_;
    bool state_;
    int rate_;
    int timer_id;
    bool rate_flag;

private slots:
    void on_state_changed();
    void on_color_changed();
    void on_rate_changed();
};

#endif // LED_H
