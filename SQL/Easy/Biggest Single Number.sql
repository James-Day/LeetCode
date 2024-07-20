--Best solution
SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
) 

--My initial solution (basically here, I am scanning the table for each number, which is quite the waste)
SELECT MAX(num) AS num
FROM MyNumbers mn1
WHERE (SELECT COUNT(*) FROM MyNumbers mn2 WHERE mn2.num = mn1.num) = 1;