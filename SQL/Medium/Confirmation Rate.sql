SELECT Signups.user_id, round(avg(CASE WHEN
action = 'confirmed' then 1 else 0 end),2) as confirmation_rate
FROM Signups
LEFT JOIN Confirmations ON Signups.user_id = Confirmations.user_id
GROUP BY Signups.user_id