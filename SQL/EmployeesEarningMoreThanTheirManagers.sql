SELECT e.name as Employee
FROM Employee e, Employee m 
WHERE e.managerId is not NULL and e.managerId = m.id and e.salary > m.salary 

--https://leetcode.com/problems/employees-earning-more-than-their-managers/