SELECT substring(trans_date::varchar, 1,7) as month, --to_char(trans_date, 'YYYY-MM')
country,
count(*) as trans_count,
sum(CASE WHEN state = 'approved' then 1 else 0 end) as approved_count,
sum(Transactions.amount) as trans_total_amount,
sum(CASE WHEN state = 'approved' then amount else 0 end) as approved_total_amount
FROM Transactions
GROUP BY country, month