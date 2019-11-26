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
RerunRecommenderUser::RerunRecommenderUser( string& name):User(name) ,lastId(1){
    setRec("rer");
}
RerunRecommenderUser::RerunRecommenderUser(RerunRecommenderUser &other) : User(other) {}

Watchable *RerunRecommenderUser::getRecommendation(Session &s) {
    Watchable* nextWatchable= history[lastId];
    lastId=(lastId+1)%history.size();
    return nextWatchable;
}

User *RerunRecommenderUser::clone() {
    return new RerunRecommenderUser(*this);
}



