/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/combine-two-tables/#/description
 *          
 * [Problem Description]
 *          
 * 
 * Table: Person
 * 
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | PersonId    | int     |
 * | FirstName   | varchar |
 * | LastName    | varchar |
 * +-------------+---------+
 * PersonId is the primary key column for this table.
 * 
 * Table: Address
 * 
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | AddressId   | int     |
 * | PersonId    | int     |
 * | City        | varchar |
 * | State       | varchar |
 * +-------------+---------+
 * AddressId is the primary key column for this table.
 * 
 * Write a SQL query for a report that provides the following information for 
 * each person in the Person table, regardless if there is an address for each 
 * of those people:
 * 
 * FirstName, LastName, City, State
 *          
 * [Comments]
 *          
 *          
 *          
 * [Companies]
 */          

# Write your MySQL query statement below

# Solution 1
select FirstName, LastName, City, State from Person natural left outer join Address

# Solution 2
select FirstName, LastName, City, State from Person left outer join Address on Person.PersonId = Address.PersonId

# Solution 3
select FirstName, LastName, City, State from Person left outer join Address using (PersonId)

# Solution 4
select FirstName, LastName, City, State from Address right outer join Person using (PersonId)

# Solution 5
select FirstName, LastName, City, State from Address right outer join Person on Address.PersonId = Person.PersonId

# Solution 6
select FirstName, LastName, City, State from Address natural right outer join Person
