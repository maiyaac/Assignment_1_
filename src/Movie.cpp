//
// Created by maiy@wincs.cs.bgu.ac.il on 19/11/2019.
//
#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>
using namespace std;

Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) :Watchable(id, length, tags), name(name){}

string Movie::toString() const{//virtual
    string s="";
    for (vector<string>::const_iterator it = getTags().begin(); it !=  getTags().end(); it++)
        s=s+(*it)+",";
    cout<<this->getID()<<name<< this->getLength()<<"["<<s.substr(0,s.length()-1)<<"]";
}

Watchable* Movie::getNextWatchable(Session&) const{}