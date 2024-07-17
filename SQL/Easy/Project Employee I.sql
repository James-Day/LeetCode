SELECT project_id, ROUND(AVG(experience_years), 2) as average_years
FROM Project
JOIN Employee ON Employee.employee_id = Project.employee_id -- you should probablly use left join but in this specific schema its impossible to have a project without an employee
GROUP BY project_id