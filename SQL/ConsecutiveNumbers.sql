SELECT DISTINCT num as ConsecutiveNums
FROM Logs
WHERE (id+1, num) in (SELECT * FROM Logs) AND (id+2, num) in (SELECT * FROM Logs)

-- https://leetcode.com/problems/consecutive-numbers/