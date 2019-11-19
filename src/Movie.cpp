//
// Created by maiy@wincs.cs.bgu.ac.il on 19/11/2019.
//
#include<iostream>
#include "../include/Watchable.h"
#include <string>
#include <vector>

Movie::Movie(long id, const std::string& name, int length, const std::vector<std::string>& tags) : Watchable(id, length, tags), name(name){}
virtual std::string Movie::toString(bool print_full=false) const{
    std::cout << id << name << length << tags;
}
