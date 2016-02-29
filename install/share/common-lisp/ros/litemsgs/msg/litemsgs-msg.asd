
(cl:in-package :asdf)

(defsystem "litemsgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "lite" :depends-on ("_package_lite"))
    (:file "_package_lite" :depends-on ("_package"))
  ))