#include "location.h"

void Location::set_values (double new_x, double new_y, double new_z, double new_t) {
  x = new_x;
  y = new_y;
  z = new_z;
  t = new_t;
}

void Location::set_values (Location loc) {
  x = loc.x;
  y = loc.y;
  z = loc.z;
  t = loc.t;
}

void Location::add_offset (Location offset ,double angle) {
  double temp_x = offset.x + cos(angle) * x - sin(angle) * z;
  double temp_z = offset.z + sin(angle) * x + cos(angle) * z;

  x = temp_x;
  z = temp_z;
}

void Location::move_position (double angle, double speed, double timestep) {
  z += cos(angle) * (speed / timestep);
  x = sin(angle) * (speed / timestep);
}
