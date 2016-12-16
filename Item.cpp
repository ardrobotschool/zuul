#include <iostream>
#include "Item.hpp"

Item::Item(const char* s){
  description = s;
}

Item::Item(const char* s, const char* c){
  description = s;
  deadly = true;
  deathDescription = c;
}

Item::~Item(){
  delete description;
  delete pickupDescription;
  delete deathDescription;
}

const char* Item::getDescription(){
  return description;
}

const char* Item::getPickupDescription(){
  return pickupDescription;
}

const char* Item::getDeathDescription(){
  return deathDescription;
}

void Item::setPickupDescription(const char* s){
  pickupDescription = s;
}
