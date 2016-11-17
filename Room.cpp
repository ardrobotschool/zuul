#include <iostream>
#include "Room.hpp"

using namespace std;

Room::Room(const char* newDescription, const char* newDiscoveryDescription){
  description = newDescription;
  discoveryDescription = newDiscoveryDescription;
}
//Now the constructor for a locked room:
Room::Room(const char* newDescription, const char* newDiscoveryDescription, const char* newLockedDescription) : Room(newDescription, newDiscoveryDescription){
  locked = true;
  lockedDescription = newLockedDescription;
}

void Room::printDescription(){
  cout << description;
}

void Room::printDiscoveryDescription(){
  cout << discoveryDescription;
}

void Room::printLockedDescription(){
  cout << lockedDescription;
}

void Room::printShortDescription(){
  cout << description;
}

void Room::printLongDescription(){
  //Decide whether to just print it out or concatenate the cstrings...
}



void Room::setExit(char* str, Room *room){
  exits[str] = room;
}

Room* Room::getExitRoom(char* exit){ //Returns exit corresponding to given key; null if no such exit.
  //Check if such an exit exists!
  if(exits.find(exit) != exits.end()){
    return exits[exit];
  }
  else{
    return 0;
  }
}
