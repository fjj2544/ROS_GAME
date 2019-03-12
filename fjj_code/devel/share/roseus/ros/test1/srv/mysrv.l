;; Auto-generated. Do not edit!


(when (boundp 'test1::mysrv)
  (if (not (find-package "TEST1"))
    (make-package "TEST1"))
  (shadow 'mysrv (find-package "TEST1")))
(unless (find-package "TEST1::MYSRV")
  (make-package "TEST1::MYSRV"))
(unless (find-package "TEST1::MYSRVREQUEST")
  (make-package "TEST1::MYSRVREQUEST"))
(unless (find-package "TEST1::MYSRVRESPONSE")
  (make-package "TEST1::MYSRVRESPONSE"))

(in-package "ROS")





(defclass test1::mysrvRequest
  :super ros::object
  :slots (_a _b _c ))

(defmethod test1::mysrvRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    ((:c __c) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   (setq _c (round __c))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:c
   (&optional __c)
   (if __c (setq _c __c)) _c)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ;; int32 _c
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;; int32 _c
       (write-long _c s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _c
     (setq _c (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass test1::mysrvResponse
  :super ros::object
  :slots (_sum ))

(defmethod test1::mysrvResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass test1::mysrv
  :super ros::object
  :slots ())

(setf (get test1::mysrv :md5sum-) "a90b140ab03fe21a95df581c56fb33ea")
(setf (get test1::mysrv :datatype-) "test1/mysrv")
(setf (get test1::mysrv :request) test1::mysrvRequest)
(setf (get test1::mysrv :response) test1::mysrvResponse)

(defmethod test1::mysrvRequest
  (:response () (instance test1::mysrvResponse :init)))

(setf (get test1::mysrvRequest :md5sum-) "a90b140ab03fe21a95df581c56fb33ea")
(setf (get test1::mysrvRequest :datatype-) "test1/mysrvRequest")
(setf (get test1::mysrvRequest :definition-)
      "int32 a
int32 b
int32 c
---
int32 sum

")

(setf (get test1::mysrvResponse :md5sum-) "a90b140ab03fe21a95df581c56fb33ea")
(setf (get test1::mysrvResponse :datatype-) "test1/mysrvResponse")
(setf (get test1::mysrvResponse :definition-)
      "int32 a
int32 b
int32 c
---
int32 sum

")



(provide :test1/mysrv "a90b140ab03fe21a95df581c56fb33ea")


