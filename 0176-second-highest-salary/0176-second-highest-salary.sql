-- SELECT MAX(salary) as SecondHighestSalary
-- FROM Employee
-- WHERE salary < (
--     SELECT MAX(salary) FROM Employee
-- );

with high_Sal as (
    select salary,Dense_Rank() over (
    order by salary desc
) SecondHighestSalary from Employee
)
select max(salary) as SecondHighestSalary from high_Sal where SecondHighestSalary=2;