SELECT contest_id, ROUND((COUNT(Register.user_id)::numeric * 100) / (SELECT COUNT(*) FROM Users), 2) as percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id 