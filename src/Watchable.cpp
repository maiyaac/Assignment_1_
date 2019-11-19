#include <string>
#include <vector>
#include "../include/Watchable.h"

Watchable::Watchable(long id, int length, const std::vector<std::string>& tags) : id(id),length(length),tags(tags){}
virtual std::string toString() const {

}
long getID(){
    return this->id;
}