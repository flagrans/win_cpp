#include "mainwindow.h"
#include <QDir>
#include <QApplication>
#include <QStringList>
#include <QDebug>
#include <QTime>

int i = 0, ri = 0;

void reName(const QFileInfo& fileInfo, const QString& search, const QString& zamena, QTextStream& out){
    auto aPath = fileInfo.absoluteFilePath();
    auto path = fileInfo.path();
    auto fName = fileInfo.fileName();
    if (fName.indexOf(search) != -1) {
        QFile(aPath).rename(path + "\\" + fName.replace(search, zamena));
        out << aPath << "\r\n";
        qInfo().noquote() << aPath;
        ri++;
    }
}

QStringList createFileTree(const QString& dir_name, const QString& search, const QString& zamena, QTextStream& out)
{
    QStringList ret_list;
    QDir dir(dir_name);
    QFileInfoList info_list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
    for(const auto& fileInfo : info_list)
    {
        auto aPath = fileInfo.absoluteFilePath();
        if(fileInfo.isDir()) {
            ret_list << createFileTree(aPath, search, zamena, out);
            reName(fileInfo, search, zamena, out);
            i++;
        } else {
            reName(fileInfo, search, zamena, out);
            ret_list << aPath;
            i++;
        }
    }
    return ret_list;
}

int mFunc (const QString& arg1, const QString& arg2, const QString& arg3){
    QString dn = "output_" + QTime::currentTime().toString("HH_mm_ss_zz") + ".log";
    QFile data(dn);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "Directory for rename:" << arg1 << "\r\n";
        out << "Search:" << arg2 << "\r\n";
        out << "Replace:" << arg3 << "\r\n\r\n";
        out << "Begin rename:" << "\r\n";
        createFileTree(arg1, arg2, arg3, out);
        out << "\r\nTotal objects:" << i << "\r\n";
        out << "Total renamed objects:" << ri << "\r\n";
        out << "Done!";
        return ri;
    } else {
        return ri;
    }
}

int main(int argc, char *argv[])
{
    QString arg1, arg2, arg3;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
