//
// Created by edensal@wincs.cs.bgu.ac.il on 24/11/2019.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"

using namespace std;
RerunRecommenderUser::RerunRecommenderUser( string& name):User(name){}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    return nullptr;
}

User *RerunRecommenderUser::clone() {
    return nullptr;
}

