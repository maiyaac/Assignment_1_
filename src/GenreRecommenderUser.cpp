
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

Watchable *GenreRecommenderUser::getRecommendation(Session &s) {
    for (vector<Watchable *>::iterator it = s.getContent().begin();it != s.getContent().end(); ++it)
        {// content  list
            Watchable *temp = *it;
            if (find(temp->getTags().begin(), temp->getTags().end(), maxGenre.first) !=  temp->getTags().end())
                return temp;
            }

    findNextGenre();
    return getRecommendation(s);

    }


User *GenreRecommenderUser::clone() {
    return new GenreRecommenderUser(*this);
}
void GenreRecommenderUser::findNextGenre() {
    genre[maxGenre.first]=-1;
    maxGenre.second=-1;
    for (unordered_map<string,int >::iterator it = genre.begin(); it != genre.end(); ++it) {
        pair<string,int >temp=*it;
        if (maxGenre.second == temp.second) {// if have the same time of appearance as max put with lex order
            if (maxGenre.first > temp.first) {
                maxGenre.first = temp.first;
                maxGenre.second = temp.second;
            }
            else if(maxGenre.second <temp.second){
                    maxGenre.first = temp.first;
                    maxGenre.second=temp.second;
                }

        }
     }
    }

void GenreRecommenderUser::addToHistory(Watchable* w) {
    vector<string> temp = w->getTags();
    for (std::vector<string>::iterator it = temp.begin(); it != temp.end(); ++it) {
        string s = *it;
        unordered_map<string,int>::const_iterator got = genre.find (s);// check if genre already exist
        if(  got == genre.end() ) {// if no exist
            genre.insert(make_pair(s, 1));
            history.push_back(w);// add to history
            if(maxGenre.second<1) {
                maxGenre.first = s;
                maxGenre.second = 1;
            }

        }
        else {//exist in genre history
            genre[s]++;
            history.push_back(w);// add to history watch
            if(maxGenre.second==genre[s]) {// if have the same time of appearance as max put with lex order
                if(maxGenre.first>s) {
                    maxGenre.first = s;
                    maxGenre.second = genre[s];
                }

            }
            if(genre[s]>maxGenre.second) {// time of appearance is larg than max
                maxGenre.first = s;
                maxGenre.second=genre[s];
            }

        }

    }
}











