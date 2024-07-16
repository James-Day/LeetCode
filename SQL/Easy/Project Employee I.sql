SELECT project_id, ROUND(AVG(experience_years), 2) as average_years
FROM Project
JOIN Employee ON Employee.employee_id = Project.employee_id
GROUP BY project_id