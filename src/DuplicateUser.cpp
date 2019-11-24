//
// Created by maiy@wincs.cs.bgu.ac.il on 23/11/2019.
//
#include <string>
#include <iostream>
#include <vector>
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/User.h"
#include <unordered_map>


void DuplicateUser::act(Session& sess){
    std::string input = sess.getInput();
    input = input.substr(7, input.size()-1);
    std::string nameCopy = input.substr(0, input.find(" "));
    std::string myName = input.substr(input.find(" "), input.size()-1);
    std::unordered_map<std::string, User*>::iterator it;
    it = sess.getUserMap().find(nameCopy);
    if(it==sess.getUserMap().end()){
        sess.addActionLog(this);
        return error("The user does not exist!");
    }
    it = sess.getUserMap().find(myName);
    if (it!=sess.getUserMap().end()){
        sess.addActionLog(this);
        return error("A user with this name already exists!");
    }
    else {
        sess.duplicateUser(myName);
        sess.addActionLog(this);
        complete();
    }
}

std::string DuplicateUser::toString() const{
    std::string output;
    if (getStatus() == ERROR){
        output = "DuplicateUser ERROR" + getErrorMsg();
    }

    if (getStatus() == COMPLETED){
        output = "DuplicateUser COMPLETED";
    }
    if (getStatus() == PENDING){
        output = "DuplicateUser PENDING";
    }
    return output;
}