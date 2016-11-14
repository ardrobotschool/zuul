#include <iostream>
#include "Room.hpp"

using namespace std;

int main(){
  char west[] = "west";
  Room *firstRoom = new Room("Awesome description");
  Room *secondRoom = new Room("This is the second room");

  firstRoom->setExit(west, secondRoom);
  firstRoom->getExitRoom(west)->printDescription();

  return 0;
}
