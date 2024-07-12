-- Write your PostgreSQL query statement below
SELECT Activity.machine_id, ROUND(AVG(Activity2.timestamp - Activity.timestamp)::numeric, 3) AS processing_time
FROM Activity
JOIN Activity AS Activity2 ON Activity.machine_id = Activity2.machine_id 
AND Activity.process_id = Activity2.process_id 
AND Activity.activity_type = 'start' AND Activity2.activity_type = 'end' 
GROUP BY Activity.machine_id;