#include "system.h"



System &System::getInstance()
{
    if(!System::instance){
        System::instance=new System();

    }
    return *System::instance;
}

void System::destroyInstace()
{
    if(System::instance){

        delete System::instance;
        System::instance=nullptr;
    }
}

void System::setUsername(QString name)
{
    client->setUser(name);
}

QString System::connectionReceive()
{
    QString rcv=connection->receive();


    if(rcv!=""){
                qDebug()<<rcv<<" DEBUG!";
    }
    return rcv;
}

void System::connectionSend(QString msg)
{
    connection->sendMessage(msg);
}

QString System::getUsername()
{
    return client->getUser();
}

void System::addCampaign(Campaigns* camp)
{
    myCampaigns.push_back(camp);
}

int System::getVectCampaignSize()
{
    return this->myCampaigns.size();
}

Campaigns *System::getCampaign(int index)
{
    return this->myCampaigns[index];
}

void System::addAnimal(Animal *anm)
{
    this->myAnimals.push_back(anm);
}

int System::getVectAnimalSize()
{
    return this->myAnimals.size();
}

Animal* System::getAnimal(int index)
{

    return this->myAnimals[index];
}

void System::emptySearchAnimals()
{
    myAnimals.clear();
}

void System::emptyCampaigns()
{
    myCampaigns.clear();
}

void System::emptyClient()
{
    delete client;
}

void System::emptyRequests()
{
    myRequests.clear();
}

void System::setLogFile(QString info)
{
    this->logFile=info;

}

QString System::getUserId()
{
return this->client->getId();
}

void System::setUserId(QString id)
{
this->client->setId(id);
}

QString System::getLogFile()
{
    return this->logFile;
}

Request *System::getRequest(int index)
{
return this->myRequests[index];
}

int System::getVectRequestSize()
{
return this->myRequests.size();

}

void System::addRequest(Request *req)
{
    myRequests.push_back(req);
}

