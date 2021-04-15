#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person();
    enum PersonStatus{
        onVacation,
        onRoute,
        atHome
    };

    Person(int id, QString firstName, QString secondName, int age, int salary);
    void set_status(PersonStatus);
    QString get_fullName();
    int get_id();
    PersonStatus get_status();
    QString get_string_age();
    int get_salary();

protected:
    int id;
    QString firstName;
    QString secondName;
    int age;
    PersonStatus status;
    int salary;
};

#endif // PERSON_H
