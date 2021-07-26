/*
Enter your query here.
*/
select d.Name, count(ID)
from department d
left outer join employee e on e.DEPT_ID = d.DEPT_ID
group by d.DEPT_ID
order by count(ID) desc
