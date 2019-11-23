#include <string>
#include <vector>
#include <iostream>
#include "../include/Watchable.h"
using namespace std;


Watchable::Watchable(long id, int length, const vector<string>& tags) : id(id),length(length),tags(tags){}

Watchable::Watchable( const Watchable &other): id(other.getID()), length(other.getLength()),tags(other.getTags()){}//copy constructor

Watchable& Watchable::operator=(const Watchable &other) {//assignment operator =
    if (this == &other) {
        return *this;
    copy(other);
    return *this;

    }
Watchable::copy (const Watchable *other){
    this.id=other->getID();
    this.length=other->getLength()
    this.tags=other->getTags()

}

long Watchable:: getID() const {
    return id ;
}
Watchable::~Watchable(){
}

int Watchable::getLength() const{
    return length ;
}
vector<string> Watchable::getTags() const{
    return tags ;
}

void Watchable::setId(long other) {
    id = other;
}
void Watchable::setLength(int other)   {
    length=other;
}
void Watchable::setTags(vector<string> other)   {
    tags=other;
}