#include "location.h"
#include <stdio.h>

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

  double temp_x = offset.x + cos(angle) * x + sin(angle) * z;
  double temp_z = offset.z + sin(angle) * x - cos(angle) * z;

  x = temp_x;
  z = temp_z;
}

void Location::move_position (double angle, double speed, double timestep) {
  z += sin(angle) * (speed / timestep);
  x += cos(angle) * (speed / timestep);
}

double Location::relative_angle(Location loc, double angle){

    double delta_z = loc.z - z;
    double delta_x = loc.x - x;

    double temp_z = -cos(angle) * delta_z + sin(angle) * delta_x;
    double temp_x = cos(angle) * delta_x + sin(angle) * delta_z;

    return (-atan2(temp_z,temp_x));
}

double Location::dist_to(Location loc){
    return sqrt((x - loc.x) * (x - loc.x) + (y - loc.y) * (y - loc.y));
}