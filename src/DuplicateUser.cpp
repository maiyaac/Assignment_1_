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


void BaseAction::act(Session & sess){
    std::string input = sess->getInput();
    input = input.substr(7, input.size()-1);
    std::string nameCopy = input.substr(0, input.find(" "));
    std::string myName = input.substr(input.find(" "), input.size()-1);
    std::unordered_map<std::string, User*>::iterator it;
    it = sess.getUserMap().find(nameCopy);
    if(it==sess->getUserMap().end()){
        setStatus(ERROR);
        sess->addActionLog(this);
        errorMsg = "The user does not exist!";
        return error(errorMsg);
    }
    it = sess.getUserMap().find(myName);
    if (it!=sess.getUserMap().end()){
        setStatus(ERROR);
        sess.addActionLog(this);
        errorMsg = "A user with this name already exists!";
        return error(errorMsg);
    }
    else {
        sess.duplicateUser(myName);
        sess->addActionLog(this);
        setStatus(COMPLETED);
    }
    sess.duplicateUser();
}

virtual std::string toString() const;