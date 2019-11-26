
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
    for(int i=0;i<history.size();i++)
        sum=sum+(history.at(i)->getLength());// whattttttt
    return sum/history.size();

}

Watchable *LengthRecommenderUser::getNextWatchable(Session &s,int avgL) {
    Watchable* best=s.getContent().front();
    long min =INTMAX_MAX;
    for ( int i=0; i<s.getContent().size();i++){
   // for (vector<Watchable *>::const_iterator it = s.getContent().begin(); it != s.getContent().end(); ++it) {
      //  Watchable* temp=*it;
        if (abs((s.getContent().at(i))->getLength() - avgL) < min)
            if (!findInHistory(s.getContent().at(i))) {
                best = s.getContent().at(i);// operator = in watchable
                min = abs((s.getContent().at(i))->getLength() - avgL);
            }
    }
    return best;
}

bool LengthRecommenderUser::findInHistory(Watchable * temp) {
    for (vector<Watchable *>::iterator it = history.begin(); it != history.end(); ++it) {
        Watchable* tempT=*it;
        if ((tempT)->getID()==temp->getID())// why???
            return true;
    }
    return false;


}









