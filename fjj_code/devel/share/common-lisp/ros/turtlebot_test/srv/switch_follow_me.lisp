; Auto-generated. Do not edit!


(cl:in-package turtlebot_test-srv)


;//! \htmlinclude switch_follow_me-request.msg.html

(cl:defclass <switch_follow_me-request> (roslisp-msg-protocol:ros-message)
  ((req
    :reader req
    :initarg :req
    :type cl:string
    :initform ""))
)

(cl:defclass switch_follow_me-request (<switch_follow_me-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switch_follow_me-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switch_follow_me-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_test-srv:<switch_follow_me-request> is deprecated: use turtlebot_test-srv:switch_follow_me-request instead.")))

(cl:ensure-generic-function 'req-val :lambda-list '(m))
(cl:defmethod req-val ((m <switch_follow_me-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_test-srv:req-val is deprecated.  Use turtlebot_test-srv:req instead.")
  (req m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switch_follow_me-request>) ostream)
  "Serializes a message object of type '<switch_follow_me-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'req))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'req))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switch_follow_me-request>) istream)
  "Deserializes a message object of type '<switch_follow_me-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'req) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'req) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switch_follow_me-request>)))
  "Returns string type for a service object of type '<switch_follow_me-request>"
  "turtlebot_test/switch_follow_meRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switch_follow_me-request)))
  "Returns string type for a service object of type 'switch_follow_me-request"
  "turtlebot_test/switch_follow_meRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switch_follow_me-request>)))
  "Returns md5sum for a message object of type '<switch_follow_me-request>"
  "fd72814fc41c6bccdf8759d8dea09f77")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switch_follow_me-request)))
  "Returns md5sum for a message object of type 'switch_follow_me-request"
  "fd72814fc41c6bccdf8759d8dea09f77")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switch_follow_me-request>)))
  "Returns full string definition for message of type '<switch_follow_me-request>"
  (cl:format cl:nil "string req~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switch_follow_me-request)))
  "Returns full string definition for message of type 'switch_follow_me-request"
  (cl:format cl:nil "string req~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switch_follow_me-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'req))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switch_follow_me-request>))
  "Converts a ROS message object to a list"
  (cl:list 'switch_follow_me-request
    (cl:cons ':req (req msg))
))
;//! \htmlinclude switch_follow_me-response.msg.html

(cl:defclass <switch_follow_me-response> (roslisp-msg-protocol:ros-message)
  ((res
    :reader res
    :initarg :res
    :type cl:string
    :initform ""))
)

(cl:defclass switch_follow_me-response (<switch_follow_me-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <switch_follow_me-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'switch_follow_me-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_test-srv:<switch_follow_me-response> is deprecated: use turtlebot_test-srv:switch_follow_me-response instead.")))

(cl:ensure-generic-function 'res-val :lambda-list '(m))
(cl:defmethod res-val ((m <switch_follow_me-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_test-srv:res-val is deprecated.  Use turtlebot_test-srv:res instead.")
  (res m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <switch_follow_me-response>) ostream)
  "Serializes a message object of type '<switch_follow_me-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'res))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'res))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <switch_follow_me-response>) istream)
  "Deserializes a message object of type '<switch_follow_me-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'res) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'res) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<switch_follow_me-response>)))
  "Returns string type for a service object of type '<switch_follow_me-response>"
  "turtlebot_test/switch_follow_meResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switch_follow_me-response)))
  "Returns string type for a service object of type 'switch_follow_me-response"
  "turtlebot_test/switch_follow_meResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<switch_follow_me-response>)))
  "Returns md5sum for a message object of type '<switch_follow_me-response>"
  "fd72814fc41c6bccdf8759d8dea09f77")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'switch_follow_me-response)))
  "Returns md5sum for a message object of type 'switch_follow_me-response"
  "fd72814fc41c6bccdf8759d8dea09f77")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<switch_follow_me-response>)))
  "Returns full string definition for message of type '<switch_follow_me-response>"
  (cl:format cl:nil "string res~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'switch_follow_me-response)))
  "Returns full string definition for message of type 'switch_follow_me-response"
  (cl:format cl:nil "string res~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <switch_follow_me-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'res))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <switch_follow_me-response>))
  "Converts a ROS message object to a list"
  (cl:list 'switch_follow_me-response
    (cl:cons ':res (res msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'switch_follow_me)))
  'switch_follow_me-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'switch_follow_me)))
  'switch_follow_me-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'switch_follow_me)))
  "Returns string type for a service object of type '<switch_follow_me>"
  "turtlebot_test/switch_follow_me")