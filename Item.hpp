#include <iostream>

class Item{
 public:
  Item(const char* s);
  Item(const char* s, const char* c);
  const char* getDescription();
  const char* getPickupDescription();
  const char* getDeathDescription();
  void setPickupDescription(const char* s);
  bool deadly = false;
  bool first = true;
 private:
  const char* description;
  const char* pickupDescription;
  const char* deathDescription;
};
