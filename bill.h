#ifndef BILL_H
#define BILL_H
#include <QString>
#include <QDate>
#include <QTime>

class Bill
{
public:
    Bill();
    Bill(int idBiil, QString gosNomerBus);

    void finishBill();

    int get_idBill();
    QString get_gosNomerBus();
    bool get_statusBill();
    QString get_stringStartDateTime();
    QString get_stringFinishDateTime();

protected:
    int idBill;
    QString gosNomerBus;
    QDate startDate;
    QTime startTime;
    QDate finishDate;
    QTime finishTime;
    bool statusBill;
};

#endif // BILL_H
