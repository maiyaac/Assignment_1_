#include <string>
#include <vector>
#include "../include/Watchable.h"
#include <iostream>
#include "../include/Session.h"
using namespace std;


Episode::Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags): Watchable(id,length,tags), seriesName(seriesName),season(season),episode(episode){
};

Episode::~Episode(){
    delete(this);
}

std::string Episode::toString() const{
    string s = "[";
    for (int i =0; i<getTags().size()-1; i++) {
        s = s + getTags().at(i) + ", ";
    }
    cout << this->getID() << ". " << seriesName << " " << this->getLength() << " minutes " << "S" << season << "E" << episode << " " << s.substr(0, s.length()-2) << "]" << endl;
}

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
    this->setLength(other.getLength());
    this->setTags(other.getTags());
    this->setSeason(other.getSeason());
    this->setEpisode(other.getEpisode());
    this->setSeriesName(other.getSeriesName());
}

Watchable* Episode::getNextWatchable(Session& s) const{

    vector<Watchable*> next = s.getContent();

}

Watchable* Episode::clone(){
    return (new Episode(*this));
}





