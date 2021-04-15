#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "person.h"

class Conductor: public Person
{
public:
    Conductor();
    Conductor(unsigned int levelOfQualification, int id, QString firstName, QString secondName, int age, int salary);
    void set_levelOfQualification(unsigned int levelOfQualification);
    unsigned int get_level();
private:
    unsigned int levelOfQualification;
};

#endif // CONDUCTOR_H
