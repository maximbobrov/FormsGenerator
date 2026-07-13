#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include "pages.h"
#include <QPrintDialog>
#include <QApplication>

int curr_page=0;

void GenerateFormsPage::gen_forms()
{

data->gen_forms_array();
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");

    if (fileName.isEmpty()) return;

    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     data->curr_pdf_path=fileName;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setResolution(300);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setPageMargins (0,0,0,0,QPrinter::Millimeter);
    printer.setFullPage(false);
    printer.setOutputFileName(fileName);
    printer.setOutputFormat(QPrinter::PdfFormat); //or QPrinter::NativeFormat



    QPainter painter(&printer); // create a painter which will paint 'on printer'.

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);


    qDebug()<<"num="<<data->forms.size()<<endl;
    for (int i=0;i<data->forms.size();i++)
    {

        qDebug()<<"i="<<i<<" "<<data->forms[i].form_type<<" "<<data->forms[i].int_loc_num<<endl;
    }

    for (int ii=0;ii<=(data->forms.size()-1)/4;ii++)
    {

        data->draw_page(painter,data->forms,ii*4,data->forms.size(),0);
       // if (ii!=9)
        if (ii<(data->forms.size()-1)/4)
         {
            printer.newPage();

         }
           if((ii!=data->forms.size()/4) && (ii%10==0))
           {
               state->setText(QString("Progress:")+QString::number(int(ii*400/data->forms.size()))+QString("%"));
               qApp->processEvents();
           }
           if (ii==data->forms.size()/4)
                state->setText(QString("Progress:100%"));
    }
    painter.end();
    state->setText(tr("PDF exported. Preview is disabled in this build."));
    data->pagesspinbox->setSuffix(QString());
    data->pagesspinbox->setMinimum(0);
    data->pagesspinbox->setMaximum(0);
    data->pagesspinbox->setSingleStep(1);
    data->pagesspinbox->setValue(0);
    slider->setMinimum(0);
    slider->setMaximum(0);
    slider->setSingleStep(1);
    slider->setValue(0);
    render_page(0);

}
void GenerateFormsPage::next()
{
     render_page(curr_page);
}
void GenerateFormsPage::prev()
{
     render_page(curr_page);
}
void GenerateFormsPage::first()
{
     render_page(0);
}
void GenerateFormsPage::last()
{
     render_page(curr_page);
}
void GenerateFormsPage::change_percent(QString a)
{
data->percent=a.toDouble()/100;
}
void GenerateFormsPage::update_view_sing()
{


    QPixmap  map( 1600,1100);
    QPainter painter(&map);
       painter.setBrush(QBrush(Qt::transparent));
       //painter.drawRect(10, 10, 100, 100);


       painter.fillRect(QRectF(0,0,map.width(),map.height()),Qt::white);


       int iii=12345;


       int frmindx=data->comboform->currentIndex();
       int locindx=data->comboloc->currentIndex();


       if (frmindx<0) frmindx=0;
       if (locindx<0) locindx=0;
       qDebug()<<"frmindx="<<frmindx<<" locindx="<<locindx<<endl;

                   QString number = QString("%1").arg(data->area_loc[locindx], 8, 10, QChar('0'));
                   QString ffff = QString("%1").arg(data->forms_numbers[frmindx], 2, 10, QChar('0'));
                    QString series = QString("%1").arg(iii, 5, 10, QChar('0'));
                  // frm.qr_text=global_qr_label+number+series+ffff+"1";


                    //if (!data->check_form_type->isChecked())


       QString qrtextloc=data->nameEdit->text()+number+series+ffff;

       int locc=abs(data->area_loc[locindx]);
       if (data->FormTypeCombo->currentIndex()==1)
       locc=-(locc/10000);

       if (data->check_empty->isChecked())
       {
           locc=0;
           qrtextloc+="1";
       }else
               {
                   qrtextloc+="0";
               }

       QString scyphered=data->scypher(qrtextloc);
       int slen=strlen( qrtextloc.toUtf8().constData());
       data->qrtext->setText(QString("<b>qr-code text:</b> %1 <b> %2 symbols </b> <br> <b>scyphered text:</b> %3 <b> %4 symbols </b>").arg(qrtextloc).arg(slen).arg(scyphered).arg(scyphered.length()));
         data->updateQRImage(qrtextloc,1,2,1);


       data->draw_form( painter, 0, 0, map.width(),map.height(),locc, data->forms_names[frmindx], QString (data->LocNumEdit->text()),QString (data->ValOfRecEdit->text()));

      // painter.end();
    viewer_sing->pix=map;
    viewer_sing->updatePix();
}
void GenerateFormsPage::update_key(QString key)
{
    data->aes256_key=key;
    update_view_sing();
}
void GenerateFormsPage::render_page(int page)
{
    curr_page=page;
    QPixmap map(900, 640);
    map.fill(Qt::white);
    QPainter painter(&map);
    painter.setPen(Qt::darkGray);
    painter.drawText(map.rect(), Qt::AlignCenter,
                     tr("PDF preview is disabled in this build.\nThe PDF file was still exported."));

    slider->setValue(page);
    data->pagesspinbox->setValue(page);
    viewer->pix=map;
    viewer->updatePix();
}
void GenerateFormsPage::print_forms()
{
data->gen_forms_array();
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted)
        return ;

    printer.setResolution(300);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setPageMargins (0,0,0,0,QPrinter::Millimeter);
    printer.setFullPage(false);

    QPainter painter(&printer); // create a painter which will paint 'on printer'.
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    qDebug()<<printer.width()<<" "<<printer.height()<<endl;
    for (int ii=0;ii<=data->forms.size()/4;ii++)
    {
        if (ii!=0)
           printer.newPage();
        data->draw_page(painter,data->forms,ii*4,data->forms.size(),1);
       // if (ii!=9)

    }
    painter.end();
}
