SELECT ROUND(AVG(CASE WHEN order_date = customer_pref_delivery_date THEN 1 else 0 end) * 100, 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN 
(SELECT customer_id, min(order_Date) 
FROM Delivery 
GROUP BY customer_id)