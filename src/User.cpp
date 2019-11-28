
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"

#include "../include/Session.h"
using namespace std;
User::User( string &name) : name(name) ,rec(""){}

std::string User::getName() const{
   return name;
}
User::~User(){
    for(auto &item:history)
        item= nullptr;
    history.clear();
    //delete(name);// necessary ?


}
User::User(User &other):name(other.name), history(),rec(other.rec){
  for(auto &item:other.history)
      history.push_back(item);


}
vector<Watchable*>* User:: get_history() {
   return &history;
}

void User::addToHistory(Watchable* s) {
    history.push_back(s);

}

void User::setRec(string s) {
    rec=s;
}
string User::getRec() {
    return rec;
}
void User::setName(string s) {
    name=s;
}