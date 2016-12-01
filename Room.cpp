#include <iostream>
#include "Room.hpp"
#include <cstring>

using namespace std;

Room::Room(const char* newDescription, const char* newDiscoveryDescription) : description(newDescription), discoveryDescription(newDiscoveryDescription){
  
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
  cout << "You are " << description << endl;
  printExitString();
}

void Room::printExitString(){
  cout << "Exits:";
  //Print out all the exits.
  for(map<char*, Room*, CStrCmp>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << it->first;
    if(it != --exits.end()){
      cout << ", ";
    }
  }
  cout << "." << endl;
  //Also add items.
  printItems();
}

void Room::printItems(){
  if(!items.empty()){
    cout << "Items here: ";
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
      cout << (*it)->getDescription();
      if(it != --items.end()){
	cout << ", ";
      }
    }
    cout << ".";
  }
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
