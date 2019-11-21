//
// Created by maiy@wincs.cs.bgu.ac.il on 19/11/2019.
//

#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>
using namespace std;

    Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) :new Watchable(id, length, tags), name(name){}
    Movie::~Movie() {}
    Movie::Movie ( const Movie &other){//copy constructor
         if(this!=&other)
            copy(&other);}
    Movie::Movie (  Movie &&other){//move constructor
        copy(&other);
        &other=nullptr;
    }
   Movie& Movie:: operator=(const Movie &other){//assignment operator =
        if(this!=&other)
            clear();// not sure that necessary
            copy(&other);
    }
    Movie& Movie:: operator=(Movie &&other){ //move assignment operator =
        if(this!=&other) {
            clear();
            copy(&other);
            &other= nullptr ;
        }}



    void Movie:: copy (const Movie *other){
    this->setId(other->getID());
    this->setLength(other->getLength());
    this->setTags(other->getTags());
    this->name=other->getName();
}
void Movie:: clear () {
}


string Movie::getName() const
{
    return name;
}



// Copy Assignment

{




     string toString() {
        string s="";
        for (vector<string>::const_iterator it = getTags().begin(); it !=  getTags().end(); it++)
            s=s+(*it)+",";
        cout<<this.getID()<<name<< this->getLength()<<"["<<s.substr(0,s.length()-1)<<"]";
    }


