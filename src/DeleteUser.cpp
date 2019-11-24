
#include "../include/Action.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/User.h"

void DeleteUser::act(Session & sess){
    std::string input = sess.getInput();
    input = input.substr(11, input.size()-1);
    std::string name = input.substr(0, input.size()-1);
    std::unordered_map<std::string, User*>::iterator it;
    it = sess.getUserMap().find(name);
    if(it==sess.getUserMap().end()){
        sess.addActionLog(this);
        return error("The user does not exist!");
    }
    else{
        sess.getUserMap().erase(name);
        sess.addActionLog(this);
        complete();
    }
}
std::string DeleteUser::toString() const{
    std::string output;
    if (getStatus() == ERROR){
        output = "DeleteUser ERROR" + getErrorMsg();
    }

    if (getStatus() == COMPLETED){
        output = "DeleteUser COMPLETED";
    }
    if (getStatus() == PENDING){
        output = "DeleteUser PENDING";
    }
    return output;
}