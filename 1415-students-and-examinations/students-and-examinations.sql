# Write your MySQL query statement below
Select s.student_id, s.student_name,
su.subject_name, COUNT(e.student_id) as attended_exams
From




Students as s
CROSS JOIN
Subjects as su
LEFT JOIN
Examinations as e
ON
s.student_id = e.student_id AND
su.subject_name = e.subject_name

Group BY s.student_id, s.student_name, su.subject_name
Order By s.student_id, su.subject_name