//
// Created by maiy@wincs.cs.bgu.ac.il on 19/11/2019.
//

#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>
using namespace std;

Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) : Watchable(id, length, tags), name(name){}
Movie::~Movie() {}

Movie::Movie ( const Movie &other): Watchable(other.getID(), other.getLength(),other.getTags()), name(name){//copy constructor
        if(this!=&other)
        copy(&other);}
Movie::Movie (  Movie &&other) :Watchable(std::move(other.getID()), std::move(other.getLength()),  std::move(other.getTags())), std::move(other.name){//move constructor
    this->
    &other=nullptr;
}
Movie& Movie::operator=(const Movie &other) {//assignment operator =
    if (this == &other) {
        return *this;
        else {
            copy(other);
            return *this;
        }
    }
}

    void  copy (const Movie *other){
        this->setId(other->getID());
        this->setLength(other->getLength());
        this->setTags(other->getTags());
        name=other->getName();
    }
    string Movie::getName() const
    {
        return this->name;
    }

    {
        string toString() {
            string s="";
            for (vector<string>::const_iterator it = getTags().begin(); it !=  getTags().end(); it++)
                s=s+(*it)+",";
            cout<<this.getID()<<name<< this->getLength()<<"["<<s.substr(0,s.length()-1)<<"]";
        }