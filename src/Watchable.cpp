    #include <string>
    #include <vector>
    #include <iostream>
    #include "../include/Watchable.h"
    using namespace std;




    Watchable::Watchable(long id, int length, const vector<string>& tags) : id(id),length(length),tags(tags){}

    }
    Watchable::~Watchable(){
    }
    long Watchable:: getID() const {
        return id ;
   void Watchable::setId(long other)   {
        this.id=other
    }
    int Watchable:: getLength() const{
        return length ;
    }
   void Watchable:: setLength(int other)   {
        this.length=other
    }
    vector<string> Watchable::g etTags() const{
        return tags ;
    }
    void Watchable::setTags(vector<string> other)   {
    this.tags=other;
    }


     string Watchable:: toString() const {// virtual
         string s="";
         for (vector<string>::const_iterator it = tags.begin(); it != tags.end(); it++)
             s=s+(*it)+",";

        cout<<id<<". "<<length<<" minutes"<<"["<<s.substr(0,s.length()-1)<<"]";
    }

