SELECT query_name, ROUND(AVG(Queries.rating::numeric / position), 2) AS quality, ROUND(AVG(CASE WHEN rating < 3 Then 1 else 0 end) * 100::numeric, 2) AS poor_query_percentage 
FROM Queries
WHERE query_name is NOT NULL
GROUP BY query_name