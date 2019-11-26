#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include "Action.h"
using namespace std;
class User;
class Watchable;

class Session{
public:
    Session(const std::string &configFilePath);
    Session(Session&);
    Session(Session &&other);
    ~Session();
    Session& operator=(const Session &&) ;
    Session& operator=(const Session &);
    void start();
    void convertJson();
    std::vector<Watchable*> getContent() const;
    const std::vector<BaseAction *> &getActionsLog() const;
    const std::unordered_map<std::string, User *> &getUserMap() const;
    User *getActiveUser() const;
    void setContent(const std::vector<Watchable *> &content);
    void setActionsLog(const std::vector<BaseAction *> &actionsLog);
    void setUserMap(const std::unordered_map<std::string, User *> &userMap);
    void setActiveUser(User *activeUser);
    void addActionLog(BaseAction *const action);
    void addUser(string name, string rec) ;
    void duplicateUser(string name);
    string getInput()const;
    void copy(const Session &other);
    void clear();
    void deleteUser(User *user);
    void deleteUserFromMap(string name);

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    bool terminate;
    string input;
};


#endif