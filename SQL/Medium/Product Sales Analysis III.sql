--my original solution (worse because the subquery is calculated each time even though its the exact same data each time, obviously optimizations in the explain plan end up giving similar run times for table size of 10,000 but maybe for bigger tables this is important! )
select  product_id, year as first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN
    (Select product_id, min(year) AS first_year
    FROM Sales
    GROUP BY product_id)

--ptentially better solution
select s1.product_id,first_year, quantity, price
from Sales s1
join (select product_id, min(year) as first_year from Sales group by product_id) s2
on s1.product_id = s2.product_id and s1.year=s2.first_year