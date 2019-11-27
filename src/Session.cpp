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
    delete(s);

}
Session::Session(Session &other){
    copy(other);
}
Session::~Session( ) {
    clear();
}

Session::Session(Session&& other) : content(),actionsLog (),userMap(),activeUser(),terminate(false),input(){
    content=*(other.getContent());
    actionsLog=other.getActionsLog();
    userMap=other.getUserMap();
    activeUser=other.getActiveUser();

    for( auto &item : other.content)
    item= nullptr;
    for( auto &item : other.userMap)
        item.second= nullptr;
    other.activeUser= nullptr;
    for( auto &item : other.actionsLog)
        item= nullptr;


}

Session& Session ::operator=( Session& other){
    if(&other==this)
        return *this;
    clear();
    copy(other);
    return *this;
}

Session& Session ::operator=( Session&& other) {
    if(&other==this)
        return *this;
    clear();
    content=*(other.getContent());
    actionsLog=other.getActionsLog();
    userMap=other.getUserMap();
    activeUser=other.getActiveUser();
    terminate=other.terminate;
    return *this;
}

void Session::clear(){

    for( auto &item : content)
        delete(item);
    for( auto &item : userMap)
        delete(item.second);
    for( auto &item : actionsLog)
        delete(item);
    delete(activeUser);
    input = "";


}
void Session::copy( Session &other){
    for (int i=0; i<other.getContent()->size()-1; i++){
        content.push_back((((*other.getContent())[i])->clone()));
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









void Session::start() {
    std::cout << "SPLFlix is now on!" << endl;
    while(!terminate){
        getline(cin,input);
        string action;
        if(input.find(" "))
              action=input.substr(0,input.find(" "));
        else {
            action = input;
        }

        if(action.compare("createuser")==0&input.size()>action.size()){
            cout<<"hello";
            CreateUser *newuser = new CreateUser;
            newuser->act(*this);
            delete(newuser);

        }
        else if(action.compare("changeuser")==0&input.size()>action.size()){
            cout<<"hello";
            ChangeActiveUser *changeuser = new ChangeActiveUser;
            changeuser->act(*this);
            delete(changeuser);

        }
        else if(action.compare("deleteuser")==0&input.size()>action.size()){
            DeleteUser *deleteuser = new DeleteUser;
            deleteuser->act(*this);
            delete(deleteuser);



        }
        else if(action.compare("dupuser")==0&input.size()>action.size()){
            DuplicateUser *dupuser = new DuplicateUser;
            dupuser->act(*this);
            delete(dupuser);

        }
        else if(action.compare("log")==0){
            PrintActionsLog *actionlog = new PrintActionsLog;
            actionlog->act(*this);
            delete(actionlog);

        }
        else if(action.compare("content")==0){
            PrintContentList *printcontent = new PrintContentList;
            printcontent->act(*this);
            delete(printcontent);

        }
        else if(action.compare("watchhist")==0){
            PrintWatchHistory *printhistory = new PrintWatchHistory;
            printhistory->act(*this);
            delete(printhistory);

        }
        else if(action.compare("watch")==0&input.size()>action.size()){ //still need to make class
            Watch *watch = new Watch;
            watch->act(*this);
            delete(watch);
        }
        else if(action.compare("exit")==0){//need to check what to implement here.. terminate??
            terminate=true;
        }

        else{
            cout << "Invalid input";
        }
    }
}

std::vector<Watchable*>* Session::getContent() {
    return &content;
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
    if (rec=="rer"){
        RerunRecommenderUser *newUser = new RerunRecommenderUser(name);
        userMap.insert(make_pair(name, newUser));
    }
    if (rec=="gen"){
        GenreRecommenderUser *newUser = new GenreRecommenderUser(name);
        userMap.insert(make_pair(name, newUser));
    }
}
void Session::duplicateUser(string myname, string othername){
        std::unordered_map<std::string, User*>::const_iterator it;
        it = userMap.find(othername);
        User *newUser = it->second->clone();
        newUser->setName(myname);
        userMap.insert(make_pair(myname,newUser));
}
void deleteUser(User *user){
    delete(user);
}

void Session::deleteUserFromMap(string name){
    userMap.erase(name);
}

void Session::convertJson(){

    std::ifstream i("../config1.json");
    json j;
    i >> j;

    //movies
    long id=0 ;
    for (int i = 0; i < j["movies"].size(); i++) {
        const std::string &name = j["movies"][i]["name"];
        int length = j["movies"][i]["length"];
        const std::vector<string> &tags = j["movies"][i]["tags"];
        content.push_back(new Movie(i, name, length, tags));
        id++;
    }
    //tv shows
    id=id-1;
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
        id=id-1;
    }

}

void Session::setInput(string s) {
this->input=s;
}

void Session::watchN(){
    Watch *watch = new Watch;
    watch->act(*this);
    delete(watch);
}