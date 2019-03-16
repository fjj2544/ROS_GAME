
(cl:in-package :asdf)

(defsystem "turtlebot_test-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "switch_follow_me" :depends-on ("_package_switch_follow_me"))
    (:file "_package_switch_follow_me" :depends-on ("_package"))
  ))