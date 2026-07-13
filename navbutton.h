#ifndef NAVBUTTON_H
#define NAVBUTTON_H

#include <QObject>
#include <QPushButton>

class NavButton : public QPushButton
{
    Q_OBJECT
public:
    NavButton(const QString &text, QWidget *parent = Q_NULLPTR);

    void activate();
    void activate1();
    void activate2();
    void deactivate();

};

#endif // NAVBUTTON_H
