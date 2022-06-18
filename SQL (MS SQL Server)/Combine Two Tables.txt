SELECT firstName, LastName, city, state
FROM Person
    LEFT JOIN address on person.personID = address.personID;