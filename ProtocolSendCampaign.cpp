#include "ProtocolSendCampaign.h"

string ProtocolSendCampaign::handleMessage(string msg)
{
	//de extras datele din BD

	//aici mai trebuie doar de luat toate datele din BD
	//nu primesc nimic de la client

	//mesajul va avea forma :

	// nr_evenimente/data/denumire/locatie/

	// data va avea formatul DD.MM.YYYY

	this->msg = "1/05.04.2022/Event_Sterilizare/Parcul IOR/";
	return this->msg;
}
