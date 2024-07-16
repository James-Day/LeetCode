-- Write your PostgreSQL query statement below
SELECT Employee2.name
FROM Employee
JOIN Employee AS Employee2 ON Employee.managerId = Employee2.id
GROUP BY Employee.managerID, Employee2.name
HAVING Count(Employee2.id) >= 5
