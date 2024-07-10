SELECT customer_id, count(*) as count_no_trans
FROM Visits
    LEFT JOIN Transactions on Visits.visit_id = Transactions.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id