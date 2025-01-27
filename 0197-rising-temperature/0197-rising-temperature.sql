# Write your MySQL query statement below
select a.id 
from weather a join
weather b
where SUBDATE(a.recordDate,1)=b.recordDate 
and a.temperature>b.temperature;