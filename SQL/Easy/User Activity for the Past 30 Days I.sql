-- Write your PostgreSQL query statement below
SELECT activity_date as day, count(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date > '2019-07-27'::date - 30 AND activity_date <= '2019-07-27'
GROUP BY activity_date