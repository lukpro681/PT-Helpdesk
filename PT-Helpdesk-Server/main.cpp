#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon());
    a.setApplicationDisplayName("PT-Helpdesk Administrator");
    a.setApplicationName("PT-Helpdesk Administrator");
    a.setApplicationVersion("1.0.0");

    QString authors = "Łukasz Prokop, Wojciech Tworek";

    QString programLicense = "This program is open-source and available for everyone under the GNU General Public License";


    a.setProperty("Authors", authors);
    a.setProperty("license", programLicense);




    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "PT-Helpdesk-Server_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.setWindowIcon(QIcon());
    w.show();
    return a.exec();
}
