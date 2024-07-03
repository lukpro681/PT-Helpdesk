#ifndef REPORTVIEW_H
#define REPORTVIEW_H

#include <QDialog>
#include <QAbstractButton>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include <QTextStream>

namespace Ui {
class reportView;
}

class reportView : public QDialog
{
    Q_OBJECT

public:
    explicit reportView(QWidget *parent = nullptr);
    ~reportView();
    void getInformation();


private slots:


    void on_buttonBox_accepted();

    void on_saveInfoButton_clicked();

private:
    Ui::reportView *ui;
    QString info;
};

#endif // REPORTVIEW_H
