
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"

using namespace std;

LengthRecommenderUser::LengthRecommenderUser(std::string &name) : User(name){
    setRec("len");

}
LengthRecommenderUser::LengthRecommenderUser(LengthRecommenderUser &other) : User(other) {}

User *LengthRecommenderUser::clone() {
    return new LengthRecommenderUser(*this);
}


Watchable *LengthRecommenderUser::getRecommendation(Session &s) {
    int avgL=getavgL();
    Watchable* NextWatchable=getNextWatchable(s,avgL);
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
    Watchable* best=s.getContent().front();
    int min =INTMAX_MAX;
    for (vector<Watchable *>::const_iterator it = s.getContent().begin(); it != s.getContent().end(); ++it) {
        if (abs((*it)->getLength() - avgL) < min)
            if (!findInHistory(*it))
                best = *it;// operator = in watchable
    }
    return best;
}

bool LengthRecommenderUser::findInHistory(Watchable * temp) {
    for (vector<Watchable *>::iterator it = history.begin(); it != history.end(); ++it) {
        if ((*it)->getID()==temp->getID())// why???
            return true;
    }
    return false;


}









