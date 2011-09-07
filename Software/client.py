import sys, tty, termios, select, os, threading, time, re
from serial import Serial, SerialException
from mutex import mutex

ADDR_ERROR_RX     = '\x00'
ADDR_BROADCAST_RX = '\x01'
ADDR_BROADCAST_TX = '\x02'
ADDR_BRAKE        = '\x03'
ADDR_COMMS        = '\x04'
ADDR_COMMS_USB    = '\x04'
ADDR_STEERING     = '\x05'
ADDR_MOTOR        = '\x06'
ADDR_SENSOR       = '\x07'


CMD_NONE          = '\x00'
CMD_GET           = '\x01'
CMD_REPLY         = '\x02'
CMD_SET           = '\x03'
CMD_REQ_CALIBRATE = '\x04'
CMD_ACK_CALIBRATE = '\x05'
CMD_REQ_RUN       = '\x06'
CMD_ACK_RUN       = '\x07'
CMD_NO            = '\x08'
CMD_ERROR         = '\x09'
CMD_RUN           = '\x0A'
CMD_CALIBRATE     = '\x0B'


VAR_SPEED   = '\x01'
VAR_BRK_POS = '\x02'

address_translation = {
    'brake': ADDR_BRAKE,
    'comms': ADDR_COMMS,
    'steering': ADDR_STEERING,
    'motor': ADDR_MOTOR,
    'sensor': ADDR_SENSOR
}

command_translation = {
    'get': CMD_GET,
    'set': CMD_SET,
}

var_translation = {
    'speed': VAR_SPEED,
    'brake_position': VAR_BRK_POS
}

def data_translation(data):
  data = data.split(' ')
  result = []
  for datum in data:
    if datum in var_translation:
      result += [var_translation[datum]]
    else:
      try:
        result += [int(datum,0)]
      except ValueError, e:
        pass
  return result


class Client:
  def __init__(self):
    self.serial = Serial();
    self.serial.port = '/dev/ttyACM0'
    self.serial.timeout = 1

    try:
      self.serial.open()
    except SerialException, e:
      sys.stderr.write("Could not open serial port %s: %s\n" % (self.serial.portstr, e))
      sys.exit(1)

  def run(self):
    cmd_re = re.compile(r'send\s+(\w+)\s+(\w+)\s*([\w\s]*)')
    print 'Connected.'
    running = True
    while running:
      try:
        cmd = raw_input()
        match = cmd_re.match(cmd)
        if match:
          board = match.group(1)
          command = match.group(2)
          data = match.group(3)

          try:
            message = [address_translation[board]] + [command_translation[command]] + data_translation(data) + ['\xFF']
          except KeyError, e:
            sys.stderr.write("Incorrect command")

          self.serial.write(''.join(message))
        else:
          sys.stderr.write("Incorrect command")
      except EOFError:
        running = False


if __name__ == '__main__':
  Client().run()
