#ifndef WATCHABLE_H_
#define WATCHABLE_H_

#include <string>
#include <vector>


class Session;
using namespace std;
class Watchable{

public:
    Watchable();
    Watchable(long id, int length, const std::vector<std::string>& tags);
    virtual ~Watchable();
    virtual std::string toString() const = 0;
    virtual Watchable* getNextWatchable(Session&) const = 0;
    virtual Watchable* clone() = 0;
    virtual string stringClone() = 0;
    int getLength() const;
    vector<string> getTags() const;
    long getID() const;
    void setTags(vector<string> other);
    void setLength(int other);
    virtual std::string getName() const;


private:
    const long id;
    int length;
    std::vector<std::string> tags;
    std::string name;
};

class Movie : public Watchable{
public:
    Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags);
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session&) const;
    virtual string getName() const;
    virtual Watchable* clone();
    virtual ~Movie();
    virtual string stringClone();
private:
    std::string name;
};

class Episode: public Watchable{
public:
    Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags);
    virtual ~Episode();
    virtual std::string toString() const;
    virtual Watchable* getNextWatchable(Session&) const;
    void copy(const Episode&);
    void setSeriesName(string other);
    void setSeason(int other);
    void setEpisode(int other);
    virtual string getName() const ;
    int getSeason() const;
    int getEpisode() const;
    virtual Watchable* clone();
    virtual string stringClone();

private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;


};

#endif
