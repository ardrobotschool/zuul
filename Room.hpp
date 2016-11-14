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
  Room(const char* description);
  void printDescription();
  void setExit(char* str, Room *room);
  Room* getExitRoom(char* exit);
private:
  map<char*, Room*, CStrCmp> exits;
  const char* description;
};
