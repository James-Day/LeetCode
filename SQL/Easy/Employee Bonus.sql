SELECT name, bonus
FROM Employee
    LEFT JOIN Bonus ON Employee.empID = Bonus.empID
WHERE bonus is NULL or bonus < 1000