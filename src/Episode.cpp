#include <string>
#include <vector>
#include "../include/Watchable.h"
#include <iostream>
using namespace std;


/*Episode::Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags): Watchable(id,length,tags), seriesName(seriesName),season(season),episode(episode){};

std::string Episode::toString() const{
    string s = "[";
    for (vector<string>::const_iterator it = this->getTags().begin(); it != this->getTags().end(); it++)
            s = s + (*it) + ", ";
    cout << this->getID() << ". " << seriesName << " " << this->getLength() << " minutes " << "S" << season << "E" << episode << " " << s.substr(0, s.length()-2) << "]" << endl;
}

//Watchable* Watchable::getNextWatchable(Session&) const
 */




