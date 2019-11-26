
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../include/User.h"
#include "../include/Watchable.h"
#include "../include/Session.h"
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

GenreRecommenderUser::GenreRecommenderUser(std::string &name) : User(name),genre(),maxGenre("default",0){
    setRec("gen");

}

GenreRecommenderUser::GenreRecommenderUser(GenreRecommenderUser &other) : User(other), genre(other.getGenre){}

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    for (vector<Watchable *>::iterator it = s.getContent().begin();it != s.getContent().end(); ++it)
        {// content  list
        if(!findInHistory(*it))
            if (find((*it)->getTags().begin(), (*it)->getTags().end(), maxGenre.first) !=  (*it)->getTags().end())
                return (*it);
            }

    findNextGenre();
    return getRecommendation(s);

    }


User *GenreRecommenderUser::clone() {
    return new GenreRecommenderUser(*this);
}
void GenreRecommenderUser::findNextGenre() {
    genre.at(maxGenre.first)=-1;
    maxGenre.second=-1;
    for (unordered_map<string,int >::iterator it = genre.begin(); it != genre.end(); ++it) {
        if (maxGenre.second == (*it).second) {// if have the same time of appearance as max put with lex order
            if (maxGenre.first > (*it).first) {
                maxGenre.first = (*it).first;
                maxGenre.second = (*it).second;
            }
            else if(maxGenre.second <(*it).second){
                    maxGenre.first = (*it).first;
                    maxGenre.second=(*it).second;
                }
        }
     }
    }

void GenreRecommenderUser::addToHistory(Watchable* w) {
    vector<string> temp = w->getTags();
    for (std::vector<string>::iterator it = temp.begin(); it != temp.end(); ++it) {
        unordered_map<string,int>::const_iterator got = genre.find (*it);// check if genre already exist
        if(  got == genre.end() ) {// if no exist
            genre.insert(make_pair(*it, 1));
            history.push_back(w);// add to history
            if(maxGenre.second<1) {
                maxGenre.first = *it;
                maxGenre.second = 1;
            }

        }
        else {//exist in genre history
            genre[*it]++;
            history.push_back(w);// add to history watch
            if(maxGenre.second==genre[*it]) {// if have the same time of appearance as max put with lex order
                if(maxGenre.first>*it) {
                    maxGenre.first = *it;
                    maxGenre.second = genre[*it];
                }

            }
            if(genre[*it]>maxGenre.second) {// time of appearance is larg than max
                maxGenre.first = *it;
                maxGenre.second=genre[*it];
            }

        }

    }
}

bool GenreRecommenderUser::findInHistory(Watchable * temp) {
    for (vector<Watchable *>::iterator it = history.begin(); it != history.end(); ++it) {
        if ((*it)->getID()==temp->getID())// why???
            return true;
    }
    return false;












