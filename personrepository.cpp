#include "personrepository.h"

PersonRepository::PersonRepository(){
}

bool PersonRepository::addDriver(QString driverLisenceType, QString driverLisenceTime, int id, QString firstName, QString secondName, int age, int salary){
    bool flag =true;
    Driver driver = Driver(driverLisenceType, driverLisenceTime, id, firstName, secondName, age, salary);
    if (this->driverRepos.size() > 0)
        for (int i=0; i < this->driverRepos.size(); i++){
            if (this->driverRepos[i].get_id() == id)
                flag = false;
        }
    if (flag == true){
        this->driverRepos.push_back(driver);
        return true;
    }
    return false;
}

bool PersonRepository::addConductor(unsigned int levelOfQualification, int id, QString firstName, QString secondName, int age, int salary){
    bool flag =true;
    Conductor conductor = Conductor(levelOfQualification, id, firstName, secondName, age, salary);
    if (this->conductorRepos.size() > 0)
        for (int i=0; i < this->conductorRepos.size(); i++){
            if (this->conductorRepos[i].get_id() == id)
                flag = false;
        }
    if (flag == true){
        this->conductorRepos.push_back(conductor);
        return true;
    }
    return false;
}

bool PersonRepository::deleteDriver(int id){
    if (this->driverRepos.size() > 0)
        for (int i=0; i < this->driverRepos.size(); i++){
            if (this->driverRepos[i].get_id() == id){
                driverRepos.remove(i);
                return true;
            }
        }
    return false;
}

bool PersonRepository::deleteConductor(int id){
    if (this->conductorRepos.size() > 0)
        for (int i=0; i < this->conductorRepos.size(); i++){
            if (this->conductorRepos[i].get_id() == id){
                conductorRepos.remove(i);
                return true;
            }
        }
    return false;
}

QString PersonRepository::get_drivers(){
    QString data;
    if (this->driverRepos.size() == 0)
        return "Водителей нет";
    else
        for (int i=0; i < this->driverRepos.size(); i++)
        {
            if (driverRepos[i].get_status() != Person::onVacation){
                data+=QString::number(driverRepos[i].get_id());
                data+="| ";
                data+=driverRepos[i].get_fullName()+" | ";
                data+=driverRepos[i].get_string_age()+" | ";
                data+=QString::number(driverRepos[i].get_salary())+" руб. | ";
                data+="Права: "+driverRepos[i].get_dlType()+" до: "+driverRepos[i].get_dlTime() + " | ";
                if (driverRepos[i].get_status() == Person::atHome){
                    data+="Отдыхает";
                }
                else if (driverRepos[i].get_status() == Person::onRoute){
                    data+="На маршруте";
                }
                data+='\n';
                data+="-------------------------------------------------------------------\n";
            }
        }
    return data;
}

QString PersonRepository::get_conductors(){
    QString data;
    if (this->conductorRepos.size() == 0)
        return "Кондукторов нет";
    else
        for (int i=0; i < this->conductorRepos.size(); i++)
        {
            if (conductorRepos[i].get_status() != Person::onVacation){
                data+=QString::number(conductorRepos[i].get_id());
                data+="| ";
                data+=conductorRepos[i].get_fullName()+" | ";
                data+=conductorRepos[i].get_string_age()+" | ";
                data+=QString::number(conductorRepos[i].get_salary())+" руб. | ";
                data+="Квалификация: "+QString::number(conductorRepos[i].get_level()) + " | ";
                if (conductorRepos[i].get_status() == Person::atHome){
                    data+="Отдыхает";
                }
                else if (conductorRepos[i].get_status() == Person::onRoute){
                    data+="На маршруте";
                }
                data+='\n';
                data+="-------------------------------------------------------------------\n";
            }
        }
    return data;
}

QString PersonRepository::get_chill_persons(){
    QString data;
    bool flag1=true;
    bool flag2=true;
    if (this->conductorRepos.size() == 0 && this->driverRepos.size() == 0)
        return "Отдыхающих нет";
    else{
        for (int i=0; i < this->driverRepos.size(); i++)
            if (driverRepos[i].get_status() == Person::onVacation)
                flag1=false;
        for (int i=0; i < this->conductorRepos.size(); i++){
            if (conductorRepos[i].get_status() == Person::onVacation){
                flag2=false;
            }
        }
        if (flag1 && flag2){
            return "Отдыхающих нет";
        }
        else {
             if (this->driverRepos.size() > 0){
                 data+="Водители:\n";
                 for (int i=0; i < this->driverRepos.size(); i++){
                    if (driverRepos[i].get_status() == Person::onVacation){

                        data+=QString::number(driverRepos[i].get_id());
                        data+="| ";
                        data+=driverRepos[i].get_fullName();
                        data+='\n';
                        data+="---------------------------------------------\n";
                    }
                }
             }
             if (this->conductorRepos.size() > 0){
                 data+="Кондуктора:\n";
                 for (int i=0; i < this->conductorRepos.size(); i++){
                    if (conductorRepos[i].get_status() == Person::onVacation){

                        data+=QString::number(conductorRepos[i].get_id());
                        data+="| ";
                        data+=conductorRepos[i].get_fullName();
                        data+='\n';
                        data+="---------------------------------------------\n";
                    }
                 }
             }
             return  data;
        }
    }
}

bool PersonRepository::driver_vacation(int id){
    if (this->driverRepos.size() > 0)
        for (int i=0; i < this->driverRepos.size(); i++){
            if (this->driverRepos[i].get_id() == id){
               if (driverRepos[i].get_status() == Person::onVacation)
                   driverRepos[i].set_status(Person::atHome);
               else
                   driverRepos[i].set_status(Person::onVacation);
                return true;
            }
        }
    return false;
}
bool PersonRepository::conductor_vacation(int id){
    if (this->conductorRepos.size() > 0)
        for (int i=0; i < this->conductorRepos.size(); i++){
            if (this->conductorRepos[i].get_id() == id){
               if (conductorRepos[i].get_status() == Person::onVacation)
                   conductorRepos[i].set_status(Person::atHome);
               else
                   conductorRepos[i].set_status(Person::onVacation);
                return true;
            }
        }
    return false;
}

bool PersonRepository::conductor_work(int id, bool flagok){
    if (this->conductorRepos.size() > 0)
        for (int i=0; i < this->conductorRepos.size(); i++){
            if (this->conductorRepos[i].get_id() == id){
               if (conductorRepos[i].get_status() == Person::onRoute && flagok == true){
                   conductorRepos[i].set_status(Person::atHome);
                   return true;
               }
               else{
                   if (conductorRepos[i].get_status() == Person::atHome && flagok == false){
                        conductorRepos[i].set_status(Person::onRoute);
                        return true;
                        }
                  }
            }
        }
    return false;
}
bool PersonRepository::driver_work(int id, bool flagok){
    if (this->driverRepos.size() > 0)
        for (int i=0; i < this->driverRepos.size(); i++){
            if (this->driverRepos[i].get_id() == id){
               if (driverRepos[i].get_status() == Person::onRoute && flagok == true){
                   driverRepos[i].set_status(Person::atHome);
                   return true;
               }
               else{
                   if (driverRepos[i].get_status() == Person::atHome && flagok == false){
                        driverRepos[i].set_status(Person::onRoute);
                        return true;
                        }
                  }
            }
        }
    return false;
}

