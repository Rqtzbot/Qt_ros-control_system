;; Auto-generated. Do not edit!


(when (boundp 'bigcar_nav::target_msg)
  (if (not (find-package "BIGCAR_NAV"))
    (make-package "BIGCAR_NAV"))
  (shadow 'target_msg (find-package "BIGCAR_NAV")))
(unless (find-package "BIGCAR_NAV::TARGET_MSG")
  (make-package "BIGCAR_NAV::TARGET_MSG"))

(in-package "ROS")
;;//! \htmlinclude target_msg.msg.html


(defclass bigcar_nav::target_msg
  :super ros::object
  :slots (_recognize _shot _grab _i _i_x _i_y _x_offset _y_offset _type _direct _height _arm_status _claw_status _lift_status _vision_status _depth _target_name _do_what _name ))

(defmethod bigcar_nav::target_msg
  (:init
   (&key
    ((:recognize __recognize) nil)
    ((:shot __shot) nil)
    ((:grab __grab) nil)
    ((:i __i) 0)
    ((:i_x __i_x) 0)
    ((:i_y __i_y) 0)
    ((:x_offset __x_offset) 0)
    ((:y_offset __y_offset) 0)
    ((:type __type) 0)
    ((:direct __direct) 0)
    ((:height __height) 0)
    ((:arm_status __arm_status) 0)
    ((:claw_status __claw_status) 0)
    ((:lift_status __lift_status) 0)
    ((:vision_status __vision_status) 0)
    ((:depth __depth) 0)
    ((:target_name __target_name) "")
    ((:do_what __do_what) "")
    ((:name __name) "")
    )
   (send-super :init)
   (setq _recognize __recognize)
   (setq _shot __shot)
   (setq _grab __grab)
   (setq _i (round __i))
   (setq _i_x (round __i_x))
   (setq _i_y (round __i_y))
   (setq _x_offset (round __x_offset))
   (setq _y_offset (round __y_offset))
   (setq _type (round __type))
   (setq _direct (round __direct))
   (setq _height (round __height))
   (setq _arm_status (round __arm_status))
   (setq _claw_status (round __claw_status))
   (setq _lift_status (round __lift_status))
   (setq _vision_status (round __vision_status))
   (setq _depth (round __depth))
   (setq _target_name (string __target_name))
   (setq _do_what (string __do_what))
   (setq _name (string __name))
   self)
  (:recognize
   (&optional (__recognize :null))
   (if (not (eq __recognize :null)) (setq _recognize __recognize)) _recognize)
  (:shot
   (&optional (__shot :null))
   (if (not (eq __shot :null)) (setq _shot __shot)) _shot)
  (:grab
   (&optional (__grab :null))
   (if (not (eq __grab :null)) (setq _grab __grab)) _grab)
  (:i
   (&optional __i)
   (if __i (setq _i __i)) _i)
  (:i_x
   (&optional __i_x)
   (if __i_x (setq _i_x __i_x)) _i_x)
  (:i_y
   (&optional __i_y)
   (if __i_y (setq _i_y __i_y)) _i_y)
  (:x_offset
   (&optional __x_offset)
   (if __x_offset (setq _x_offset __x_offset)) _x_offset)
  (:y_offset
   (&optional __y_offset)
   (if __y_offset (setq _y_offset __y_offset)) _y_offset)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:direct
   (&optional __direct)
   (if __direct (setq _direct __direct)) _direct)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:arm_status
   (&optional __arm_status)
   (if __arm_status (setq _arm_status __arm_status)) _arm_status)
  (:claw_status
   (&optional __claw_status)
   (if __claw_status (setq _claw_status __claw_status)) _claw_status)
  (:lift_status
   (&optional __lift_status)
   (if __lift_status (setq _lift_status __lift_status)) _lift_status)
  (:vision_status
   (&optional __vision_status)
   (if __vision_status (setq _vision_status __vision_status)) _vision_status)
  (:depth
   (&optional __depth)
   (if __depth (setq _depth __depth)) _depth)
  (:target_name
   (&optional __target_name)
   (if __target_name (setq _target_name __target_name)) _target_name)
  (:do_what
   (&optional __do_what)
   (if __do_what (setq _do_what __do_what)) _do_what)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:serialization-length
   ()
   (+
    ;; bool _recognize
    1
    ;; bool _shot
    1
    ;; bool _grab
    1
    ;; int8 _i
    1
    ;; int8 _i_x
    1
    ;; int8 _i_y
    1
    ;; int16 _x_offset
    2
    ;; int16 _y_offset
    2
    ;; int8 _type
    1
    ;; int8 _direct
    1
    ;; int8 _height
    1
    ;; int8 _arm_status
    1
    ;; int8 _claw_status
    1
    ;; int8 _lift_status
    1
    ;; int8 _vision_status
    1
    ;; uint16 _depth
    2
    ;; string _target_name
    4 (length _target_name)
    ;; string _do_what
    4 (length _do_what)
    ;; string _name
    4 (length _name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _recognize
       (if _recognize (write-byte -1 s) (write-byte 0 s))
     ;; bool _shot
       (if _shot (write-byte -1 s) (write-byte 0 s))
     ;; bool _grab
       (if _grab (write-byte -1 s) (write-byte 0 s))
     ;; int8 _i
       (write-byte _i s)
     ;; int8 _i_x
       (write-byte _i_x s)
     ;; int8 _i_y
       (write-byte _i_y s)
     ;; int16 _x_offset
       (write-word _x_offset s)
     ;; int16 _y_offset
       (write-word _y_offset s)
     ;; int8 _type
       (write-byte _type s)
     ;; int8 _direct
       (write-byte _direct s)
     ;; int8 _height
       (write-byte _height s)
     ;; int8 _arm_status
       (write-byte _arm_status s)
     ;; int8 _claw_status
       (write-byte _claw_status s)
     ;; int8 _lift_status
       (write-byte _lift_status s)
     ;; int8 _vision_status
       (write-byte _vision_status s)
     ;; uint16 _depth
       (write-word _depth s)
     ;; string _target_name
       (write-long (length _target_name) s) (princ _target_name s)
     ;; string _do_what
       (write-long (length _do_what) s) (princ _do_what s)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _recognize
     (setq _recognize (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _shot
     (setq _shot (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _grab
     (setq _grab (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int8 _i
     (setq _i (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _i 127) (setq _i (- _i 256)))
   ;; int8 _i_x
     (setq _i_x (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _i_x 127) (setq _i_x (- _i_x 256)))
   ;; int8 _i_y
     (setq _i_y (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _i_y 127) (setq _i_y (- _i_y 256)))
   ;; int16 _x_offset
     (setq _x_offset (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _y_offset
     (setq _y_offset (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int8 _type
     (setq _type (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _type 127) (setq _type (- _type 256)))
   ;; int8 _direct
     (setq _direct (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _direct 127) (setq _direct (- _direct 256)))
   ;; int8 _height
     (setq _height (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _height 127) (setq _height (- _height 256)))
   ;; int8 _arm_status
     (setq _arm_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _arm_status 127) (setq _arm_status (- _arm_status 256)))
   ;; int8 _claw_status
     (setq _claw_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _claw_status 127) (setq _claw_status (- _claw_status 256)))
   ;; int8 _lift_status
     (setq _lift_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _lift_status 127) (setq _lift_status (- _lift_status 256)))
   ;; int8 _vision_status
     (setq _vision_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _vision_status 127) (setq _vision_status (- _vision_status 256)))
   ;; uint16 _depth
     (setq _depth (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _target_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _target_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _do_what
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _do_what (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get bigcar_nav::target_msg :md5sum-) "bc0e7bd1dc8a707120e4081a94662789")
(setf (get bigcar_nav::target_msg :datatype-) "bigcar_nav/target_msg")
(setf (get bigcar_nav::target_msg :definition-)
      "bool recognize
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

")



(provide :bigcar_nav/target_msg "bc0e7bd1dc8a707120e4081a94662789")


