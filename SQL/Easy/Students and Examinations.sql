SELECT Students.student_id, Students.student_name, Subjects.subject_name, count(Examinations.subject_name) AS attended_exams
FROM Students
JOIN Subjects on TRUE
LEFT JOIN Examinations ON Examinations.student_id = students.student_id
AND Examinations.subject_name = Subjects.subject_name
GROUP BY Students.student_id, Students.student_name, Subjects.subject_name
ORDER BY Students.student_id ASC, Subjects.subject_name ASC; --this line is optional since these would order like this by default anyway.