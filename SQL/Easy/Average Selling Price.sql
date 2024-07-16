-- Write your PostgreSQL query statement below
SELECT Prices.product_id, COALESCE(ROUND(sum(price * units::numeric) / sum(units), 2), 0) as average_price
FROM Prices
LEFT JOIN UnitsSold on UnitsSold.product_id = Prices.product_id AND UnitsSold.purchase_date >= Prices.start_date AND UnitsSold.purchase_date <= Prices.end_date
GROUP BY Prices.product_id