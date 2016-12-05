#include <iostream>
#include "Room.hpp"
#include <vector>
#include <cctype>

using namespace std;

void createRooms(vector<Room*> &rooms);
Room* getRoom(vector<Room*> &rooms, const char* description);
void printWelcome(Room* currentRoom);
void printHelp();
void printInventory(vector<Item*> &inventory);

int main(){
  //Initialize rooms.
  vector<Room*> rooms;
  createRooms(rooms);
  Room *hill = new Room("on the hilltop", "There is only emptiness ahead as far as the eye can see. You also see a hill to the east. It's not an easy climb"); //Winning room
  hill->setExit("west", getRoom(rooms, "in the front yard"));
  rooms.push_back(hill);
  getRoom(rooms, "in the front yard")->setExit("east", hill);
  //More game variables:
  vector<Item*> inventory;
  Room* currentRoom = getRoom(rooms, "in the dining room");

  cout << "Start typing your commands. Type \"help\" for a list of available commands." << endl;
  char input[128];
  bool done = false;

  while(!done){
    //Get input and convert to lower case.
    cin.getline(input, 128);
    for(int i = 0; input[i]; i++){
      input[i] = tolower(input[i]);
    }

    if(strcmp(input, "quit") == 0){
      return 0;
    }
    else if(strcmp(input, "help") == 0){
      printHelp();
    }
    else if(strcmp(input, "inventory") == 0){
      printInventory(inventory);
    }
    else{
      //All other commands have to do with items and thus require multiple words. Split the input into individual words:
    }
    
  }
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

  // initialise room exits
  outside->setExit("south", graveyard);
  outside->setExit("west", bedroom);

  bedroom->setExit("north", livingroom);
  bedroom->setExit("east", outside);
  bedroom->setExit("west", diningroom);

  diningroom->setExit("east", bedroom);
  diningroom->setExit("south", kitchen);
  diningroom->setExit("north", theatre);
  diningroom->setExit("west", basement);

  basement->setExit("south", deeperbasement);
  basement->setExit("east", diningroom);

  kitchen->setExit("north", diningroom);

  deeperbasement->setExit("north", basement);

  theatre->setExit("south", diningroom);
  theatre->setExit("east", livingroom);
  theatre->setExit("north", library);

  library->setExit("south", theatre);
  library->setExit("west", computerlab);
  library->setExit("east", reference);

  reference->setExit("west", library);

  computerlab->setExit("east", library);
  computerlab->setExit("north", hallway);

  hallway->setExit("south", computerlab);
  hallway->setExit("east", frontyard);

  frontyard->setExit("west", hallway);
  //frontyard->setExit("east", hill);

  //hill->setExit("west", frontyard);

  livingroom->setExit("south", bedroom);
  livingroom->setExit("west", theatre);

  graveyard->setExit("north", outside);
  
  //Create all the items and their descriptions and add them to the rooms:
  
  kitchen->items.push_back(new Item("goblet", "As you grab the goblet, a ghost flies out of the wall and sets the whole room on fire. You realize that it must be cursed. Unfortunately, you cannot escape and die."));

  Item* key = new Item("key");
  key->setPickupDescription("What's this key for?");
  deeperbasement->items.push_back(key);
  library->unlockItem = key;

  Item* candle = new Item("candle");
  candle->setPickupDescription("The candle is burning steadily. It's not much, but it helps.");
  livingroom->items.push_back(candle);
  deeperbasement->unlockItem = candle;
        
  Item* flashlight = new Item("flashlight");
  flashlight->setPickupDescription("The flashlight does not work. Perhaps the batteries are dead.");
  bedroom->items.push_back(flashlight);
        
  Item* tableoflogarithms = new Item("tableoflogarithms");
  hallway->unlockItem = tableoflogarithms;
  reference->items.push_back(tableoflogarithms);
        
  reference->items.push_back(new Item("dictionary"));
        
  Item* calculator = new Item("calculator");
  calculator->setPickupDescription("The calculator does not turn on. Perhaps the batteries are dead.");
  computerlab->items.push_back(calculator);
        
  Item *satellitephone = new Item("satellitephone");
  satellitephone->setPickupDescription("This phone has barely any charge left. There is no signal.");
  computerlab->items.push_back(satellitephone);
        
  deeperbasement->items.push_back(new Item("cobra", "The cobra bites you as you try to grab it and you die shortly."));
  livingroom->items.push_back(new Item("organ", "As you try to carry the organ, your spinal chord cannot handle the weight and snaps. Needless to say, you die."));
}

Room* getRoom(vector<Room*> &rooms, const char* description){
  //Returns pointer to room with given description. (Assumed to exist.)
  for(vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); it++){
    if(strcmp(description, (*it)->getDescription())==0){
      return *it;
    }
  }
  return NULL;
}

void printWelcome(Room *currentRoom){
  cout << endl;
  cout << "Welcome to the Adventure!" << endl;
  cout << "You are a detective investigating this house. Reports have been received claiming that it is haunted. A power outage occured while you were in the dining room." << "\nIt has been twenty minutes and your eyes just barely started to adjust to the darkness. There is no siganl on your cellphone and its battery is about to die." << endl;
  cout << "Type \"help\" for available commands." << endl;
  cout << endl;
  currentRoom->printLongDescription();
}

void printHelp(){
  cout << "You must find a way to get help." << endl;
  cout << endl;
  cout << "Your command words are:" << endl;
  cout << "help" << endl;
  cout << "go <exit>" << endl;
  cout << "quit" << endl;
  cout << "inventory" << endl;
  cout << "take <item>" << endl;
  cout << "drop <item>" << endl;
}

void printInventory(vector<Item*> &inventory){
  cout << "Your items:" << endl;
  for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
    cout << (*it)->getDescription() << endl;
  }
  cout << endl;
}
