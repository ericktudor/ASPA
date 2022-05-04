#ifndef SYSTEM_H
#define SYSTEM_H
#include <QString>
#include "userclient.h"
#include "tcpclient.h"
#include "campaign.h"
#include <vector>
#include "campaigns.h"
#include "animal.h"
#include "request.h"

using namespace std;

class System
{
public:
    static System& getInstance();
    void destroyInstace();
    void setUsername(QString name);
    QString connectionReceive();
    void connectionSend(QString msg);
    QString getUsername();
    void addCampaign(Campaigns* camp);
    void addAnimal(Animal* anm);
    int getVectAnimalSize();
    Animal* getAnimal(int index);
    void emptySearchAnimals();
    void setLogFile(QString info);
    QString getLogFile();
    Request* getRequest(int index);
    int getVectRequestSize();
    void addRequest(Request* req);
private:
    UserClient* client;
    TcpClient* connection;
    QString logFile;
    vector<Campaigns*> myCampaigns;
    vector<Animal*> myAnimals;
    vector<Request*>myRequests;
    static System *instance;
    System(){client=new UserClient;
             connection=new TcpClient;
             connection->connectToServer("127.0.0.1","54010");//172.16.7.23//127.0.0.1
            };
    System(const System&){}
    ~System(){};
};

#endif // SYSTEM_H
