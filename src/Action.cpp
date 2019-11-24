//
// Created by maiy@wincs.cs.bgu.ac.il on 23/11/2019.
//

#include "../include/Action.h"

BaseAction::BaseAction() {
    std::string errorMsg;
    ActionStatus status;

}

ActionStatus BaseAction::getStatus() const {
    return status;
}

void BaseAction::complete() {

}

void BaseAction::error(const std::string &errorMsg) {
    std::cout<<errorMsg;

}

std::string BaseAction::getErrorMsg() const {
    return std::__cxx11::string();
}

void BaseAction::setStatus(ActionStatus s) {
    status=s;
}
void BaseAction::setErrorMsg(std::string s) {
    errorMsg=s;
}