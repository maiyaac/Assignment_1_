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


 string Watchable:: toString() const {// virtual
     string s="";
     for (vector<string>::const_iterator it = tags.begin(); it != tags.end(); it++)
         s=s+(*it)+",";

    cout<<id<<". "<<length<<" minutes"<<"["<<s.substr(0,s.length()-1)<<"]";
}

