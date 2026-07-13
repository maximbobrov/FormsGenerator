#ifndef DIALOG2_H
#define DIALOG2_H
#include <QDialog>

#include <QWidget>
#include <QSqlTableModel>
#include <mysqltablemodel.h>
#include <QTableView>
#include <QComboBox>
#include <QLineEdit>
#include <QTranslator>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <qgridlayout>
#include "commondata.h"

class Dialog2 : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog2(QWidget *parent = 0,commonData *d=0);
    ~Dialog2();
     commonData *data;
bool status;
  QLineEdit *locat;
  QLineEdit *users;
   QLineEdit *disk;
    QLineEdit *num_area;
    QLineEdit *area;
    QLabel *area_l;
   QLabel *num_area_1;
   QLabel *locat_l;
   QLabel *users_l;
   QLabel *disk_l;
   NavButton * add_new;
   NavButton * edit_new;

void my_show();

private slots:
   void update();
    void update_edit();

signals:
   void add();
   void edit();
private:

};
#endif // DIALOG2_H
