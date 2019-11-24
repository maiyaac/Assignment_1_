#include <string>
#include <vector>
#include <iostream>
#include "../include/Watchable.h"
using namespace std;

Watchable::Watchable(long id, int length, const vector<string>& tags) : id(id),length(length),tags(tags){}

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
