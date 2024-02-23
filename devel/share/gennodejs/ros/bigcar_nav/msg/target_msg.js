// Auto-generated. Do not edit!

// (in-package bigcar_nav.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class target_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.recognize = null;
      this.shot = null;
      this.grab = null;
      this.i = null;
      this.i_x = null;
      this.i_y = null;
      this.x_offset = null;
      this.y_offset = null;
      this.type = null;
      this.direct = null;
      this.height = null;
      this.arm_status = null;
      this.claw_status = null;
      this.lift_status = null;
      this.vision_status = null;
      this.depth = null;
      this.target_name = null;
      this.do_what = null;
      this.name = null;
    }
    else {
      if (initObj.hasOwnProperty('recognize')) {
        this.recognize = initObj.recognize
      }
      else {
        this.recognize = false;
      }
      if (initObj.hasOwnProperty('shot')) {
        this.shot = initObj.shot
      }
      else {
        this.shot = false;
      }
      if (initObj.hasOwnProperty('grab')) {
        this.grab = initObj.grab
      }
      else {
        this.grab = false;
      }
      if (initObj.hasOwnProperty('i')) {
        this.i = initObj.i
      }
      else {
        this.i = 0;
      }
      if (initObj.hasOwnProperty('i_x')) {
        this.i_x = initObj.i_x
      }
      else {
        this.i_x = 0;
      }
      if (initObj.hasOwnProperty('i_y')) {
        this.i_y = initObj.i_y
      }
      else {
        this.i_y = 0;
      }
      if (initObj.hasOwnProperty('x_offset')) {
        this.x_offset = initObj.x_offset
      }
      else {
        this.x_offset = 0;
      }
      if (initObj.hasOwnProperty('y_offset')) {
        this.y_offset = initObj.y_offset
      }
      else {
        this.y_offset = 0;
      }
      if (initObj.hasOwnProperty('type')) {
        this.type = initObj.type
      }
      else {
        this.type = 0;
      }
      if (initObj.hasOwnProperty('direct')) {
        this.direct = initObj.direct
      }
      else {
        this.direct = 0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0;
      }
      if (initObj.hasOwnProperty('arm_status')) {
        this.arm_status = initObj.arm_status
      }
      else {
        this.arm_status = 0;
      }
      if (initObj.hasOwnProperty('claw_status')) {
        this.claw_status = initObj.claw_status
      }
      else {
        this.claw_status = 0;
      }
      if (initObj.hasOwnProperty('lift_status')) {
        this.lift_status = initObj.lift_status
      }
      else {
        this.lift_status = 0;
      }
      if (initObj.hasOwnProperty('vision_status')) {
        this.vision_status = initObj.vision_status
      }
      else {
        this.vision_status = 0;
      }
      if (initObj.hasOwnProperty('depth')) {
        this.depth = initObj.depth
      }
      else {
        this.depth = 0;
      }
      if (initObj.hasOwnProperty('target_name')) {
        this.target_name = initObj.target_name
      }
      else {
        this.target_name = '';
      }
      if (initObj.hasOwnProperty('do_what')) {
        this.do_what = initObj.do_what
      }
      else {
        this.do_what = '';
      }
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type target_msg
    // Serialize message field [recognize]
    bufferOffset = _serializer.bool(obj.recognize, buffer, bufferOffset);
    // Serialize message field [shot]
    bufferOffset = _serializer.bool(obj.shot, buffer, bufferOffset);
    // Serialize message field [grab]
    bufferOffset = _serializer.bool(obj.grab, buffer, bufferOffset);
    // Serialize message field [i]
    bufferOffset = _serializer.int8(obj.i, buffer, bufferOffset);
    // Serialize message field [i_x]
    bufferOffset = _serializer.int8(obj.i_x, buffer, bufferOffset);
    // Serialize message field [i_y]
    bufferOffset = _serializer.int8(obj.i_y, buffer, bufferOffset);
    // Serialize message field [x_offset]
    bufferOffset = _serializer.int16(obj.x_offset, buffer, bufferOffset);
    // Serialize message field [y_offset]
    bufferOffset = _serializer.int16(obj.y_offset, buffer, bufferOffset);
    // Serialize message field [type]
    bufferOffset = _serializer.int8(obj.type, buffer, bufferOffset);
    // Serialize message field [direct]
    bufferOffset = _serializer.int8(obj.direct, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.int8(obj.height, buffer, bufferOffset);
    // Serialize message field [arm_status]
    bufferOffset = _serializer.int8(obj.arm_status, buffer, bufferOffset);
    // Serialize message field [claw_status]
    bufferOffset = _serializer.int8(obj.claw_status, buffer, bufferOffset);
    // Serialize message field [lift_status]
    bufferOffset = _serializer.int8(obj.lift_status, buffer, bufferOffset);
    // Serialize message field [vision_status]
    bufferOffset = _serializer.int8(obj.vision_status, buffer, bufferOffset);
    // Serialize message field [depth]
    bufferOffset = _serializer.uint16(obj.depth, buffer, bufferOffset);
    // Serialize message field [target_name]
    bufferOffset = _serializer.string(obj.target_name, buffer, bufferOffset);
    // Serialize message field [do_what]
    bufferOffset = _serializer.string(obj.do_what, buffer, bufferOffset);
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type target_msg
    let len;
    let data = new target_msg(null);
    // Deserialize message field [recognize]
    data.recognize = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [shot]
    data.shot = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [grab]
    data.grab = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [i]
    data.i = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [i_x]
    data.i_x = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [i_y]
    data.i_y = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [x_offset]
    data.x_offset = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [y_offset]
    data.y_offset = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [type]
    data.type = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [direct]
    data.direct = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [arm_status]
    data.arm_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [claw_status]
    data.claw_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [lift_status]
    data.lift_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [vision_status]
    data.vision_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [depth]
    data.depth = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [target_name]
    data.target_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [do_what]
    data.do_what = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.target_name);
    length += _getByteLength(object.do_what);
    length += _getByteLength(object.name);
    return length + 31;
  }

  static datatype() {
    // Returns string type for a message object
    return 'bigcar_nav/target_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bc0e7bd1dc8a707120e4081a94662789';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool recognize
    bool shot
    bool grab
    
    int8 i
    int8 i_x
    int8 i_y
    int16 x_offset
    int16 y_offset
    
    int8 type
    int8 direct
    int8 height
    int8 arm_status
    int8 claw_status
    int8 lift_status
    int8 vision_status
    
    uint16 depth
    
    string target_name
    string do_what
    string name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new target_msg(null);
    if (msg.recognize !== undefined) {
      resolved.recognize = msg.recognize;
    }
    else {
      resolved.recognize = false
    }

    if (msg.shot !== undefined) {
      resolved.shot = msg.shot;
    }
    else {
      resolved.shot = false
    }

    if (msg.grab !== undefined) {
      resolved.grab = msg.grab;
    }
    else {
      resolved.grab = false
    }

    if (msg.i !== undefined) {
      resolved.i = msg.i;
    }
    else {
      resolved.i = 0
    }

    if (msg.i_x !== undefined) {
      resolved.i_x = msg.i_x;
    }
    else {
      resolved.i_x = 0
    }

    if (msg.i_y !== undefined) {
      resolved.i_y = msg.i_y;
    }
    else {
      resolved.i_y = 0
    }

    if (msg.x_offset !== undefined) {
      resolved.x_offset = msg.x_offset;
    }
    else {
      resolved.x_offset = 0
    }

    if (msg.y_offset !== undefined) {
      resolved.y_offset = msg.y_offset;
    }
    else {
      resolved.y_offset = 0
    }

    if (msg.type !== undefined) {
      resolved.type = msg.type;
    }
    else {
      resolved.type = 0
    }

    if (msg.direct !== undefined) {
      resolved.direct = msg.direct;
    }
    else {
      resolved.direct = 0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0
    }

    if (msg.arm_status !== undefined) {
      resolved.arm_status = msg.arm_status;
    }
    else {
      resolved.arm_status = 0
    }

    if (msg.claw_status !== undefined) {
      resolved.claw_status = msg.claw_status;
    }
    else {
      resolved.claw_status = 0
    }

    if (msg.lift_status !== undefined) {
      resolved.lift_status = msg.lift_status;
    }
    else {
      resolved.lift_status = 0
    }

    if (msg.vision_status !== undefined) {
      resolved.vision_status = msg.vision_status;
    }
    else {
      resolved.vision_status = 0
    }

    if (msg.depth !== undefined) {
      resolved.depth = msg.depth;
    }
    else {
      resolved.depth = 0
    }

    if (msg.target_name !== undefined) {
      resolved.target_name = msg.target_name;
    }
    else {
      resolved.target_name = ''
    }

    if (msg.do_what !== undefined) {
      resolved.do_what = msg.do_what;
    }
    else {
      resolved.do_what = ''
    }

    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    return resolved;
    }
};

module.exports = target_msg;
