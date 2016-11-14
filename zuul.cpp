#include <iostream>
#include "Room.hpp"

using namespace std;

int main(){
  char west[] = "west";
  Room *firstRoom = new Room("Awesome description", "DiscoveryFirst");
  Room *secondRoom = new Room("This is the second room", "DiscoverySecond");

  firstRoom->setExit(west, secondRoom);

  char input[128];
  cin >> input;
  if(firstRoom->getExitRoom(input) != NULL){
    cout << firstRoom->getExitRoom(input)->getDiscoveryDescription() << endl;
  }
  else{
    cout << "No such exit.";
  }

  return 0;
}
