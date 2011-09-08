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
VAR_STEERING_ANGLE = '\x03'


def address_translation(address):
    return [{
        'brake': ADDR_BRAKE,
        'comms': ADDR_COMMS,
        'steering': ADDR_STEERING,
        'motor': ADDR_MOTOR,
        'sensor': ADDR_SENSOR,
        'all': ADDR_BROADCAST_RX,
    }[address]]

def command_translation(command):
    return [{
        'get': CMD_GET,
        'set': CMD_SET,
        'error': CMD_ERROR,
    }[command]]

var_translation = {
    'speed': VAR_SPEED,
    'brake_position': VAR_BRK_POS,
    'steering_angle': VAR_STEERING_ANGLE,
}

def data_translation(data):
    data = data.split(' ')
    result = []
    for datum in data:
        if datum in var_translation:
            result += [var_translation[datum]]
        else:
            result += [chr(int(datum,0))]
    return result
