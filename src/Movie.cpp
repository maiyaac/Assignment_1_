#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>
using namespace std;

Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) : Watchable(id, length, tags), name(name){}
Movie::~Movie() {}

Movie::Movie ( const Movie &other): Watchable(other.getID(), other.getLength(),other.getTags()), name(other.getName()){//copy constructor

    Movie& Movie::operator=(const Movie &other) {//assignment operator =
        if (this == &other) {
            return *this;
            else {
                copy(other);
                return *this;
            }
        }

        string Movie::toString() const {//virtual
            string s = "";
            for (vector<string>::const_iterator it = getTags().begin(); it != getTags().end(); it++)
                s = s + (*it) + ",";
            cout << this->getID() << name << this->getLength() << "[" << s.substr(0, s.length() - 1) << "]";

        }
        void copy(const Movie *other) {
            this->setId(other->getID());
            this->setLength(other->getLength());
            this->setTags(other->getTags());
            name = other->getName();
        }
        string Movie::getName() const {
            return this->name;
        }


        string toString() {
            string s = "";
            for (vector<string>::const_iterator it = getTags().begin(); it != getTags().end(); it++)
                s = s + (*it) + ",";
            cout << this.getID() << name << this->getLength() << "[" << s.substr(0, s.length() - 1) << "]";
        }
