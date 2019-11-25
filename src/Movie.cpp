#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>
using namespace std;

Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) : Watchable(id, length, tags), name(name){}

Movie::~Movie(){
    delete(this);
}

string Movie::toString() const {
    string s = "";
    for (int i =0; i<getTags().size()-1; i++) {
        s = s + getTags().at(i) + ", ";
    }
    cout << this->getID() << name << this->getLength() << "[" << s.substr(0, s.length() - 1) << "]";
}

string Movie::getName() const {
    return this->name;
}

Watchable* Movie::getNextWatchable(Session&) const{
    return nullptr;
}

Watchable* Movie::clone(){
    return (new Movie(*this));
}
