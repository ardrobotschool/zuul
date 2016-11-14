#include <iostream>
#include "Room.hpp"

using namespace std;

int main(){
  char west[] = "west";
  Room *firstRoom = new Room("Awesome description");
  Room *secondRoom = new Room("This is the second room");

  firstRoom->setExit(west, secondRoom);

  char input[128];
  cin >> input;
  if(firstRoom->getExitRoom(input) != NULL){
    firstRoom->getExitRoom(input)->printDescription();
  }
  else{
    cout << "No such exit.";
  }

  return 0;
}
