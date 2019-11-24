#include <string>
#include <vector>
#include "../include/Watchable.h"
#include <iostream>
#include "../include/Session.h"
using namespace std;


Episode::Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags): Watchable(id,length,tags), seriesName(seriesName),season(season),episode(episode){
};

std::string Episode::toString() const{
    string s = "[";
    for (vector<string>::const_iterator it = this->getTags().begin(); it != this->getTags().end(); it++)
        s = s + *it + ", ";
    cout << this->getID() << ". " << seriesName << " " << this->getLength() << " minutes " << "S" << season << "E" << episode << " " << s.substr(0, s.length()-2) << "]" << endl;
}

Episode::Episode(const Episode &other): Watchable(other.getID(),other.getLength(),other.getTags()), seriesName(other.getSeriesName()), season(other.getSeason()), episode(other.getEpisode()){}

Episode::~Episode(){}

//Episode::Episode (Episode &&other): Watchable(other.getID(),(other.getLength()),other.getTags()), seriesName(other.getSeriesName()), season(other.getSeason()), episode(other.getEpisode()){

}
Episode& Episode::operator=(const Episode& other){
    if (this!=&other){
        copy(other);
    }
    return *this;
}
/*const Episode& Episode::operator=(const Episode&& other){
    if (this!=&other){
    }

}*/

void Episode::setSeriesName(string other){
    seriesName = other;
}
void Episode::setSeason(int other){
    season = other;
}
void Episode::setEpisode(int other){
    episode = other;
}
string Episode::getSeriesName() const {
    return seriesName;
}
int Episode::getSeason() const{
    return season;
}
int Episode::getEpisode() const {
    return episode;
}
void Episode::copy(const Episode& other){
    this->setId(other.getID());
    this->setLength(other.getLength());
    this->setTags(other.getTags());
    this->setSeason(other.getSeason());
    this->setEpisode(other.getEpisode());
    this->setSeriesName(other.getSeriesName());
}

Watchable* Episode::getNextWatchable(Session& s) const{

    vector<Watchable*> next = s.getContent();





}