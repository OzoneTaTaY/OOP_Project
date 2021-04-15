#include "billrepository.h"

BillRepository::BillRepository(){}

bool BillRepository::addNewWayBill(int idBill, QString gosNomerBus,int idDriver, int idConductor,unsigned int fare){
    bool flag =true;
    WayBill WB = WayBill(idBill, gosNomerBus,idDriver,idConductor,fare);
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill)
                flag = false;
        }
    if (flag == true){
        this->wayBillRepos.push_back(WB);
        return true;
    }
    return false;
}

bool BillRepository::addNewRepairBill(unsigned int cost, QString describtion,int idBill, QString gosNomerBus){
    bool flag =true;
    RepairBill RB = RepairBill(cost, describtion, idBill, gosNomerBus);
    if (this->repairBillRepos.size() > 0)
        for (int i=0; i < this->repairBillRepos.size(); i++){
            if (this->repairBillRepos[i].get_idBill() == idBill)
                flag = false;
        }
    if (flag == true){
        this->repairBillRepos.push_back(RB);
        return true;
    }
    return false;
}

bool BillRepository::deleteWayBill(int idBill){
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill){
                wayBillRepos.remove(i);
                return true;
            }
        }
    return false;
}

bool BillRepository::deleteRepairBill(int idBill){
    if (this->repairBillRepos.size() > 0)
        for (int i=0; i < this->repairBillRepos.size(); i++){
            if (this->repairBillRepos[i].get_idBill() == idBill){
                repairBillRepos.remove(i);
                return true;
            }
        }
    return false;
}

QString BillRepository::get_gosnomerWay(int idBill){
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill){
                return wayBillRepos[i].get_gosNomerBus();
            }
        }
    return NULL;
}
QString BillRepository::get_gosnomerRepair(int idBill){
    if (this->repairBillRepos.size() > 0)
        for (int i=0; i < this->repairBillRepos.size(); i++){
            if (this->repairBillRepos[i].get_idBill() == idBill){
                return repairBillRepos[i].get_gosNomerBus();
            }
        }
    return NULL;
}
int BillRepository::get_idDriver(int idBill){
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill){
                return wayBillRepos[i].get_idDriver();
            }
        }
    return -1;
}
int BillRepository::get_idConductor(int idBill){
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill){
                return wayBillRepos[i].get_idConductor();
            }
        }
    return -1;
}
bool BillRepository::finishWayBill(int idBill, unsigned int num){
    if (this->wayBillRepos.size() > 0)
        for (int i=0; i < this->wayBillRepos.size(); i++){
            if (this->wayBillRepos[i].get_idBill() == idBill){
                wayBillRepos[i].set_numberOfPassengers(num);
                wayBillRepos[i].finishBill();
                return true;
            }
        }
    return false;
}
bool BillRepository::finishRepairBill(int idBill){
    if (this->repairBillRepos.size() > 0)
        for (int i=0; i < this->repairBillRepos.size(); i++){
            if (this->repairBillRepos[i].get_idBill() == idBill){
                repairBillRepos[i].finishBill();
                return true;
            }
        }
    return false;
}
QString BillRepository::get_openBills(){
    QString data;
    bool flag1 = true;
    bool flag2 = true;
    if (this->repairBillRepos.size() == 0 && this->wayBillRepos.size() == 0){
        return "Нет открытых накладных";
    }
    else{
        for (int i=0; i < this->wayBillRepos.size(); i++)
            if (wayBillRepos[i].get_statusBill() == false)
                flag1=false;
        for (int i=0; i < this->repairBillRepos.size(); i++)
            if (repairBillRepos[i].get_statusBill() == false)
                flag2=false;
        if (flag1 && flag2){
            return "Нет открытых накладных";
        }
        else {
            if (this->wayBillRepos.size() > 0){
                data+="Путевые накладные: \n";
                for (int i=0; i < this->wayBillRepos.size(); i++)
                    if (wayBillRepos[i].get_statusBill() == false){
                        data+= QString::number(wayBillRepos[i].get_idBill())+"| ";
                        data+= "Билет: " + QString::number(wayBillRepos[i].get_fare()) + " руб. | ";
                        data+= wayBillRepos[i].get_stringStartDateTime() + "\n";
                        data+="------------------------------------------------------------\n";
                    }

            }
            if (this->repairBillRepos.size() > 0){
                data+="Ремонтные накладные: \n";
                for (int i=0; i < this->repairBillRepos.size(); i++)
                    if (repairBillRepos[i].get_statusBill() == false){
                        data+= QString::number(repairBillRepos[i].get_idBill())+"| ";
                        data+= "Стоимость: " + QString::number(repairBillRepos[i].get_cost()) + " руб.| ";
                        data+= "Описание: "+ repairBillRepos[i].get_describtion() + " | ";
                        data+= repairBillRepos[i].get_stringStartDateTime()+ "\n";
                        data+="------------------------------------------------------------\n";
                    }
            }
           return data;
        }

    }
}
QString BillRepository::get_finishedBills(){
    QString data;
    bool flag1 = true;
    bool flag2 = true;
    if (this->repairBillRepos.size() == 0 && this->wayBillRepos.size() == 0){
        return "Нет закрытых накладных";
    }
    else{
        for (int i=0; i < this->wayBillRepos.size(); i++)
            if (wayBillRepos[i].get_statusBill() == true)
                flag1=false;
        for (int i=0; i < this->repairBillRepos.size(); i++)
            if (repairBillRepos[i].get_statusBill() == true)
                flag2=false;
        if (flag1 && flag2){
            return "Нет закрытых накладных";
        }
        else {
            if (this->wayBillRepos.size() > 0){
                data+="Путевые накладные: \n";
                for (int i=0; i < this->wayBillRepos.size(); i++)
                    if (wayBillRepos[i].get_statusBill() == true){
                        data+= QString::number(wayBillRepos[i].get_idBill())+"| ";
                        data+= "Билет: " + QString::number(wayBillRepos[i].get_fare()) + " руб. | ";
                        data+= "Открыта: "+wayBillRepos[i].get_stringStartDateTime() + " | ";
                        data+= "Закрыта: "+wayBillRepos[i].get_stringFinishDateTime() +"\n";
                        data+="------------------------------------------------------------\n";
                    }

            }
            if (this->repairBillRepos.size() > 0){
                data+="Ремонтные накладные: \n";
                for (int i=0; i < this->repairBillRepos.size(); i++)
                    if (repairBillRepos[i].get_statusBill() == true){
                        data+= QString::number(repairBillRepos[i].get_idBill())+"| ";
                        data+= "Стоимость: " + QString::number(repairBillRepos[i].get_cost()) + " руб. | ";
                        data+= "Описание: "+ repairBillRepos[i].get_describtion()+" | ";
                        data+= "Открыта: "+repairBillRepos[i].get_stringStartDateTime() + " | ";
                        data+= "Закрыта: "+repairBillRepos[i].get_stringFinishDateTime() +"\n";
                        data+="------------------------------------------------------------\n";
                    }
            }
           return data;
        }

    }
}

