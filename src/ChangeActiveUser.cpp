#include "../include/Action.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/User.h"
#include "../include/Session.h"

void ChangeActiveUser::act(Session& sess){
    std::string input = sess.getInput();
    input = input.substr(10, input.size()-1);
    std::string name = input.substr(0, input.size()-1);
    std::unordered_map<std::string, User*>::const_iterator it;
    it = sess.getUserMap().find(name);
    if(it==sess.getUserMap().end()){
        sess.addActionLog(this);
        return error("The user does not exist!");
    }
    else {
        sess.setActiveUser(it->second);
        sess.addActionLog(this);
        complete();
    }
}
std::string ChangeActiveUser::toString() const {
    std::string output;
    if (getStatus() == ERROR){
        output = "ChangeUser ERROR" + getErrorMsg();
    }

    if (getStatus() == COMPLETED){
        output = "ChangeUser COMPLETED";
    }
    if (getStatus() == PENDING){
        output = "ChangeUser PENDING";
    }
    return output;
}

BaseAction* ChangeActiveUser::clone(){
    return (new ChangeActiveUser(*this));
}