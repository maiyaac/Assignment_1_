
#include "../include/User.h"
#include "../include/Action.h"
#include <map>
using namespace std;

CreateUser::CreateUser():{
    string errorMsg="user with this name already exist";
    ActionStatus status=PENDING;
}
CreateUser::CreateUser() {}
CreateUser ::~CreateUser();

void CreateUser::act(Session &sess) {
    string s="";
    //sess->addActionLog(new CreateUser());
    s=sess->getInput();
    s=s.substr(10,s.size()-1);// check
    string name=s.substr(0,s.find(" "));//check
    string recG=s.substr(s.find(" ")+1,s.size());
    if(recG.compare("len")!=0&recG.compare("rer")!=0&recG.compare("gen")!=0){
        setStatus(ERROR);
        setErrorMsg("no such recommendation algorithm");
        sess->addActionLog(this);
        return error(getErrorMsg());
    }
    map <string,User*>::iterator it=sess->getUserMap().find(name);
    if(it!=sess->getUserMap().end()) {
        setStatus(ERROR);
        sess->addActionLog(this);
        return error(getErrorMsg());
    }
    sess->addUser(name,new User(name,recG));
    setStatus(COMPLETED);
    sess->addActionLog(this);
    sess->setActiveUser(this);


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