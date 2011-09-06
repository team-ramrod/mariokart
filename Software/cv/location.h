/* 
 * File:   location.h
 * Author: z
 *
 * Created on September 6, 2011, 2:52 PM
 */

#ifndef LOCATION_H
#define	LOCATION_H

#include <math.h>

class Location {
    double x, y, z, t;
  public:
    void set_values (double, double, double, double);
    void add_offset(Location);
    double relative_angle(Location);
    void move_position (double, double, double);
};

#endif	/* LOCATION_H */

