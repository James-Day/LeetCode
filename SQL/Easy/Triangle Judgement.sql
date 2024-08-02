SELECT x,y,z, case WHEN (x + y > z  AND y + z > x AND x + z > y) then 'Yes' ELSE 'No' end as triangle
FROM Triangle