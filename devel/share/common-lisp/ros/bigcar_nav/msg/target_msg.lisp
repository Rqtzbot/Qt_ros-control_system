; Auto-generated. Do not edit!


(cl:in-package bigcar_nav-msg)


;//! \htmlinclude target_msg.msg.html

(cl:defclass <target_msg> (roslisp-msg-protocol:ros-message)
  ((recognize
    :reader recognize
    :initarg :recognize
    :type cl:boolean
    :initform cl:nil)
   (shot
    :reader shot
    :initarg :shot
    :type cl:boolean
    :initform cl:nil)
   (grab
    :reader grab
    :initarg :grab
    :type cl:boolean
    :initform cl:nil)
   (i
    :reader i
    :initarg :i
    :type cl:fixnum
    :initform 0)
   (i_x
    :reader i_x
    :initarg :i_x
    :type cl:fixnum
    :initform 0)
   (i_y
    :reader i_y
    :initarg :i_y
    :type cl:fixnum
    :initform 0)
   (x_offset
    :reader x_offset
    :initarg :x_offset
    :type cl:fixnum
    :initform 0)
   (y_offset
    :reader y_offset
    :initarg :y_offset
    :type cl:fixnum
    :initform 0)
   (type
    :reader type
    :initarg :type
    :type cl:fixnum
    :initform 0)
   (direct
    :reader direct
    :initarg :direct
    :type cl:fixnum
    :initform 0)
   (height
    :reader height
    :initarg :height
    :type cl:fixnum
    :initform 0)
   (arm_status
    :reader arm_status
    :initarg :arm_status
    :type cl:fixnum
    :initform 0)
   (claw_status
    :reader claw_status
    :initarg :claw_status
    :type cl:fixnum
    :initform 0)
   (lift_status
    :reader lift_status
    :initarg :lift_status
    :type cl:fixnum
    :initform 0)
   (vision_status
    :reader vision_status
    :initarg :vision_status
    :type cl:fixnum
    :initform 0)
   (depth
    :reader depth
    :initarg :depth
    :type cl:fixnum
    :initform 0)
   (target_name
    :reader target_name
    :initarg :target_name
    :type cl:string
    :initform "")
   (do_what
    :reader do_what
    :initarg :do_what
    :type cl:string
    :initform "")
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform ""))
)

