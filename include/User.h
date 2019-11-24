#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
class Watchable;
class Session;

class User{
public:
    User(std::string& name);
    virtual Watchable* getRecommendation(Session& s) = 0;
    std::string getName() const;
    std::vector<Watchable*> get_history() const;
    void addContent(Watchable*);
    virtual User* clone()=0 ;
protected:
    std::vector<Watchable*> history;
private:
    std::string name;

};


class LengthRecommenderUser : public User {
public:
    LengthRecommenderUser( std::string& name);
    virtual Watchable* getRecommendation(Session& s);
    virtual User* clone() ;
    int getavgL();
    Watchable* getNextWatchable(Session& s, int avgL);
    bool findT(Watchable*);

private:
};

class RerunRecommenderUser : public User {
public:
    RerunRecommenderUser( std::string& name);
    virtual Watchable* getRecommendation(Session& s);
private:
};

class GenreRecommenderUser : public User {
public:
    GenreRecommenderUser( std::string& name);
    virtual Watchable* getRecommendation(Session& s);
private:
};

#endif
