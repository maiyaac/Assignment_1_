#include "../include/Action.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/User.h"
#include "../include/Session.h"
#include <algorithm>
#include "../include/Watchable.h"
Watch::~Watch(){


}
void Watch::act(Session& sess) {
    std::string input = sess.getInput();
    input = input.substr(6, input.size());
    std::string watchinput = input.substr(0, input.size());
    long watchID = (atol(watchinput.c_str())) - 1;
    std::vector<Watchable *> *content = sess.getContent();
    Watchable *toWatch = ((content)->at(watchID));
    std::cout << "Watching " << toWatch->stringClone() << endl;
    sess.getActiveUser()->addToHistory(toWatch);
    Watchable *next = (toWatch->getNextWatchable(sess));
    if (next == nullptr)
        next = sess.getActiveUser()->getRecommendation(sess);
    complete();
    sess.addActionLog(this);
    std::cout << "We recommend watching " << next->stringClone() << ", continue watching? [y/n]" << endl;
    getline(cin, input);
    if (input == "y") {
        string temp = "watch ";
        temp += to_string(next->getID()+1);
        sess.setInput(temp);
        sess.watchN();
    }
}

std::string Watch::toString() const{
        string output;
        if (getStatus() == ERROR){
            output = "Watch ERROR" + getErrorMsg();
        }
        if (getStatus() == COMPLETED){
            output = "Watch COMPLETED";
        }
        if (getStatus() == PENDING){
            output = "Watch PENDING";
        }
        return output;
    }

BaseAction* Watch::clone(){
    return (new Watch(*this));
}