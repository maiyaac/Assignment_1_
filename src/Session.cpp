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
        long id=0 ;
        for (int i = 0; i < j["movies"].size(); i++) {

            id++;
            //cout<<id<<". ";
            const std::string &name = j["movies"][i]["name"];
            // cout << name <<" ";
            int length = j["movies"][i]["length"];
            // cout << length<<" minutes ";
            const std::vector<string> &tags = j["movies"][i]["tags"];
            // string s="[";
            //   for (vector<string>::const_iterator it = tags.begin(); it !=  tags.end(); it++)
            //     s=s+(*it)+", ";
            //  cout <<s.substr(0,s.length()-2)<<"]"<< endl;
           // content.push_back(new Movie(i, name, length, tags));
        }

          for (int i = 0; i < j["tv_series"].size(); i++) {
              id++;
              const std::string &seriesName = j["tv_series"][i]["name"];
              int length = j["tv_series"][i]["episode_length"];
              const std::vector<int> &seasons = j["tv_series"][i]["seasons"];
              int season = 0;
              const std::vector<std::string> &tags = j["tv_series"][i]["tags"];
              for (vector<int>::const_iterator it = seasons.begin(); it != seasons.end(); it++) {//
                  season++;
                  for (int episode = 1; episode <= *it; episode++) {
                      //  content.push_back(new Episode( id,  seriesName, length,  season,  episode , tags);//
                      cout << id << ". ";
                      cout << seriesName << " ";
                      cout << length << " minutes ";
                      cout << "S"<<season << "E"<< episode <<" ";
                       string s="[";
                      for (vector<string>::const_iterator it = tags.begin(); it !=  tags.end(); it++)
                           s=s+(*it)+", ";
                       cout <<s.substr(0,s.length()-2)<<"]"<< endl;
                      id++;

                  }
              }
          }



              //  content.push_back(new Movie(i,name,length, tags));



          }




    Session::~Session(){

    }

void Session::start() {
        cout<<"SPLFLIX is now on";
        string s;
        cin >> s;
        while(s!="exit")
            if(s.="createUser")
                createUser(this)
            if(s=changeUser)



                cin >> s;

        }





