SELECT round(count(player_id)::numeric / (SELECT count(*) FROM (SELECT count(*) FROM Activity GROUP BY player_id)), 2) AS fraction
FROM Activity
WHERE (player_id, event_date - 1) IN 
(SELECT player_id, min(event_date)
FROM Activity
GROUP BY player_id)