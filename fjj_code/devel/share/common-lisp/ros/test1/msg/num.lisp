; Auto-generated. Do not edit!


(cl:in-package test1-msg)


;//! \htmlinclude num.msg.html

(cl:defclass <num> (roslisp-msg-protocol:ros-message)
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

(cl:defclass num (<num>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <num>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'num)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test1-msg:<num> is deprecated: use test1-msg:num instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-msg:a-val is deprecated.  Use test1-msg:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-msg:b-val is deprecated.  Use test1-msg:b instead.")
  (b m))

(cl:ensure-generic-function 'c-val :lambda-list '(m))
(cl:defmethod c-val ((m <num>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test1-msg:c-val is deprecated.  Use test1-msg:c instead.")
  (c m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <num>) ostream)
  "Serializes a message object of type '<num>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <num>) istream)
  "Deserializes a message object of type '<num>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<num>)))
  "Returns string type for a message object of type '<num>"
  "test1/num")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'num)))
  "Returns string type for a message object of type 'num"
  "test1/num")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<num>)))
  "Returns md5sum for a message object of type '<num>"
  "c8e8991925bcc343091e9b8015dc05ec")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'num)))
  "Returns md5sum for a message object of type 'num"
  "c8e8991925bcc343091e9b8015dc05ec")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<num>)))
  "Returns full string definition for message of type '<num>"
  (cl:format cl:nil "int32 a~%int32 b~%int32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'num)))
  "Returns full string definition for message of type 'num"
  (cl:format cl:nil "int32 a~%int32 b~%int32 c~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <num>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <num>))
  "Converts a ROS message object to a list"
  (cl:list 'num
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
    (cl:cons ':c (c msg))
))
