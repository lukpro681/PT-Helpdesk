#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsDialog(int row, const QString &from, const QString &type, const QString &status, const QString &description, QWidget *parent = nullptr);
    ~DetailsDialog();

signals:

    void closeCaseRequest(int row, const QString &from, const QString &type, const QString &description);

private slots:
    void on_closeCaseButton_clicked();

private:
    Ui::DetailsDialog *ui;
    int row;
    QString from;
    QString type;
    QString status;
    QString description;
};

#endif // DETAILSDIALOG_H
