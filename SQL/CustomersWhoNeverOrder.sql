SELECT c.name AS Customers FROM Customers c
LEFT JOIN Orders o ON (o.customerId = c.id) 
WHERE o.id IS NULL 

--https://leetcode.com/problems/customers-who-never-order/