#include "navbutton.h"
#include <QGraphicsEffect>

NavButton::NavButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(10);
    effect->setOffset(0, 2);
    setGraphicsEffect(effect);
}

void NavButton::activate()
{

  QString style =  QString("QPushButton { \
            color: #222222;\
            background-color: #a5fdf4;\
            border-width: 3px;\
            border-color: white;\
            border-style: solid;\
            padding: 10px;\
            border-radius: 10px;\
            outline: none;\
           font:bold;\
           font-size: 14px;\
           font-family: \"Arial\";\
           text-align:left;\
        }");
    setStyleSheet(style);
}
void NavButton::activate1()
{

    QString style =  QString("QPushButton { \
              color: #666666;\
              background-color: #ffffff;\
              border-width: 3px;\
              border-color: aquamarine;\
              border-style: solid;\
              padding: 10px;\
              border-radius: 10px;\
              outline: none;\
             font:bold;\
             font-size: 14px;\
             font-family: \"Arial\";\
             text-align:left;\
          }");
    setStyleSheet(style);
}
void NavButton::activate2()
{

    QString style =  QString("QPushButton { \
              color: #666666;\
              background-color: #ffffff;\
              border-width: 3px;\
              border-color: mediumspringgreen ;\
              border-style: solid;\
              padding: 10px;\
              border-radius: 10px;\
              outline: none;\
             font:bold;\
             font-size: 14px;\
             font-family: \"Arial\";\
             text-align:left;\
          }");
    setStyleSheet(style);
}


void NavButton::deactivate()
{

    QString style =  QString("QPushButton { \
              color: #888888;\
              background-color: #663699;\
              border-width: 0px;\
              border-color: #76797C;\
              border-style: solid;\
              padding: 10px;\
              border-radius: 3px;\
              outline: none;\
             font:bold;\
             font-size: 14px;\
             font-family: \"Arial\";\
             text-align:left;\
          }");
    setStyleSheet(style);
}
