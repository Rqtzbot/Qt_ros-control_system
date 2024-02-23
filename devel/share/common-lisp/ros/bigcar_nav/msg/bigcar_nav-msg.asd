
(cl:in-package :asdf)

(defsystem "bigcar_nav-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "target_msg" :depends-on ("_package_target_msg"))
    (:file "_package_target_msg" :depends-on ("_package"))
  ))