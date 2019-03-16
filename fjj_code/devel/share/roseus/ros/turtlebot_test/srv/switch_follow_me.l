;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_test::switch_follow_me)
  (if (not (find-package "TURTLEBOT_TEST"))
    (make-package "TURTLEBOT_TEST"))
  (shadow 'switch_follow_me (find-package "TURTLEBOT_TEST")))
(unless (find-package "TURTLEBOT_TEST::SWITCH_FOLLOW_ME")
  (make-package "TURTLEBOT_TEST::SWITCH_FOLLOW_ME"))
(unless (find-package "TURTLEBOT_TEST::SWITCH_FOLLOW_MEREQUEST")
  (make-package "TURTLEBOT_TEST::SWITCH_FOLLOW_MEREQUEST"))
(unless (find-package "TURTLEBOT_TEST::SWITCH_FOLLOW_MERESPONSE")
  (make-package "TURTLEBOT_TEST::SWITCH_FOLLOW_MERESPONSE"))

(in-package "ROS")





(defclass turtlebot_test::switch_follow_meRequest
  :super ros::object
  :slots (_req ))

(defmethod turtlebot_test::switch_follow_meRequest
  (:init
   (&key
    ((:req __req) "")
    )
   (send-super :init)
   (setq _req (string __req))
   self)
  (:req
   (&optional __req)
   (if __req (setq _req __req)) _req)
  (:serialization-length
   ()
   (+
    ;; string _req
    4 (length _req)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _req
       (write-long (length _req) s) (princ _req s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _req
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _req (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass turtlebot_test::switch_follow_meResponse
  :super ros::object
  :slots (_res ))

(defmethod turtlebot_test::switch_follow_meResponse
  (:init
   (&key
    ((:res __res) "")
    )
   (send-super :init)
   (setq _res (string __res))
   self)
  (:res
   (&optional __res)
   (if __res (setq _res __res)) _res)
  (:serialization-length
   ()
   (+
    ;; string _res
    4 (length _res)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _res
       (write-long (length _res) s) (princ _res s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _res
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _res (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass turtlebot_test::switch_follow_me
  :super ros::object
  :slots ())

(setf (get turtlebot_test::switch_follow_me :md5sum-) "fd72814fc41c6bccdf8759d8dea09f77")
(setf (get turtlebot_test::switch_follow_me :datatype-) "turtlebot_test/switch_follow_me")
(setf (get turtlebot_test::switch_follow_me :request) turtlebot_test::switch_follow_meRequest)
(setf (get turtlebot_test::switch_follow_me :response) turtlebot_test::switch_follow_meResponse)

(defmethod turtlebot_test::switch_follow_meRequest
  (:response () (instance turtlebot_test::switch_follow_meResponse :init)))

(setf (get turtlebot_test::switch_follow_meRequest :md5sum-) "fd72814fc41c6bccdf8759d8dea09f77")
(setf (get turtlebot_test::switch_follow_meRequest :datatype-) "turtlebot_test/switch_follow_meRequest")
(setf (get turtlebot_test::switch_follow_meRequest :definition-)
      "string req
---
string res

")

(setf (get turtlebot_test::switch_follow_meResponse :md5sum-) "fd72814fc41c6bccdf8759d8dea09f77")
(setf (get turtlebot_test::switch_follow_meResponse :datatype-) "turtlebot_test/switch_follow_meResponse")
(setf (get turtlebot_test::switch_follow_meResponse :definition-)
      "string req
---
string res

")



(provide :turtlebot_test/switch_follow_me "fd72814fc41c6bccdf8759d8dea09f77")


