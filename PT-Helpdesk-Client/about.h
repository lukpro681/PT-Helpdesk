#ifndef ABOUT_H
#define ABOUT_H

#include <QApplication>
#include <QDialog>


namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
    QString appName = qApp->applicationName();
    QString version = qApp->applicationVersion();
    QString authors = qApp->property("Authors").toString();
    QString license = qApp->property("license").toString();
};

#endif // ABOUT_H
