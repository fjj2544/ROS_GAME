;; Auto-generated. Do not edit!


(when (boundp 'test1::num)
  (if (not (find-package "TEST1"))
    (make-package "TEST1"))
  (shadow 'num (find-package "TEST1")))
(unless (find-package "TEST1::NUM")
  (make-package "TEST1::NUM"))

(in-package "ROS")
;;//! \htmlinclude num.msg.html


(defclass test1::num
  :super ros::object
  :slots (_a _b _c ))

(defmethod test1::num
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

(setf (get test1::num :md5sum-) "c8e8991925bcc343091e9b8015dc05ec")
(setf (get test1::num :datatype-) "test1/num")
(setf (get test1::num :definition-)
      "int32 a
int32 b
int32 c

")



(provide :test1/num "c8e8991925bcc343091e9b8015dc05ec")


