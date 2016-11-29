#include <iostream>
#include "Room.hpp"

using namespace std;

void createRooms();

int main(){
  char west[] = "west";
  

  firstRoom->setExit(west, secondRoom);

  char input[128];
  cin >> input;
  if(firstRoom->getExitRoom(input) != NULL){
    firstRoom->getExitRoom(input)->printDiscoveryDescription();
  }
  else{
    cout << "No such exit.";
  }

  return 0;
}

void createRooms(){
  Room theatre, library, reference, livingroom, 
        bedroom, outside, graveyard, kitchen, deeperbasement,
        basement, computerlab, hallway, frontyard, diningroom;

  outside = new Room("outside", "You made it outside, but the only path from here leads south to the graveyard.");
  //Fix to match new constructors:
  /*theatre = new Room("in the theatre room");
        basement = new Room("in the basement");
        graveyard = new Room("in the graveyard");
        bedroom = new Room("in a bedroom");
        diningroom = new Room("in the dining room");
        kitchen = new Room("in the kitchen");
        deeperbasement = new Room("in the deeper part of the basement", "It's very dark in there. Going without something to light the way is too dangerous.");
        livingroom = new Room("in the living room");
        reference = new Room("in the reference section of the library");
        library = new Room("in the library", "The library door is locked. A key is needed.");
        computerlab = new Room("in the computer lab");
        hallway = new Room("in a long hallway", "The mechanical lock requires you to perform calculations involving products and roots of large numbers that you do not have the time to compute by hand.");
        frontyard = new Room("in the front yard");
        hill = new Room("on the hilltop");*/
}
