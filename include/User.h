#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <utility>
class Watchable;
class Session;
using namespace std;

class User{
public:
    User(string &name);
    virtual Watchable* getRecommendation(Session& s) = 0;
    std::string getName() const;
    std::vector<Watchable*> get_history() const;
    virtual User* clone()=0;
    virtual void addToHistory(Watchable*);
    void setRec(string);
    string getRec();
    void setName(string);
protected:
    std::vector<Watchable*> history;
private:
    std::string name;
    string rec;

};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser(std::string &name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User * clone() ;
    int getavgL() ;
    Watchable* getNextWatchable(Session &s,int avgL) ;
    bool findInHistory(Watchable * temp) ;

private:


};

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser(std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User * clone() ;

private:
    long lastId;
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser(std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User * clone() ;
    virtual void addToHistory(Watchable*);
    void findNextGenre();
    bool findInHistory(Watchable *temp);

private:
   unordered_map<string, int> genre;
   pair<string,int > maxGenre;


};

#endif
