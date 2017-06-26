/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/rising-temperature/#/description
 *          
 * [Problem Description]
 *          
 * Given a Weather table, write a SQL query to find all dates' Ids with higher
 * temperature compared to its previous (yesterday's) dates.
 * 
 * +---------+------------+------------------+
 * | Id(INT) | Date(DATE) | Temperature(INT) |
 * +---------+------------+------------------+
 * |       1 | 2015-01-01 |               10 |
 * |       2 | 2015-01-02 |               25 |
 * |       3 | 2015-01-03 |               20 |
 * |       4 | 2015-01-04 |               30 |
 * +---------+------------+------------------+
 * 
 * 
 * For example, return the following Ids for the above Weather table:
 * 
 * +----+
 * | Id |
 * +----+
 * |  2 |
 * |  4 |
 * +----+
 *          
 * [Comments]
 *          
 * DATE_SUB: https://dev.mysql.com/doc/refman/5.7/en/date-and-time-functions.html#function_date-add          
 *          
 * [Companies]
 */          

select W.Id
from Weather W
where W.Temperature > (select S.Temperature from Weather S where S.Date = DATE_SUB(W.Date, Interval 1 day) )
