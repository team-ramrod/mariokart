#include "location.h"

void Location::set_values (double new_x, double new_y, double new_z, double new_t) {
  x = new_x;
  y = new_y;
  z = new_z;
  t = new_t;
}

void Location::add_offset (Location offset) {
  x = offset.x;
  y = offset.y;
  z = offset.z;
  t = offset.t;
}

void Location::move_position (double angle, double speed, double timestep) {
  x += cos(angle) * (speed / timestep);
  z = sin(angle) * (speed / timestep);
}
