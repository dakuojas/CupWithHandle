#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include "stock.h"

QList<Stock> initStockData(QFile &file);
QList<Stock> findMaximas(QList<Stock> &stockData);
QList<Stock> findMinimas(QList<Stock> &stockData);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("C:/Users/ojas/qt-projects/CupWithHandle/msft-meta.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            qDebug() << "File Not Found";

    QList<Stock> stockData;
    stockData = initStockData(file);
    for(Stock stock : stockData)
    {
//        stock.print();
    }

    QList<Stock> maximas;
    maximas = findMaximas(stockData);
    for(Stock stock : maximas) stock.print();

    QList<Stock> minimas;
    minimas = findMinimas(stockData);
    for(Stock stock : minimas) stock.print();

    return a.exec();
}

QList<Stock> findMinimas(QList<Stock> &stockData)
{
    QList<Stock> minimas;
    int i = 0;
    qDebug() << "MINIMAS";
    while(i < stockData.size()-1)
    {
        if(stockData.at(i).close <= stockData.at(i+1).close)
        {
            qDebug() << i;
            minimas.append(stockData.at(i));
        }
        i++;
    }

    return minimas;
}

QList<Stock> findMaximas(QList<Stock> &stockData)
{
    QList<Stock> maximas;
    int i = 0;
    qDebug() << "MAXIMAS";
    while(i < stockData.size()-1)
    {
        if(stockData.at(i).close <= stockData.at(i+1).close)
        {
            qDebug() << i+1;
            maximas.append(stockData.at(i+1));
        }
        i++;
    }

    return maximas;
}

QList<Stock> initStockData(QFile &file)
{
    Stock s;
    QList<Stock> stockData;
    QTextStream in(&file);
    QString line;
    QStringList splitline;
    while (!in.atEnd())
    {
        line = in.readLine();
        splitline = line.split(",");
        s.ticker = splitline.at(0);
        s.datetime = QDateTime::fromString(splitline.at(1),"dd-MMM-yyyy");
        s.timestamp = s.datetime.toTime_t();
        s.open = splitline.at(2).toFloat();
        s.high = splitline.at(3).toFloat();
        s.low = splitline.at(4).toFloat();
        s.close = splitline.at(5).toFloat();
        s.volume = splitline.at(6).toInt();
        stockData.append(s);
        s.init();
    }

    return stockData;
}
