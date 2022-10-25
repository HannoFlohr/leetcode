SELECT Email 
FROM Person 
GROUP BY Email
HAVING COUNT(*) > 1

--https://leetcode.com/problems/duplicate-emails/