Select employees.employee_id, employees.name, count(*) as reports_count, round(AVG(e2.age)) as average_age
FROM employees
JOIN employees as e2 on employees.employee_id = e2.reports_to 
GROUP BY employees.employee_id, employees.name
ORDER BY employee_id