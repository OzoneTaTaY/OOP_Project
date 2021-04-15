#ifndef BUS_H
#define BUS_H
#include <QString>
class Bus{
public:
    enum BusType //перечисляемый тип для типа автобуса
    {
        MAZ,
        LIAZ,
        VOLGABUS
     };
    enum BusStatus //перечисл тип для типа автобуса
    {
        inRoad,
        inPark,
        inService
    };
    //Конструкторы
    Bus();
    Bus(QString gosnomer, BusType busType, BusStatus busStatus);

    //сеттеры
    void set_gosnomer(QString gosnomer);
    void set_BusType(BusType busType);
    void set_BusStatus(BusStatus busStatus);

    //геттеры
    QString get_gosnomer();
    BusType get_busType();
    BusStatus get_busStatus();
private:
    QString gosnomer;
    BusType busType;
    BusStatus busStatus;
};

#endif // BUS_H
