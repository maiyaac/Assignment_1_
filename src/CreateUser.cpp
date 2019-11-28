
#include "../include/User.h"
#include "../include/Action.h"
#include "../include/Session.h"
#include <unordered_map>
using namespace std;

void CreateUser::act(Session &sess) {
    string s="";
    s=sess.getInput();
    s=s.substr(11,s.size());
    string name=s.substr(0,s.find(" "));//check
    string recG=s.substr(s.find(" ")+1,s.size());
    if(recG.compare("len")!=0&recG.compare("rer")!=0&recG.compare("gen")!=0){
        error("No such recommendation option!");
        sess.addActionLog(this);
    }
    unordered_map<string,User*>::const_iterator it = sess.getUserMap().find(name);
    if(it!=sess.getUserMap().end()) {
        error("A user with this name already exists!");
        sess.addActionLog(this);
    }
    else{
        sess.addUser(name, recG);
        complete();
        sess.addActionLog(this);
    }
}

string CreateUser::toString() const {
    string s="CreateUser: ";
    if(getStatus()==ERROR)
        s=s+"ERROR "+getErrorMsg();
    if(getStatus()==COMPLETED)
        s=s+"COMPLETED ";
    if(getStatus()==PENDING)
        s=s+"PENDING ";
    return s;

}

BaseAction* CreateUser::clone(){
    return (new CreateUser(*this));
}

CreateUser::~CreateUser() {
}