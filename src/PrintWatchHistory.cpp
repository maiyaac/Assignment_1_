#include <string>
#include <iostream>
#include "../include/User.h"
#include "../include/Action.h"
#include "../include/Watchable.h"
#include "../include/Session.h"

void PrintWatchHistory::act (Session& sess){
    cout<<sess.getActiveUser()->getName()<<endl;
    std::vector<Watchable*>* history = sess.getActiveUser()->get_history();
    for (int i=0; i<history->size(); i++){
        string s= history->at(i)->toString();
        s=s.substr(s.find(" "),s.size());
        std::cout << i+1<<"."<<s<<endl;
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