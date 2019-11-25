#include <string>
#include <iostream>
#include "../include/User.h"
#include "../include/Action.h"
#include "../include/Watchable.h"
#include "../include/Session.h"


void PrintActionsLog::act(Session& sess) {
    std::vector<BaseAction *> actions = sess.getActionsLog();
    for (int i = 0; i < actions.size() - 1; i++) {
        std::cout << actions[i]->toString();
    }
}
std::string PrintActionsLog::toString() const{
    std::string output;
    if (getStatus() == ERROR){
        output = "PrintActionsLog ERROR" + getErrorMsg();
    }

    if (getStatus() == COMPLETED){
        output = "PrintActionsLog COMPLETED";
    }
    if (getStatus() == PENDING){
        output = "PrintActionsLog PENDING";
    }
    return output;
}

BaseAction* PrintActionsLog::clone(){
    return (new PrintActionsLog(*this));
}