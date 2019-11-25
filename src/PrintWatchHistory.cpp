#include <string>
#include <iostream>
#include "../include/User.h"
#include "../include/Action.h"
#include "../include/Watchable.h"
#include "../include/Session.h"

void PrintWatchHistory::act (Session& sess){
    std::vector<Watchable*> history = sess.getActiveUser()->get_history();
    for (int i=0; i<history.size()-1; i++){
        std::cout << history[i]->toString();
    }

}
std::string PrintWatchHistory::toString() const{
    std::string output;
    if (getStatus() == ERROR){
        output = "PrintWatchHistory ERROR" + getErrorMsg();
    }

    if (getStatus() == COMPLETED){
        output = "PrintWatchHistory COMPLETED";
    }
    if (getStatus() == PENDING){
        output = "PrintWatchHistory PENDING";
    }
    return output;
}

BaseAction* PrintWatchHistory::clone(){
    return (new PrintWatchHistory(*this));
}