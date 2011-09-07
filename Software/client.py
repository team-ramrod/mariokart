from re import compile
from sys import stderr, exit, argv
from serial import Serial, SerialException
from definitions import *

cmd_re = compile(r'send\s+(\w+)\s+(\w+)\s*([\w\s]*)')

serial = Serial()
serial.port = argv[1] if len(argv) > 1 else '/dev/ttyACM0'
serial.timeout = 1

try:
	serial.open()
except SerialException, e:
	stderr.write("%s\n" % (e))
	exit(1)

print 'Connected.'
running = True
while running:
	try:
		match = cmd_re.match(raw_input())
		if match:
			board   = match.group(1)
			command = match.group(2)
			data    = match.group(3)

			try:
				message = address_translation(board) + command_translation(command) + data_translation(data) + ['\xFF']
			except Exception, e:
				stderr.write("Incorrect command\n")

			serial.write(''.join(message))
		else:
			stderr.write("Incorrect command\n")
	except EOFError:
		running = False