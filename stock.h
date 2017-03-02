#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QDate>
#include <QFile>
class Stock
{
    public:

        QString ticker;
        QDate date;
        QDateTime datetime;
        uint timestamp;
        float open;
        float high;
        float low;
        float close;
        int volume;

        Stock();
        void init();
        void print();

};

#endif // STOCK_H
