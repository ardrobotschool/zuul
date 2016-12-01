#include <iostream>
#include "Room.hpp"
#include <vector>

using namespace std;

void createRooms(vector<Room*> &rooms);

int main(){
  char west[] = "west";
  vector<Room*> rooms;
  createRooms(rooms);
  rooms[0]->printDescription();
  Room *hill = new Room("on the hilltop", "There is only emptiness ahead as far as the eye can see. You also see a hill to the east. It's not an easy climb");
  /*
  someRoom->setExit(west, secondRoom);

  char input[128];
  cin >> input;
  if(firstRoom->getExitRoom(input) != NULL){
    firstRoom->getExitRoom(input)->printDiscoveryDescription();
  }
  else{
    cout << "No such exit.";
    }*/

  return 0;
}

void createRooms(vector<Room*> &rooms){
  Room *theatre, *library, *reference, *livingroom, 
    *bedroom, *outside, *graveyard, *kitchen, *deeperbasement,
        *basement, *computerlab, *hallway, *frontyard, *diningroom;
  outside = new Room("outside", "You made it outside, but the only path from here leads south to the graveyard.");
  rooms.push_back(outside);
  theatre = new Room("in the theatre room", "A horror movie is playing. But who would start it, and why?");
  rooms.push_back(theatre);
  basement = new Room("in the basement", "It is very dark in here. You see stairs to the south that lead even further downward.");
  rooms.push_back(basement);
  graveyard = new Room("in the graveyard", "The whole place is cold and dark. The surrounding vegetation is too dense to pass through.");
  rooms.push_back(graveyard);
  bedroom = new Room("in a bedroom", "");
  rooms.push_back(bedroom);
  diningroom = new Room("in the dining room", "");
  rooms.push_back(diningroom);
  kitchen = new Room("in the kitchen", "There is a goblet made of gold and filled with jewelry standing on the table.");
  rooms.push_back(kitchen);
  deeperbasement = new Room("in the deeper part of the basement", "Good thing you brought that candle. There is a snake on the floor! It's moving slowly.", "Good thing you brought that candle. There is a snake on the floor! It's moving slowly.");
  rooms.push_back(deeperbasement);
  livingroom = new Room("in the living room", "There is an organ here. It is playing music by itself. Well, either that or you can't see the player.");
  rooms.push_back(livingroom);
  reference = new Room("in the reference section of the library", "");
  rooms.push_back(reference);
  library = new Room("in the library", "You see lots and lots of books. There should be enough for years. After all, you're not in a hurry, right?", "The library door is locked. A key is needed.");
  rooms.push_back(library);
  computerlab = new Room("in the computer lab", "These are old computers. Everything is powered down, in any case.");
  rooms.push_back(computerlab);
  hallway = new Room("in a long hallway", "Finally. It took you 20 minutes just to perform the necessary calculations to open the lock. If it was any longer than that, you would lose your mind, which almost happened several times during the process. Those handy logarithm tables!", "The mechanical lock requires you to perform calculations involving products and roots of large numbers that you do not have the time to compute by hand.");
  rooms.push_back(hallway);
  frontyard = new Room("in the front yard", "There is only emptiness ahead as far as the eye can see. You also see a hill to the east. It's not an easy climb");
  rooms.push_back(frontyard);
}
