#include <vector>
#include <unordered_map>
#include <string>
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/User.h"
#include <fstream>
using namespace std;
using json = nlohmann::json;


Session::Session(const std::string &configFilePath):content(),actionsLog (),userMap(),activeUser(),terminate(false),input(){
    convertJson();
    string *s= new string ("ddefault"); //need to delete
    User *default1 = new LengthRecommenderUser(*s); //need to delete
    userMap.insert(make_pair("default",default1));
    setActiveUser(default1);
}
Session::Session(Session &other){
    copy(other);
}

Session::Session(Session&& other) : content(move(other.getContent())),actionsLog(move(other.getActionsLog())),userMap(move(other.getUserMap())),
activeUser(move(other.getActiveUser())),input(move(other.getInput())),terminate(false){}

Session& Session ::operator=(const Session& other){
    if(&other==this)
        return *this;
    clear();
    copy(other);
    return *this;
}

Session& Session ::operator=(const Session&& other) {
    if(&other==this)
        return *this;
    clear();
    move(other.getContent());
    move(other.getActionsLog());
    move(other.getUserMap());
    move(other.getActiveUser());
    move(other.getInput());
    terminate=false;
    return *this;
}

void Session::clear(){
    content.clear();
    actionsLog.clear();
    userMap.clear();
    activeUser = nullptr;
    input = "";
}

void Session::copy(const Session &other){
    for (int i=0; i<other.getContent().size()-1; i++){
        content.push_back((other.getContent()[i]->clone()));
        }
    for (int i=0; i<other.getActionsLog().size()-1; i++){
        actionsLog.push_back((other.getActionsLog()[i]->clone()));
}
    for (unordered_map<string,User*>::const_iterator it=other.getUserMap().begin(); it!=other.getUserMap().end(); ++it){
           userMap.insert(make_pair(it->first,(it->second)->clone()));//clone()
    }
    activeUser = other.getActiveUser();
    terminate = false;
    input = other.getInput(); //necessary?
}


Session::~Session() {}






void Session::start() {
    std::cout << "SPLFlix is now on!" << endl;
    while(!terminate){
        getline(cin,input);
        string action=input.substr(0,input.find(" "));
        if(action.compare("createuser")==0){
            cout<<"hello";
            CreateUser *newuser = new CreateUser;
            newuser->act(*this);
        }
        else if(action.compare("changeuser")==0){
            cout<<"hello";
            ChangeActiveUser *changeuser = new ChangeActiveUser;
            changeuser->act(*this);
        }
        else if(action.compare("deleteuser")==0){
            DeleteUser *deleteuser = new DeleteUser;
            deleteuser->act(*this);
        }
        else if(action.compare("dupuser")==0){
            DuplicateUser *dupuser = new DuplicateUser;
            dupuser->act(*this);
        }
        else if(action.compare("log")==0){
            PrintActionsLog *actionlog = new PrintActionsLog;
            actionlog->act(*this);
        }
        else if(action.compare("content")==0){
            PrintContentList *printcontent = new PrintContentList;
            printcontent->act(*this);
        }
        else if(action.compare("watchhist")==0){
            PrintWatchHistory *printhistory = new PrintWatchHistory;
            printhistory->act(*this);
        }
        else if(action.compare("watch")==0){ //still need to make class
            Watch *watch = new Watch;
            watch->act(*this);
        }
        else if(action.compare("Exit")==0){//need to check what to implement here.. terminate??
            terminate=true;
        }
        else{
            cout << "Invalid input";
        }
    }
}

std::vector<Watchable*> Session::getContent() const{
    return content;
}

string Session::getInput()const{
    return input;
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
    actionsLog.push_back(action->clone());
}

void Session::addUser(string name, string rec)  {
    if (rec=="len"){
        LengthRecommenderUser *newUser = new LengthRecommenderUser(name);
        userMap.insert(make_pair(name,newUser));
    }
//    if (rec=="rer"){
//        RerunRecommenderUser *newUser = new RerunRecommenderUser(name);
//        userMap.insert(make_pair(name, newUser));
//    }
//    if (rec=="gen"){
//        GenreRecommenderUser *newUser = new GenreRecommenderUser(name);
//        userMap.insert(make_pair(name, newUser));
//    }
}
void Session::duplicateUser(string name){ //need to make copy constructor for each and also getrec and setname functions in user
//    string rec = activeUser.getRec();
//    if (rec=="len"){
//        LengthRecommenderUser *newUser = new LengthRecommenderUser(activeUser);
//        newUser->setName(name);
//    }
//    if (rec=="rer"){
//        RerunRecommenderUser *newUser = new RerunRecommenderUser(activeUser);
//        newUser->setName(name);
//    }
//    if (rec=="gen") {
//        GenreRecommenderUser *newUser = new GenreRecommenderUser(activeUser);
//        newUser->setName(name);
//    }

}
void deleteUser(User *user){
    delete(user);
}

void Session::convertJson(){

    std::ifstream i("../config1.json");
    json j;
    i >> j;

    //movies
    long id=0 ;
    for (int i = 0; i < j["movies"].size(); i++) {
        id++;
        const std::string &name = j["movies"][i]["name"];
        int length = j["movies"][i]["length"];
        const std::vector<string> &tags = j["movies"][i]["tags"];
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
                id++;

            }
        }
    }

}