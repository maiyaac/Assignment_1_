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

LengthRecommenderUser::LengthRecommenderUser(std::string &name) : User(name),recHistory() {

}

User *LengthRecommenderUser::clone() {
    return new LengthRecommenderUser(*this);
}


Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    int avgL=getavgL();
    Watchable* NextWatchable=getNextWatchable(s,avgL);
    recHistory.push_back(NextWatchable);
    return NextWatchable;
}

int LengthRecommenderUser::getavgL() {
    long sum=0;

    for (vector<Watchable*>::iterator it = history.begin() ; it != history.end(); ++it)   {
        Watchable* temp=*it;
        sum=sum+(temp->getLength());// whattttttt
    }
    return sum/history.size();

}

Watchable *LengthRecommenderUser::getNextWatchable(Session &s,int avgL) {
    Watchable* best = s.getContent().front();
    bool isFull=false;
    int min =abs( best->getLength()-avgL);

    for (vector<Watchable *>::iterator it = s.getContent().begin(); it != s.getContent().end(); ++it) {
        Watchable* temp=*it;//why????
    if (abs(temp->getLength() - avgL) < min)
        if(!findInHistory(temp)&!findInRecHistory())
            best = *it;// operator = in watchable
}
    if(best->getID()==-1) {
        clear(recHistory);
        best = getNextWatchable(s, avgL);
    }
    return best;
}

bool LengthRecommenderUser::findInHistory(Watchable * temp) {
    for (vector<Watchable *>::iterator it = history.begin(); it != history.end(); ++it) {
        Watchable* temp1=*it;//why????
        if (temp1->getID()==temp->getID())// why???
            return true;
    }
    return false;


}
bool LengthRecommenderUser::findInRecHistory(Watchable *temp) {
    if(isFull())
    for (vector<Watchable *>::iterator it = recHistory.begin(); it != recHistory.end(); ++it) {
        Watchable* temp1=*it;//why????
        if (temp1->getID()==temp->getID())// why???
            return true;
    }
    return false;
}

void LengthRecommenderUser::clear(vector<Watchable*> v){
    for (vector<Watchable *>::iterator it = recHistory.begin(); it != recHistory.end(); ++it) {
        delete(*it);
    }


    }










