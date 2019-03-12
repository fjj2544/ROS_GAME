; Auto-generated. Do not edit!


(cl:in-package test1-srv)


;//! \htmlinclude mysrv-request.msg.html

(cl:defclass <mysrv-request> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:integer
    :initform 0)
   (b
    :reader b
    :initarg :b
    :type cl:integer
    :initform 0)
   (c
    :reader c
    :initarg :c
    :type cl:integer
    :initform 0))
)

(cl:defclass mysrv-request (<mysrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mysrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mysrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test1-srv:<mysrv-request> is deprecated: use test1-srv:mysrv-request instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <mysrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-srv:a-val is deprecated.  Use test1-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <mysrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-srv:b-val is deprecated.  Use test1-srv:b instead.")
  (b m))

(cl:ensure-generic-function 'c-val :lambda-list '(m))
(cl:defmethod c-val ((m <mysrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-srv:c-val is deprecated.  Use test1-srv:c instead.")
  (c m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mysrv-request>) ostream)
  "Serializes a message object of type '<mysrv-request>"
  (cl:let* ((signed (cl:slot-value msg 'a)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'b)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'c)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mysrv-request>) istream)
  "Deserializes a message object of type '<mysrv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'a) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'b) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'c) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mysrv-request>)))
  "Returns string type for a service object of type '<mysrv-request>"
  "test1/mysrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mysrv-request)))
  "Returns string type for a service object of type 'mysrv-request"
  "test1/mysrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mysrv-request>)))
  "Returns md5sum for a message object of type '<mysrv-request>"
  "a90b140ab03fe21a95df581c56fb33ea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mysrv-request)))
  "Returns md5sum for a message object of type 'mysrv-request"
  "a90b140ab03fe21a95df581c56fb33ea")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mysrv-request>)))
  "Returns full string definition for message of type '<mysrv-request>"
  (cl:format cl:nil "int32 a~%int32 b~%int32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mysrv-request)))
  "Returns full string definition for message of type 'mysrv-request"
  (cl:format cl:nil "int32 a~%int32 b~%int32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mysrv-request>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mysrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'mysrv-request
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
    (cl:cons ':c (c msg))
))
;//! \htmlinclude mysrv-response.msg.html

(cl:defclass <mysrv-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass mysrv-response (<mysrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <mysrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'mysrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test1-srv:<mysrv-response> is deprecated: use test1-srv:mysrv-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <mysrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-srv:sum-val is deprecated.  Use test1-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <mysrv-response>) ostream)
  "Serializes a message object of type '<mysrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <mysrv-response>) istream)
  "Deserializes a message object of type '<mysrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<mysrv-response>)))
  "Returns string type for a service object of type '<mysrv-response>"
  "test1/mysrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mysrv-response)))
  "Returns string type for a service object of type 'mysrv-response"
  "test1/mysrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<mysrv-response>)))
  "Returns md5sum for a message object of type '<mysrv-response>"
  "a90b140ab03fe21a95df581c56fb33ea")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'mysrv-response)))
  "Returns md5sum for a message object of type 'mysrv-response"
  "a90b140ab03fe21a95df581c56fb33ea")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<mysrv-response>)))
  "Returns full string definition for message of type '<mysrv-response>"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'mysrv-response)))
  "Returns full string definition for message of type 'mysrv-response"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <mysrv-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <mysrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'mysrv-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'mysrv)))
  'mysrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'mysrv)))
  'mysrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'mysrv)))
  "Returns string type for a service object of type '<mysrv>"
  "test1/mysrv")