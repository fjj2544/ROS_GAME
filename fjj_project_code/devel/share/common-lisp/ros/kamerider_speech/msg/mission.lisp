; Auto-generated. Do not edit!


(cl:in-package kamerider_speech-msg)


;//! \htmlinclude mission.msg.html

(cl:defclass <mission> (roslisp-msg-protocol:ros-message)
  ((mission_type
    :reader mission_type
    :initarg :mission_type
    :type cl:string
    :initform "")
   (mission_name
    :reader mission_name
    :initarg :mission_name
    :type cl:string
    :initform ""))
)

(cl:defclass mission (<mission>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mission>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mission)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kamerider_speech-msg:<mission> is deprecated: use kamerider_speech-msg:mission instead.")))

(cl:ensure-generic-function 'mission_type-val :lambda-list '(m))
(cl:defmethod mission_type-val ((m <mission>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kamerider_speech-msg:mission_type-val is deprecated.  Use kamerider_speech-msg:mission_type instead.")
  (mission_type m))

(cl:ensure-generic-function 'mission_name-val :lambda-list '(m))
(cl:defmethod mission_name-val ((m <mission>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kamerider_speech-msg:mission_name-val is deprecated.  Use kamerider_speech-msg:mission_name instead.")
  (mission_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mission>) ostream)
  "Serializes a message object of type '<mission>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'mission_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'mission_type))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'mission_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'mission_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mission>) istream)
  "Deserializes a message object of type '<mission>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mission_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'mission_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mission_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'mission_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mission>)))
  "Returns string type for a message object of type '<mission>"
  "kamerider_speech/mission")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mission)))
  "Returns string type for a message object of type 'mission"
  "kamerider_speech/mission")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mission>)))
  "Returns md5sum for a message object of type '<mission>"
  "6d58fdcb61ba622ce7ed121da079b668")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mission)))
  "Returns md5sum for a message object of type 'mission"
  "6d58fdcb61ba622ce7ed121da079b668")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mission>)))
  "Returns full string definition for message of type '<mission>"
  (cl:format cl:nil "string mission_type~%string mission_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mission)))
  "Returns full string definition for message of type 'mission"
  (cl:format cl:nil "string mission_type~%string mission_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mission>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'mission_type))
     4 (cl:length (cl:slot-value msg 'mission_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mission>))
  "Converts a ROS message object to a list"
  (cl:list 'mission
    (cl:cons ':mission_type (mission_type msg))
    (cl:cons ':mission_name (mission_name msg))
))
