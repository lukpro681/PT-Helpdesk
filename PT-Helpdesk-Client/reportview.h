#ifndef REPORTVIEW_H
#define REPORTVIEW_H

#include <QDialog>
#include <QAbstractButton>

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

    void on_pushButton_clicked();

private:
    Ui::reportView *ui;
};

#endif // REPORTVIEW_H
