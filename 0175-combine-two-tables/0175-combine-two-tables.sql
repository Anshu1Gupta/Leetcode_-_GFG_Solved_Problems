# Write your MySQL query statement below
select Person.firstname, Person.lastName,Address.city,Address.state from Person Left Join Address on Person.personID=Address.personID;

# SELECT P.firstName, P.lastName, A.city, A.state
# FROM Person P LEFT JOIN Address A
# on P.personId = A.personId