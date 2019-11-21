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
    int getLength() const;
    vector<string> getTags() const;
    long getID() const;
    void setTags(vector<string> other);
    void setLength(int other);
    void setId(long other);


private:
    const long id;
    int length;
    std::vector<std::string> tags;
};

class Movie : public Watchable{
public:
    Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags);
    virtual~Movie();
    Movie(const Movie &other);
    Movie(Movie &&other);
    Movie& operator=(const Movie &other);
    Movie& operator=(Movie &&other);
    virtual std::string toString() const;
    void copy (const Movie &other) const;
    void  clear () {
    string getName() const;
    virtual Watchable* getNextWatchable(Session&) const;

private:
    std::string name;

    void copy(const Movie *other);
};


class Episode: public Watchable{
public:
    Episode(long id, const std::string& seriesName,int length, int season, int episode ,const std::vector<std::string>& tags);
    virtual std::string toString(bool print_full=false) const;
    virtual Watchable* getNextWatchable(Session&) const;
private:
    std::string seriesName;
    int season;
    int episode;
    long nextEpisodeId;
};

#endif
