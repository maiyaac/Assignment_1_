#include "../include/Action.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/User.h"
#include "../include/Session.h"
#include <algorithm>
#include "../include/Watchable.h"

void Watch::act(Session& sess){
    std::string input = sess.getInput();
    input = input.substr(6, input.size());
    std::string watchinput = input.substr(0, input.size());
    long watchID = atol(watchinput.c_str());
    std::vector<Watchable*> content = sess.getContent();
    Watchable* toWatch =((content).at(watchID));
    std::cout << "Watching " << toWatch->stringClone();
    sess.getActiveUser()->addToHistory(toWatch);
    Watchable* next = sess.getActiveUser()->getRecommendation(sess);
    std::cout << " We recommend watching " << next->stringClone() << ", continue watching? [y/n]" << endl;
    string nextinput="";
    getline(cin, nextinput);
  if (nextinput == "y"){
        sess.setInput("watch" + to_string(next->getID()));
        Watch(sess);
    }
    }
std::string Watch::toString() const{
    return "hi";
}
BaseAction* Watch::clone(){

}