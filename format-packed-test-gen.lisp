; Copyright 2020 Fabian Stiewitz <fabian@stiewitz.pw>
;
; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU Lesser General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
;
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU Lesser General Public License for more details.
;
; You should have received a copy of the GNU Lesser General Public License
; along with this program.  If not, see <https://www.gnu.org/licenses/>.
(defparameter *sizes* '(1 2 4))
(defparameter *types* (list "uint8_t" "uint16_t" "uint32_t"))
(defparameter *var-names* (loop for i from (char-code #\a) to (char-code #\z)
                                collect (code-char i)))

(defmacro for-aligned (packed-size size (start end) &body body)
  (if (<= size packed-size)
      (let ((i (gensym)))
        `(loop for ,i from 0 to ,(- packed-size size)
               do (let ((,start (* ,i 8))
                        (,end (1- (* (+ ,i ,size) 8))))
                    ,@body)))))

(defmacro for-same (packed-size size (start end) &body body)
  (if (<= size packed-size)
      (let ((i (gensym))
            (j (gensym))
            (k (gensym)))
        `(loop for ,i from 0 to ,(- packed-size size)
               do (loop for ,j from 0 below (* ,size 8)
                        for ,start = (+ ,j (* ,i 8))
                        do (loop for ,k from 0 to (1- (- (* ,size 8) ,j))
                                 for ,end = (+ ,start ,k)
                                 do (progn ,@body)))))))

(defmacro for-unaligned (packed-size size (start end) &body body)
  (if (<= size packed-size)
      (let ((j (gensym))
            (o (gensym))
            (k (gensym)))
        `(loop for ,start from 0 to ,(* 8 (1- packed-size))
                unless (eq 0 (mod ,start 8))
                  do (loop for ,j from 1 to ,size
                           when (< (+ ,start (* ,j 8)) (* ,packed-size 8))
                             do (loop with ,o = (- 8 (mod ,start 8))
                                      for ,k from ,o to (1- (+ ,o (* ,j 8)))
                                      do (let ((,end (+ ,start ,k)))
                                           ,@body)))))))

(defvar *random-tests* 3)

(defun random-tests (start end)
  (loop for i from 1 to *random-tests*
        collect (let ((val (random (ash 1 (1+ (- end start))))))
                  (list val (ash val start)))))

(defun one-val (size)
  (1- (ash 1 (1+ size))))

(defun one-test (start end)
  (let ((v (one-val (- end start))))
    (ash v start)))

(defun print-test (type start end val result)
  (format t "assert((Packed<~A>().apply<~A,~A>(~A).value == ~Au));~%" type start end val result))

(defun unique (l)
  (loop for v in l
        for c = (cdr l) then (cdr c)
        unless (find v c :test 'equal)
          collect v))

(defun print-tests (type start end)
  (dolist (v (unique (append (list (list (one-val (- end start)) (one-test start end))
                            (list 0 0))
                      (random-tests start end))))
    (print-test type start end (car v) (cadr v)))
  (format t "~%"))

(defmacro make-tests ()
  `(progn ,@(loop for size in *sizes*
                  for type in *types*
                  append (loop for i from 1 to 1
                               append `((for-aligned ,size ,i (s e) (print-tests ,type s e))
                                        (for-same ,size ,i (s e) (print-tests ,type s e))
                                        (for-unaligned ,size ,i (s e) (print-tests ,type s e)))))))

(defun make-test-file (path)
  (with-open-file (fd path :direction :output :if-exists :supersede)
    (let ((*standard-output* fd))
      (make-tests))))

(make-test-file "packed-test.cpp")

(defun make-struct (vars)
  (format t "struct Test {~%~:{~A ~A {};~%~}Test() = default;~%
Test(~:{~A ~A~:^, ~}): ~:{~A(~A)~:^, ~} {}~%} t {};~%"
          vars
          (loop for (a b) in vars
                collect (list a (concatenate 'string (list b #\1))))
          (loop for (a b) in vars
                collect (list b (concatenate 'string (list b #\1))))))
