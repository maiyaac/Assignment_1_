#include <vector>
#include <unordered_map>
#include <string>
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include <fstream>

using json = nlohmann::json;
std::vector<Watchable*> content;
std::vector<BaseAction*> actionsLog;
std::unordered_map<std::string,User*> userMap;
User* activeUser;


    Session::Session(const std::string &configFilePath):content(),actionsLog (),userMap(),activeUser(){

        std::ifstream i("../config1.json");
        json j;
        i >> j;
        //movies
        for (int i = 0; i < j.size(); i++) {
            long id = i;
            const std::string &name = j["movies"][i]["name"];
            cout << name;
            int length = j["movies"][i]["length"];
            cout << length;
            const std::vector<std::string> &tags = j["movies"][i]["tags"];
            string s="[";
            for (vector<string>::const_iterator it = tags.begin(); it !=  tags.end(); it++)
                s=s+(*it)+",";
            cout << s <<"]"<<endl;
          //  content.push_back(new Watchabl(i, length, tags));


        }
  }



    Session::~Session() {

    }

void Session::start() {
            std::cout << "hello";
        }





