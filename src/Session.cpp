#include <vector>
#include <unordered_map>
#include <string>
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include <fstream>
using namespace std;
using json = nlohmann::json;


Session::Session(const std::string &configFilePath):content(),actionsLog (),userMap(),activeUser(){
    convertJson();
}

Session::~Session(){}

void Session::start() {
    std::cout << "SPLFlix is now on!" << endl;

}

std::vector<Watchable*> Session::getContent() const{

    return content;
}

const vector<BaseAction *> &Session::getActionsLog() const {
    return actionsLog;
}

const unordered_map<std::string, User *> &Session::getUserMap() const {
    return userMap;
}

User *Session::getActiveUser() const {
    return activeUser;
}

void Session::setContent(const vector<Watchable *> &content) {
    Session::content = content;
}

void Session::setActionsLog(const vector<BaseAction *> &actionsLog) {
    Session::actionsLog = actionsLog;
}

void Session::setUserMap(const unordered_map<std::string, User *> &userMap) {
    Session::userMap = userMap;
}

void Session::setActiveUser(User *activeUser) {
    Session::activeUser = activeUser;
}
void Session::addActionLog(BaseAction *const action) {
    actionsLog.push_back(action);
}

void Session::addUser(string name , User * user) const {

    userMap.insert({name,user});
}


}




void Session::convertJson(){

    std::ifstream i("../config1.json");
    json j;
    i >> j;

    //movies
    long id=0 ;
    for (int i = 0; i < j["movies"].size(); i++) {
        id++;
        //cout<<id<<". ";
        const std::string &name = j["movies"][i]["name"];
        // cout << name <<" ";
        int length = j["movies"][i]["length"];
        // cout << length<<" minutes ";
        const std::vector<string> &tags = j["movies"][i]["tags"];
        // string s="[";
        //   for (vector<string>::const_iterator it = tags.begin(); it !=  tags.end(); it++)
        //     s=s+(*it)+", ";
        //  cout <<s.substr(0,s.length()-2)<<"]"<< endl;
        content.push_back(new Movie(i, name, length, tags));
    }
    //tv shows
    for (int i = 0; i < j["tv_series"].size(); i++) {
        id++;
        const std::string &seriesName = j["tv_series"][i]["name"];
        int length = j["tv_series"][i]["episode_length"];
        const std::vector<int> &seasons = j["tv_series"][i]["seasons"];
        int season = 0;
        const std::vector<std::string> &tags = j["tv_series"][i]["tags"];
        for (vector<int>::const_iterator it = seasons.begin(); it != seasons.end(); it++) {//
            season++;
            for (int episode = 1; episode <= *it; episode++) {
                content.push_back(new Episode( id,  seriesName, length,  season,  episode , tags));//
                //cout << id << ". ";
                // cout << seriesName << " ";
                // cout << length << " minutes ";
                // cout << "S" << season << "E" << episode << " ";
                // string s = "[";
                // for (vector<string>::const_iterator it = tags.begin(); it != tags.end(); it++)
                //    s = s + (*it) + ", ";
                //  cout << s.substr(0, s.length() - 2) << "]" << endl;
                id++;

            }
        }
    }

}



