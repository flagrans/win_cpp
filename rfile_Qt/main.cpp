#include <QCoreApplication>
#include <QDir>
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

int main(int argc, char *argv[]) {
    system("cls");
    QCoreApplication a(argc, argv);

    QString arg1, arg2, arg3;
    QTextStream stream(stdin);
    QString line;
    qInfo() << "Enter directory for rename:";
    stream.readLineInto(&line);
    arg1 = line;
    if (arg1.indexOf(":\\") == -1) {
        qInfo().noquote() << "Wrong directory path <disk>:\\path\\";
        system("pause");
        return 1;
    }
    qInfo() << "Enter search string:";
    stream.readLineInto(&line);
    arg2 = line;
    qInfo() << "Enter replace string:";
    stream.readLineInto(&line);
    arg3 = line;

    system("cls");

    qInfo().noquote() << "Directory for rename:" << arg1;
    qInfo().noquote() << "Search:" << arg2;
    qInfo().noquote() << "Replace:" << arg3 << "\r\n";

    qInfo() << "The process cannot be canceled! To begin?(yes/no):";
    stream.readLineInto(&line);

    if (line != "yes") {
        return 1;
    } else {
        QFile data("output.log");
        if (data.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&data);
            out << "Directory for rename:" << arg1 << "\r\n";
            out << "Search:" << arg2 << "\r\n";
            out << "Replace:" << arg3 << "\r\n\r\n";
            out << "Begin rename:" << "\r\n";
            qInfo().noquote() << "Begin rename:";
            createFileTree(arg1, arg2, arg3, out);
            out << "\r\nTotal objects:" << i << "\r\n";
            out << "Total renamed objects:" << ri << "\r\n";
            out << "Done!";
            qInfo().noquote() << "\r\nTotal objects:" << i;
            qInfo().noquote() << "Total renamed objects:" << ri;
            qInfo().noquote() << "Done!";
        }
    }

    system("pause");

    //return a.exec();
    return 0;
}
