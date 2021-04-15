#include "person.h"

Person::Person(){}

Person::Person(int id, QString firstName, QString secondName, int age, int salary){
    this->id = id;
    this->firstName = firstName;
    this->secondName = secondName;
    this->age = age;
    this->status = atHome;
    this->salary=salary;
}

void Person::set_status(PersonStatus status){
    this->status=status;
}

QString Person::get_fullName(){
    QString name = this->firstName + " " + this->secondName;
    return name;
}

int Person::get_id(){
    return this->id;
}

QString Person::get_string_age(){
    if (this->age % 10 == 1)
        return QString::number(age)+" год";
    else if (this->age % 10 > 1 && this->age % 10 < 5)
        return QString::number(age)+" года";
    else
        return QString::number(age)+" лет";
}

Person::PersonStatus Person::get_status(){
    return this->status;
}

int Person::get_salary(){
    return this->salary;
}

