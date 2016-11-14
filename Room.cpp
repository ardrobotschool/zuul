#include <iostream>
#include "Room.hpp"

using namespace std;

Room::Room(const char* newDescription){
  description = newDescription;
}

void Room::printDescription(){
  cout << description << endl;
}

void Room::setExit(char* str, Room *room){
  exits[str] = room;
}

Room* Room::getExitRoom(char* exit){
  //Check if such an exit exists!
  if(exits.find(exit) != exits.end()){
    return exits[exit];
  }
  else{
    return 0;
  }
}