QString BillRepository::full_otchet(){
    QString data;
    int x=0;
    int dohod = 0;
    int rashod = 0;
    bool flag=true;
    if (this->wayBillRepos.size()==0 && this->repairBillRepos.size()==0)
        return NULL;
    else{
        for (int i=0; i < this->repairBillRepos.size(); i++)
            if (repairBillRepos[i].get_statusBill()==true)
                flag = false;
        for (int i=0; i < this->wayBillRepos.size(); i++)
                if (wayBillRepos[i].get_statusBill()==true)
                    flag = false;
    }
    if (flag)
        return NULL;
    else{
        data+="--------------------------\n|Путевые накладные: |\n--------------------------\n";
        for (int i=0; i < this->wayBillRepos.size(); i++)
            if (wayBillRepos[i].get_statusBill()==true){
                x=(wayBillRepos[i].get_fare()*wayBillRepos[i].get_numberOfPassengers());
                data+="Накладная №" + QString::number(wayBillRepos[i].get_idBill()) + "\nДоход составил: " + QString::number(x)+"\n";
                dohod+=x;
            }
        data+="---------------------------\nОбщий доход: " + QString::number(dohod) + "\n---------------------------\n";
        data+="----------------------------\n|Ремонтные накладные: |\n----------------------------\n";
        for (int i=0; i < this->repairBillRepos.size(); i++)
            if (repairBillRepos[i].get_statusBill()==true)
            {
                x=repairBillRepos[i].get_cost();
                data+="Накладная №" + QString::number(repairBillRepos[i].get_idBill()) + "\nРасход составил: " + QString::number(x)+"\n";
                rashod+=x;
            }
        data+="---------------------------\nОбщий расход: " + QString::number(rashod) + "\n---------------------------\n";
    }
    if (dohod-rashod >= 0)
        data+="Прибыль составила: " + QString::number(dohod-rashod) + " !";
    else
        data+="Прибыль составила: " + QString::number(dohod-rashod) + " :(";
    return data;

}