(cl:defclass target_msg (<target_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <target_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'target_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bigcar_nav-msg:<target_msg> is deprecated: use bigcar_nav-msg:target_msg instead.")))

(cl:ensure-generic-function 'recognize-val :lambda-list '(m))
(cl:defmethod recognize-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:recognize-val is deprecated.  Use bigcar_nav-msg:recognize instead.")
  (recognize m))

(cl:ensure-generic-function 'shot-val :lambda-list '(m))
(cl:defmethod shot-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:shot-val is deprecated.  Use bigcar_nav-msg:shot instead.")
  (shot m))

(cl:ensure-generic-function 'grab-val :lambda-list '(m))
(cl:defmethod grab-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:grab-val is deprecated.  Use bigcar_nav-msg:grab instead.")
  (grab m))

(cl:ensure-generic-function 'i-val :lambda-list '(m))
(cl:defmethod i-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:i-val is deprecated.  Use bigcar_nav-msg:i instead.")
  (i m))

(cl:ensure-generic-function 'i_x-val :lambda-list '(m))
(cl:defmethod i_x-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:i_x-val is deprecated.  Use bigcar_nav-msg:i_x instead.")
  (i_x m))

(cl:ensure-generic-function 'i_y-val :lambda-list '(m))
(cl:defmethod i_y-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:i_y-val is deprecated.  Use bigcar_nav-msg:i_y instead.")
  (i_y m))

(cl:ensure-generic-function 'x_offset-val :lambda-list '(m))
(cl:defmethod x_offset-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:x_offset-val is deprecated.  Use bigcar_nav-msg:x_offset instead.")
  (x_offset m))

(cl:ensure-generic-function 'y_offset-val :lambda-list '(m))
(cl:defmethod y_offset-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:y_offset-val is deprecated.  Use bigcar_nav-msg:y_offset instead.")
  (y_offset m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:type-val is deprecated.  Use bigcar_nav-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'direct-val :lambda-list '(m))
(cl:defmethod direct-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:direct-val is deprecated.  Use bigcar_nav-msg:direct instead.")
  (direct m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:height-val is deprecated.  Use bigcar_nav-msg:height instead.")
  (height m))

(cl:ensure-generic-function 'arm_status-val :lambda-list '(m))
(cl:defmethod arm_status-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:arm_status-val is deprecated.  Use bigcar_nav-msg:arm_status instead.")
  (arm_status m))

(cl:ensure-generic-function 'claw_status-val :lambda-list '(m))
(cl:defmethod claw_status-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:claw_status-val is deprecated.  Use bigcar_nav-msg:claw_status instead.")
  (claw_status m))

(cl:ensure-generic-function 'lift_status-val :lambda-list '(m))
(cl:defmethod lift_status-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:lift_status-val is deprecated.  Use bigcar_nav-msg:lift_status instead.")
  (lift_status m))

(cl:ensure-generic-function 'vision_status-val :lambda-list '(m))
(cl:defmethod vision_status-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:vision_status-val is deprecated.  Use bigcar_nav-msg:vision_status instead.")
  (vision_status m))

(cl:ensure-generic-function 'depth-val :lambda-list '(m))
(cl:defmethod depth-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:depth-val is deprecated.  Use bigcar_nav-msg:depth instead.")
  (depth m))

(cl:ensure-generic-function 'target_name-val :lambda-list '(m))
(cl:defmethod target_name-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:target_name-val is deprecated.  Use bigcar_nav-msg:target_name instead.")
  (target_name m))

(cl:ensure-generic-function 'do_what-val :lambda-list '(m))
(cl:defmethod do_what-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:do_what-val is deprecated.  Use bigcar_nav-msg:do_what instead.")
  (do_what m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <target_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bigcar_nav-msg:name-val is deprecated.  Use bigcar_nav-msg:name instead.")
  (name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <target_msg>) ostream)
  "Serializes a message object of type '<target_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'recognize) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'shot) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'grab) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'i)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'i_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'x_offset)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y_offset)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'type)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'direct)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'height)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'arm_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'claw_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'lift_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'vision_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'depth)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'depth)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'target_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'target_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'do_what))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'do_what))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <target_msg>) istream)
  "Deserializes a message object of type '<target_msg>"
    (cl:setf (cl:slot-value msg 'recognize) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'shot) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'grab) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i_x) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'i_y) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x_offset) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y_offset) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'direct) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'height) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'arm_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'claw_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'lift_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vision_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'depth)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'depth)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'target_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'target_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'do_what) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'do_what) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<target_msg>)))
  "Returns string type for a message object of type '<target_msg>"
  "bigcar_nav/target_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'target_msg)))
  "Returns string type for a message object of type 'target_msg"
  "bigcar_nav/target_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<target_msg>)))
  "Returns md5sum for a message object of type '<target_msg>"
  "bc0e7bd1dc8a707120e4081a94662789")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'target_msg)))
  "Returns md5sum for a message object of type 'target_msg"
  "bc0e7bd1dc8a707120e4081a94662789")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<target_msg>)))
  "Returns full string definition for message of type '<target_msg>"
  (cl:format cl:nil "bool recognize~%bool shot~%bool grab~%~%int8 i~%int8 i_x~%int8 i_y~%int16 x_offset~%int16 y_offset~%~%int8 type~%int8 direct~%int8 height~%int8 arm_status~%int8 claw_status~%int8 lift_status~%int8 vision_status~%~%uint16 depth~%~%string target_name~%string do_what~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'target_msg)))
  "Returns full string definition for message of type 'target_msg"
  (cl:format cl:nil "bool recognize~%bool shot~%bool grab~%~%int8 i~%int8 i_x~%int8 i_y~%int16 x_offset~%int16 y_offset~%~%int8 type~%int8 direct~%int8 height~%int8 arm_status~%int8 claw_status~%int8 lift_status~%int8 vision_status~%~%uint16 depth~%~%string target_name~%string do_what~%string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <target_msg>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
     2
     2
     1
     1
     1
     1
     1
     1
     1
     2
     4 (cl:length (cl:slot-value msg 'target_name))
     4 (cl:length (cl:slot-value msg 'do_what))
     4 (cl:length (cl:slot-value msg 'name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <target_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'target_msg
    (cl:cons ':recognize (recognize msg))
    (cl:cons ':shot (shot msg))
    (cl:cons ':grab (grab msg))
    (cl:cons ':i (i msg))
    (cl:cons ':i_x (i_x msg))
    (cl:cons ':i_y (i_y msg))
    (cl:cons ':x_offset (x_offset msg))
    (cl:cons ':y_offset (y_offset msg))
    (cl:cons ':type (type msg))
    (cl:cons ':direct (direct msg))
    (cl:cons ':height (height msg))
    (cl:cons ':arm_status (arm_status msg))
    (cl:cons ':claw_status (claw_status msg))
    (cl:cons ':lift_status (lift_status msg))
    (cl:cons ':vision_status (vision_status msg))
    (cl:cons ':depth (depth msg))
    (cl:cons ':target_name (target_name msg))
    (cl:cons ':do_what (do_what msg))
    (cl:cons ':name (name msg))
))
