## Solution explanation

Here is the answer to the question:

```sql
select dep.Name as Department, emp.Name as Employee, emp.Salary
from Department dep, Employee emp
where emp.DepartmentId=dep.Id and
(select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary)<3
order by dep.Id, Salary desc
```

The key to understand this query relies on the subquery appeard in the `where` clause:

```sql
(select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary)<3
```

`emp.Salary` is the salary we concern (i.e. appeard inside the `select` statement)
and `select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary`
says that we want to `count` the number of salaries that are greater than the salary we concern. 
Then, `<3` means that we want this number to be smaller than three. In other words,
we allow there are at most two person's salary greater than the salary we care about 
(i.e. `emp.Salary`). The question asks us to find the top three salaries of each 
department. Imagine the fourth highest salary person in the department 
and `select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary`
will return $3$, which is equal to $3$. So, the fourth highest will not appeard
in the result set. The third highest salary person will appear in our result set
because the result of subquery in `where` clause will be $2$, which is smaller than 
$3$. This applies to the second highest and highest salary person as well.

## Extension

I spend quite some time try to understand the subquery appeard inside `where`
clause above. I think the following example is somewhat helpful to understand.

SQL includes a boolean function for testing whether a subquery has duplicate
tuples in its result. The **unique** construct returns the value true if the argument
subquery contains no duplicate tuples. Using the **unique** construct, we can write
the query “Find all courses that were offered at most once in 2009” as follows:

```sql
select T.course id
from course as T
where unique (select distinct R.course id
              from section as R
              where T.course id= R.course id and R.year = 2009);
```

Note that if a course is not offered in 2009, the subquery would return an empty
result, and the **unique** predicate would evaluate to true on the empty set.

Let's see what the result set of the above query should look like. We have
the data looks like below:

```
sqlite> select * from section where year = 2009;
course_id|sec_id|semester|year|building|room_number|time_slot_id
BIO-101|1|Summer|2009|Painter|514|B
CS-101|1|Fall|2009|Packard|101|H
CS-190|1|Spring|2009|Taylor|3128|E
CS-190|2|Spring|2009|Taylor|3128|A
CS-347|1|Fall|2009|Taylor|3128|A
EE-181|1|Spring|2009|Taylor|3128|C
PHY-101|1|Fall|2009|Watson|100|A

sqlite> select * from section;
course_id|sec_id|semester|year|building|room_number|time_slot_id
BIO-101|1|Summer|2009|Painter|514|B
BIO-301|1|Summer|2010|Painter|514|A
CS-101|1|Fall|2009|Packard|101|H
CS-101|1|Spring|2010|Packard|101|F
CS-190|1|Spring|2009|Taylor|3128|E
CS-190|2|Spring|2009|Taylor|3128|A
CS-315|1|Spring|2010|Watson|120|D
CS-319|1|Spring|2010|Watson|100|B
CS-319|2|Spring|2010|Taylor|3128|C
CS-347|1|Fall|2009|Taylor|3128|A
EE-181|1|Spring|2009|Taylor|3128|C
FIN-201|1|Spring|2010|Packard|101|B
HIS-351|1|Spring|2010|Painter|514|C
MU-199|1|Spring|2010|Packard|101|D
PHY-101|1|Fall|2009|Watson|100|A
```

Then, our result should include the course offered once in 2009 (Spring, Fall or
Summer but not either both of semsters or all three semesters). In addition, 
we should include the course not offered in 2009 at all, like "BIO-301". In 
addition, "CS-190" has two sections in "Spring 2009" and we want to use
`distinct` to eliminate this case.

However, **unique** construct is not widely implemented. For instance, in sqlite,
the **unique** is not supported. So, the following is an equivalent version of
the query above, which doesn't use **unique** construct:

```sql
sqlite> select T.course_id
   ...> from course T
   ...> where 1 >= (select count(distinct R.course_id) from section R where
   ...> T.course_id = R.course_id and R.year = 2009);
course_id
BIO-101
BIO-301
BIO-399
CS-101
CS-190
CS-315
CS-319
CS-347
EE-181
FIN-201
HIS-351
MU-199
PHY-101
```

Here, `>=` indicates the "at most once in 2009" and `distinct` eliminates
the course with two sections within one semester (i.e. "CS-190").

## Links to resources

- Please see [Database System Concepts](http://db-book.com/) section 3.8 Nested
subqueries for details. The example above is taken from 3.8.4 Test for the Absence of Duplicate Tuples.
