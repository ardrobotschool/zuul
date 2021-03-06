//This class represents an item that can be in a room or in the player's inventory.
//Some items are deadly: picking these up will kill the player.
#include <iostream>

class Item{
 public:
  Item(const char* s);
  Item(const char* s, const char* c);
  ~Item();
  const char* getDescription();
  const char* getPickupDescription();
  const char* getDeathDescription();
  void setPickupDescription(const char* s);
  bool deadly = false;
  bool first = true;
 private:
  const char* description;
  const char* pickupDescription = "";
  const char* deathDescription;
};
