## Solution explanation

There are a couple of ways to solve this problem. Let's take a look one by one.

### With variables

```sql
SET @rank = 0;
SET @prev = -1;

SELECT
  Score,
  (@rank := @rank + (@prev <> (@prev := Score))) as Rank
FROM
  Scores
ORDER BY Score desc
```

We use [User-Defined Variables in MySQL](https://dev.mysql.com/doc/refman/5.7/en/user-variables.html)
in this solution. Several highlights:

- User variables are written as `@var_name`. We can use `SET` key word
to initialize our variables.

- `(@rank := @rank + (@prev <> (@prev := Score)))` says that we increment
`@rank` variable by `1` when `(@prev <> (@prev := Score))` condition is
evaluated to true. 

In fact, this solution can be written in a more compact form:

```sql
SELECT
  Score,
  @rank := @rank + (@prev <> (@prev := Score)) Rank
FROM
  Scores,
  (SELECT @rank := 0, @prev := -1) init
ORDER BY Score desc
```

Here, we put our variable declaration and initialization inside `FROM` clasue.
`SELECT @rank := 0, @prev := -1` is [a typical way](https://dev.mysql.com/doc/refman/5.7/en/assignment-operators.html#operator_assign-value) 
to initialize the variables in a query. In addition, we omit `AS` keyword as well.

### Without variables

```sql
SELECT
  Score,
  (SELECT count(distinct Score) FROM Scores WHERE Score >= s.Score) Rank
FROM Scores s
ORDER BY Score desc
```

In this solution we count for each score, how many `s.Score` we are greater or
equal to.
