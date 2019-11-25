
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"

#include "../include/Session.h"
User::User( std::string &name) : name(name) {}
Watchable* User:: getRecommendation(Session& s){
    return nullptr;
}
std::string User::getName() const{
   return nullptr;
}

std::vector<Watchable*> User:: get_history() const{
    std::vector<Watchable*> content;
     return content;
}