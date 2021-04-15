#include "conductor.h"

Conductor::Conductor(){}
Conductor::Conductor( unsigned int levelOfQualification, int id, QString firstName, QString secondName, int age, int salary)
    :Person(id, firstName, secondName, age, salary){
    this->levelOfQualification = levelOfQualification;
}
void Conductor::set_levelOfQualification(unsigned int levelOfQualification){
     this->levelOfQualification = levelOfQualification;
}

unsigned int Conductor::get_level(){
    return this->levelOfQualification;
}
