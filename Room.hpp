#include <iostream>
#include <map>
#include <cstring>

using namespace std;

struct CStrCmp{
  bool operator()(char* a, char* b){
    return strcmp(a, b) < 0;
  }
};

class Room{
public:
  Room(const char* description, const char* discoveryDescription);
  Room(const char* description, const char* discoveryDescription, const char* lockedDescription);
  const char* getDescription();
  const char* getDiscoveryDescription();
  const char* getLockedDescription();
  void setExit(char* str, Room *room);
  Room* getExitRoom(char* exit);
private:
  bool locked;
  bool first;
  map<char*, Room*, CStrCmp> exits;
  const char* description;
  const char* discoveryDescription;
  const char* lockedDescription;
};
