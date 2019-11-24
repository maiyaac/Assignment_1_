
#include "../include/User.h"
#include "../include/Action.h"
#include <map>
using namespace std;

void CreateUser::act(Session &sess) {
    string s="";
    //sess->addActionLog(new CreateUser());
    s=sess->getInput();
    s=s.substr(10,s.size()-1);// check
    string name=s.substr(0,s.find(" "));//check
    string recG=s.substr(s.find(" ")+1,s.size());
    if(recG.compare("len")!=0&recG.compare("rer")!=0&recG.compare("gen")!=0){
        sess->addActionLog(this);
        return error("No such recommendation option!");
    }
    map <string,User*>::iterator it=sess->getUserMap().find(name);
    if(it!=sess->getUserMap().end()) {
        sess->addActionLog(this);
        return error("A user with this name already exists!");
    }
    sess->addUser(name, recG);
    sess->addActionLog(this);
    complete();
}

string CreateUser::toString() const {
    string s="Create User ";
    if(getStatus()==ERROR)
        s=s+"ERROR "+getErrorMsg();
    if(getStatus()==COMPLETED)
        s=s+"COMPLETED ";
    if(getStatus()==PENDING)
        s=s+"PENDING ";
    return s;

}