//
// Created by edensal@wincs.cs.bgu.ac.il on 23/11/2019.
//

#include <vector>
#include <string>
#include <unordered_set>
#include "../include/User.h"
using namespace std;

User::User(string &name) : name(name),history() {}

std::string User::getName() const {
    return name;
}

std::vector<Watchable *> User::get_history() const {
    return std::vector<Watchable *>();
}

void User::addContent(Watchable * content ) {
    history.push_back(content);
}

