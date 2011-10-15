MarioKart
=========

The full description of this project can be found on our [github wiki](https://github.com/team-ramrod/mariokart/wiki)

Purpose
-------

To retrofit one of the EE department's electric go-karts with a drive by wire
system, controllable over a single USB interface. Add to this a simple example
of a closed-loop controller using sensors and software running on a \*nix
laptop.

Method
------

Control the electric motor, servo driven steering wheel and actuated brake
pedal via embedded arm microprocessors. The separate micros are connected via a
CAN and also leave room for an arbitrary number of analog and digital sensors.

Behavioural-level software runs on a laptop connected to this network via USB.

Future Work
-----------

Develop a more complete sensor network (possibly including computer vision in
collaboration with cosc428) alongside more advanced controller software.
