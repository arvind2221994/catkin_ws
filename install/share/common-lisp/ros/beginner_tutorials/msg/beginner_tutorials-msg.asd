
(cl:in-package :asdf)

(defsystem "beginner_tutorials-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Gen" :depends-on ("_package_Gen"))
    (:file "_package_Gen" :depends-on ("_package"))
  ))