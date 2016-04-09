; Auto-generated. Do not edit!


(cl:in-package beginner_tutorials-msg)


;//! \htmlinclude Gen.msg.html

(cl:defclass <Gen> (roslisp-msg-protocol:ros-message)
  ((my_name
    :reader my_name
    :initarg :my_name
    :type cl:string
    :initform ""))
)

(cl:defclass Gen (<Gen>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Gen>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Gen)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorials-msg:<Gen> is deprecated: use beginner_tutorials-msg:Gen instead.")))

(cl:ensure-generic-function 'my_name-val :lambda-list '(m))
(cl:defmethod my_name-val ((m <Gen>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorials-msg:my_name-val is deprecated.  Use beginner_tutorials-msg:my_name instead.")
  (my_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Gen>) ostream)
  "Serializes a message object of type '<Gen>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'my_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'my_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Gen>) istream)
  "Deserializes a message object of type '<Gen>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'my_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'my_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Gen>)))
  "Returns string type for a message object of type '<Gen>"
  "beginner_tutorials/Gen")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Gen)))
  "Returns string type for a message object of type 'Gen"
  "beginner_tutorials/Gen")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Gen>)))
  "Returns md5sum for a message object of type '<Gen>"
  "587f464e921a54e4ccb9c52f3f4f4bcb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Gen)))
  "Returns md5sum for a message object of type 'Gen"
  "587f464e921a54e4ccb9c52f3f4f4bcb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Gen>)))
  "Returns full string definition for message of type '<Gen>"
  (cl:format cl:nil "string my_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Gen)))
  "Returns full string definition for message of type 'Gen"
  (cl:format cl:nil "string my_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Gen>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'my_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Gen>))
  "Converts a ROS message object to a list"
  (cl:list 'Gen
    (cl:cons ':my_name (my_name msg))
))
