## Solution explanation

We break down the solution query line by line

```sql
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id
```

We perform cartesian product of the table to itself and get 
the following:

```
| p1.Id | p1.Email         | p2.Id | p2.Email         |
|-------|------------------|-------|------------------|
| 1     | john@example.com | 1     | john@example.com |
| 1     | john@example.com | 2     | bob@example.com  |
| 1     | john@example.com | 3     | john@example.com |
| 2     | bob@example.com  | 1     | john@example.com |
| 2     | bob@example.com  | 2     | bob@example.com  |
| 2     | bob@example.com  | 3     | john@example.com |
| 3     | john@example.com | 1     | john@example.com |
| 3     | john@example.com | 2     | bob@example.com  |
| 3     | john@example.com | 3     | john@example.com |
```

Then, we apply the `where` clause and locate the target row. Now, we use
mysql "multi-table delete" syntax: `DELETE p1` says 
only matching rows from the tables listed before the `FROM` clause are deleted, 
in this case just

```
| p1.Id | p1.Email         |
|-------|------------------|
| 3     | john@example.com |
```
