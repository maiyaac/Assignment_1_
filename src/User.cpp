
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"

#include "../include/Session.h"
using namespace std;
User::User( string &name) : name(name) ,rec(""){}

User::User(User &other) {
    name=other.name;
    rec=other.rec;
}

std::string User::getName() const{
   return name;
}

vector<Watchable*> User:: get_history() const{
   return history;
}

void User::addToHistory(Watchable * s) {
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