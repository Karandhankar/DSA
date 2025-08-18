# Write your MySQL query statement below
Select e.name , b.bonus
from Employee as e
Left Join Bonus as b
on e.empId = b.empId 
where b.bonus < 1000
or b.bonus is null;