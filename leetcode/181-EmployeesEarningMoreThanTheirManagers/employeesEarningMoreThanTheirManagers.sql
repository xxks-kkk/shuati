/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/employees-earning-more-than-their-managers/#/description
 *          
 * [Problem Description]
 *          
 * 
 * The Employee table holds all employees including their managers. Every employee
 * has an Id, and there is also a column for the manager Id.
 * 
 * +----+-------+--------+-----------+
 * | Id | Name  | Salary | ManagerId |
 * +----+-------+--------+-----------+
 * | 1  | Joe   | 70000  | 3         |
 * | 2  | Henry | 80000  | 4         |
 * | 3  | Sam   | 60000  | NULL      |
 * | 4  | Max   | 90000  | NULL      |
 * +----+-------+--------+-----------+
 * Given the Employee table, write a SQL query that finds out employees who earn
 * more than their managers. For the above table, Joe is the only employee who
 * earns more than his manager.
 * 
 * +----------+
 * | Employee |
 * +----------+
 * | Joe      |
 * +----------+
 *          
 * [Comments]
 *          
 * Correlated Nested Queries. DMS p.147 is really helpful.
 *          
 * [Companies]
 */          


# Write your MySQL query statement below

select E.Name as Employee
from Employee E
where E.Salary > (select S.Salary from Employee S where S.Id = E.ManagerId )
