SELECT score, (SELECT count(*) FROM (SELECT DISTINCT score s FROM Scores) tmp WHERE s >= score) 'rank'
FROM Scores
ORDER BY Score desc

-- https://leetcode.com/problems/rank-scores/