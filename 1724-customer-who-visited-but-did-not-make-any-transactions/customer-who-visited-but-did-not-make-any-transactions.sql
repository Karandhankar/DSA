# Write your MySQL query statement below
Select customer_id, COUNT(*) as count_no_trans
From visits as v 
Left Join
Transactions as t
On
v.visit_id = t.visit_id
Where
t.transaction_id Is NULL
Group By customer_id;