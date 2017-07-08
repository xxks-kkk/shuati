## Solution explanation

Here is the answer to the question:

```sql
select Email
from Person
group by Email
having count(Email)>1
```

The key point for this question lies in the understanding of `having` clause:

At times, it is useful to state a condition that applies to groups rather than to
tuples. For example, we might be interested in only those departments where the
average salary of the instructors is more than $42,000. This condition does not
apply to a single tuple; rather, it applies to each group constructed by the group
by clause. To express such a query, we use the **having** clause of SQL. SQL applies
predicates in the **having** clause after groups have been formed, so aggregate
functions may be used. We express this query in SQL as follows:

```sql
select dept name, avg (salary) as avg salary
from instructor
group by dept name
having avg (salary) > 42000;
```

Here is the evaluation order for a query contains **where**, **group by**, and 
**having**:

1. As was the case for queries without aggregation, the **from** clause is first
evaluated to get a relation.

2. If a **where** clause is present, the predicate in the **where** clause is applied on
the result relation of the from clause.

3. Tuples satisfying the **where** predicate are then placed into groups by the
**group by** clause if it is present. If the **group by** clause is absent, the entire
set of tuples satisfying the **where** predicate is treated as being in one group.

4. The **having** clause, if it is present, is applied to each group; the groups that
do not satisfy the **having** clause predicate are removed.

5. The **select** clause uses the remaining groups to generate tuples of the result
of the query, applying the aggregate functions to get a single result tuple for
each group.

To illustrate the use of both a **having** clause and a **where** clause in the same
query, we consider the query “For each course section offered in 2009, find the
average total credits (tot cred) of all students enrolled in the section, if the section
had at least 2 students.”

```sql
select course id, semester, year, sec id, avg (tot cred)
from takes natural join student
where year = 2009
group by course id, semester, year, sec id
having count (ID) >= 2;
```

## Links to resources

- Please see [Database System Concepts](http://db-book.com/) section 3.7.3 The
Having Clause for the details.

