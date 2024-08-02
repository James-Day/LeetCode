-- Write your PostgreSQL query statement below
SELECT DISTINCT(l.num) AS ConsecutiveNums
FROM Logs l
LEFT JOIN logs l2 on l.id = l2.id + 1
LEFT JOIN logs l3 on l.id = l3.id + 2
WHERE l.num = l2.num AND l2.num = l3.num