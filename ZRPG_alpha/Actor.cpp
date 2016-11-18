
#include "Actor.h"

actor::actor(string _name, position _pos) :pos(_pos), name(_name) {}
actor::actor() { name = "ERROR"; }