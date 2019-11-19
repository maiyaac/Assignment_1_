#include <vector>
#include <unordered_map>
#include <string>
#include "../include/Action.h"
#include "../include/Session.h"
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include <fstream>

using json = nlohmann::json;



  /*  Session::Session(const std::string &configFilePath) {
        std::ifstream i("../config1.json");
        json j;
        i >> j;
        //movies
        for (int i = 0; i < j.size(); i++) {
            long id = i;
            const std::string &name = j["movies"][i]["name"];
            int length = j["movies"][i]["length"];
            const std::vector<std::string> &tags = j["movies"][i]["tags"];
            content.push_back(new Movie(i, name, length, tags));

        }
    }*/
  Session::Session(const std::string &configFilePath) {}

    Session::~Session() {

    }

void Session::start() {
            std::cout << "hello";
        }





