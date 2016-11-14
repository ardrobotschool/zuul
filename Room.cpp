#include <iostream>
#include "Room.hpp"

using namespace std;

Room::Room(const char* newDescription, const char* newDiscoveryDescription){
  locked = false;
  description = newDescription;
  discoveryDescription = newDiscoveryDescription;
}
//Now the constructor for a locked room:
Room::Room(const char* newDescription, const char* newDiscoveryDescription, const char* newLockedDescription) : Room(newDescription, newDiscoveryDescription){
  locked = true;
  first = true;
  lockedDescription = newLockedDescription;
}

const char* Room::getDescription(){
  return description;
}

const char* Room::getDiscoveryDescription(){
  return discoveryDescription;
}

const char* Room::getLockedDescription(){
  return lockedDescription;
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
