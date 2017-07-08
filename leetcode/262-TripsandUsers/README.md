## Solution explanation

The solution is below:

```sql
select t.Request_at Day, round(sum(status <> 'completed')/count(*),2) 'Cancellation Rate'
from Trips t join Users u on t.Client_Id = u.Users_Id 
where t.Request_at between '2013-10-01' and '2013-10-03' and u.Banned = 'No'
group by t.Request_at
```

Here is the demonstration of how solution actually works:

```
+----+-----------+-----------+---------+--------------------+----------+
| Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
+----+-----------+-----------+---------+--------------------+----------+
| 1  |     1     |    10     |    1    |     completed      |2013-10-01|
| 2  |     2     |    11     |    1    | cancelled_by_driver|2013-10-01|
| 3  |     3     |    12     |    6    |     completed      |2013-10-01|
| 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01|
| 5  |     1     |    10     |    1    |     completed      |2013-10-02|
| 6  |     2     |    11     |    6    |     completed      |2013-10-02|
| 7  |     3     |    12     |    6    |     completed      |2013-10-02|
| 8  |     2     |    12     |    12   |     completed      |2013-10-03|
| 9  |     3     |    10     |    12   |     completed      |2013-10-03| 
| 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03|
+----+-----------+-----------+---------+--------------------+----------+

+----------+--------+--------+
| Users_Id | Banned |  Role  |
+----------+--------+--------+
|    1     |   No   | client |
|    2     |   Yes  | client |
|    3     |   No   | client |
|    4     |   No   | client |
|    10    |   No   | driver |
|    11    |   No   | driver |
|    12    |   No   | driver |
|    13    |   No   | driver |
+----------+--------+--------+
```

By `Trips t join Users u on t.Client_Id = u.Users_Id ` we have

```
+----+-----------+-----------+---------+--------------------+----------+
| Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
+----+-----------+-----------+---------+--------------------+----------+
| 1  |     1     |    10     |    1    |     completed      |2013-10-01| no, client
| 2  |     2     |    11     |    1    | cancelled_by_driver|2013-10-01| yes, client
| 3  |     3     |    12     |    6    |     completed      |2013-10-01| no, client
| 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01| no, client
| 5  |     1     |    10     |    1    |     completed      |2013-10-02| no, client
| 6  |     2     |    11     |    6    |     completed      |2013-10-02| yes, client
| 7  |     3     |    12     |    6    |     completed      |2013-10-02| no, client
| 8  |     2     |    12     |    12   |     completed      |2013-10-03| yes, client
| 9  |     3     |    10     |    12   |     completed      |2013-10-03| no, client
| 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03| no, client
+----+-----------+-----------+---------+--------------------+----------+
```

Now, we apply `where` clause and get 

```
+----+-----------+-----------+---------+--------------------+----------+
| Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
+----+-----------+-----------+---------+--------------------+----------+
| 1  |     1     |    10     |    1    |     completed      |2013-10-01| no, client
| 3  |     3     |    12     |    6    |     completed      |2013-10-01| no, client
| 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01| no, client
| 5  |     1     |    10     |    1    |     completed      |2013-10-02| no, client
| 7  |     3     |    12     |    6    |     completed      |2013-10-02| no, client
| 9  |     3     |    10     |    12   |     completed      |2013-10-03| no, client
| 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03| no, client
+----+-----------+-----------+---------+--------------------+----------+
```

Then, we calculate the cancellation rate.

One thing to note is `sum(status <> 'completed')`. We want to use `sum` instead of
`count`. This can be seen below

```sql
select Status <> 'completed'
from Trips
```

The result is 

```
{"headers": ["Status <> 'completed'"], "values": [[0], [1], [0], [1], [0], [0], [0], [0], [0], [1]]}
```

Then, if we run 

```sql
select count(Status <> 'completed')
from Trips
```

Then, we have 

```
{"headers": ["count(Status <> 'completed')"], "values": [[10]]}
```

if we run 

```sql
select sum(Status <> 'completed')
from Trips
```

Then, we have

```
{"headers": ["sum(Status <> 'completed')"], "values": [[3]]}
```

Another way to write `round(sum(status <> 'completed')/count(*),2) 'Cancellation Rate'`
is `round(sum(case when t.Status like 'cancelled_%' then 1 else 0 end)/count(*),2) 'Cancellation Rate'`.
