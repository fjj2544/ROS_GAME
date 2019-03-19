
(cl:in-package :asdf)

(defsystem "msg_demo-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "srv_demo" :depends-on ("_package_srv_demo"))
    (:file "_package_srv_demo" :depends-on ("_package"))
  ))