
#include "../include/Action.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/User.h"
#include "../include/Session.h"

void DeleteUser::act(Session & sess){
    std::string input = sess.getInput();
    input = input.substr(11, input.size()-1);
    std::string name = input.substr(0, input.size());
    std::unordered_map<std::string, User*>::const_iterator it = sess.getUserMap().find(name);
    if(it==sess.getUserMap().end()){
        error("The user does not exist!");
        sess.addActionLog(this);
    }
    else{
        sess.deleteUserFromMap(name);
      //  sess.deleteUser(it->second); MUST IMPLEMENT THIS!!
        complete();
        sess.addActionLog(this);
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

BaseAction* DeleteUser::clone(){
    return (new DeleteUser(*this));
}

DeleteUser::~DeleteUser() {}