#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QObject>
#include <QPainter>
#include "aes256.h"
#include "QRCodeGenerator.h"
#include <QImage>
#include <QSqlDatabase>
#include <QLabel>
#include <QGroupBox>

#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QTextEdit>
#include <QCheckBox>
#include "navbutton.h"
#include <QStackedWidget>

struct FORM
{
    QString form_type;
    QString loc_num;
    int int_loc_num;
    QString val_of_rec;
    QString qr_text;
};

class commonData : public QObject
{
    Q_OBJECT
public:

    explicit commonData(QObject *parent = 0);
    void updateQRImage(QString text, int scypher, int index,int invert);
    QString scypher(QString text);
    QString to_base64(unsigned char * in,int buffsize);
    void draw_number(QPainter &painter, int x, int y, int d, int val);
    void draw_label(QPainter &painter, int x, int y, int h, int w, int fontsize, QString lbl);
    void draw_form(QPainter &painter, int X0, int Y0, int W,int H,int int_loc_num, QString form_type, QString loc_num,QString val_of_rec);

    void draw_page(QPainter &painter,std::vector <FORM>& form_arr,int istart,int iend,int invert);

    void gen_forms_array();
    QComboBox* comboloc;

    QComboBox* comboform;
    double percent;
    int area_loc[1000];
    int forms_numbers[100];
    int num_que;
    int selected_row1;
    int selected_row2;
    int selected_row3;
    int selected_row4;
    int marg;

    QComboBox *filterCombo1;
    QComboBox *filterCombo2;
    QComboBox *filterCombo3;
    QComboBox *filterCombo4;
    QLineEdit *filterEdit1;
    QLineEdit *filterEdit2;
    QLineEdit *filterEdit3;
    QLineEdit *filterEdit4;
    NavButton *edit1;
    NavButton *rem1;
    NavButton *add1;

    NavButton *edit2;
    NavButton *rem_area2;
    NavButton *rem_loc2;
    NavButton *add_area2;
    NavButton *add_loc2;

    QString que;
    int num_area;
    int answer;
    QString area;
    int locat;
    int users;
    QString disk;
    QString comm_answer;

    QString forms_names[100];
    std::vector<FORM> forms;
    QString text_for_qr;
    QString form;
    QString loc;
    QString val;
    QString global_val_name;
    QString global_loc_name;
    QString global_qr_label;
    int global_form_model;
    QString aes256_key;
    CQR_Encode qrEncode;
    QImage eI;
    QComboBox *langCombo;
    QLineEdit *nameEdit;
    QLineEdit *keyEdit;
    QLineEdit *LocNumEdit;
    QLineEdit *ValOfRecEdit;
    QLineEdit *PercentEdit;
    QComboBox *FormTypeCombo;

    QLabel* num_form_label;
    QLabel* PercentLabel;
    QLabel* total_num_label;

    QString curr_pdf_path;
    QSpinBox *pagesspinbox;
    void init_db();
    void open_db();
    QString db_name;
    QSqlDatabase db;

    QGroupBox *formParametersGroup;

    QLabel *nameLabel;

    QLabel *keyLabel;

    QLabel *LocNumLabel;

    QLabel *ValOfRecLabel ;

    QLabel *FormTypeLabel;
    NavButton *genButton;
    NavButton *printButton;
    QGroupBox *langGroup;
    QLabel *langLabel;
    QGroupBox *tablesGroup;
    QLabel *tableLabel1;
    QLabel *tableLabel2;
    QLabel *tableLabel3;
    QLabel *tableLabel4;
    NavButton *tab1;
    NavButton *tab2;


    QStackedWidget *tableStack;
    NavButton *filterButton1;
    NavButton *addButton1;
    NavButton *genff;
    NavButton *printforms;
    bool status;
    NavButton *editButton1;
    NavButton *remButton1;
    NavButton *checkallButton1;
    NavButton *uncheckallButton1;
    NavButton *filterButton2;
    NavButton *addButton2;
    NavButton *remButton2;
    NavButton *checkallButton2;
    NavButton *uncheckallButton2;
    NavButton *editButton3;
    NavButton *filterButton3;
    NavButton *addButton3;
    NavButton *remButton3;
    NavButton *checkallButton3;
    NavButton *uncheckallButton3;
    NavButton *editButton4;
    NavButton *filterButton4;
    NavButton *addButton4;
    NavButton *remButton4;
    NavButton *checkallButton4;
    NavButton *uncheckallButton4;
    QGroupBox *printGroup;
    NavButton *openButton;

    NavButton *nextButton;
    QTextEdit* qrtext;

    QCheckBox * check_form_type;
    QCheckBox * check_empty;

signals:

public slots:
};

#endif
