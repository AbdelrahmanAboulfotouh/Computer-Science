--1.sql
SELECT "name", "city" FROM "schools" WHERE "type" = "Public School";

--2.sql
SELECT "name"
FROM "districts"
WHERE "name"  LIKE '%(non-op)';

--3.sql
SELECT AVG("per_pupil_expenditure" ) AS "Average District Per-Pupil Expenditure"
FROM "expenditures"

--4.sql
SELECT  COUNT("name"), "city"  
FROM  "schools"
WHERE  "type" = "Public School"
GROUP BY "city"
ORDER BY COUNT("name")  DESC , "city" ASC LIMIT 10 ;

--5.sql
SELECT COUNT(*) AS "PUBLIC","city"
FROM "schools"
WHERE "type" = "Public School"
GROUP BY "city"
HAVING  "PUBLIC" <= 3
ORDER BY "PUBLIC" DESC , "city" ASC;

--6.sql
SELECT "name" FROM "schools" WHERE "id" IN (
    SELECT "school_id" FROM "graduation_rates" WHERE "graduated" = 100
    );

--7.sql
SELECT "name" FROM "schools" WHERE "district_id" IN (
     SELECT "id" FROM "districts" WHERE "city" = "Cambridge" AND "name" = "Cambridge"

);

--8.sql
SELECT "name","pupils"
FROM "districts"
JOIN "expenditures"
ON "expenditures"."district_id" = "districts"."id";

--9.sql
SELECT "name"
FROM "districts"
JOIN "expenditures"
ON "expenditures"."district_id" = "districts"."id"
ORDER BY "pupils" ASC
LIMIT 1;

--10.sql
SELECT "name", "per_pupil_expenditure"
FROM "districts"
JOIN "expenditures"
ON "expenditures"."district_id" = "districts"."id"
WHERE "type" = "Public School District"
ORDER BY "per_pupil_expenditure" DESC
LIMIT 10;

--11.sql
SELECT "name","per_pupil_expenditure","graduated"
FROM "schools"
JOIN "expenditures" ON "expenditures"."district_id" = "schools"."district_id"
JOIN "graduation_rates" ON "schools"."id" = "graduation_rates"."school_id"
ORDER BY "per_pupil_expenditure" DESC , "name" ASC;

--12.sql
SELECT "name" , "per_pupil_expenditure","exemplary"
FROM "districts"
JOIN "expenditures" ON "expenditures"."district_id" = "districts"."id"
JOIN "staff_evaluations" ON "staff_evaluations"."district_id" = "districts"."id"
WHERE "districts"."type" = "Public School District"
    AND "per_pupil_expenditure" > (
        SELECT AVG("per_pupil_expenditure") FROM "expenditures"
    )
    AND "exemplary" > (
        SELECT AVG("exemplary") FROM "staff_evaluations"
    )
ORDER BY "exemplary" DESC , "per_pupil_expenditure" DESC;

--13.sql
SELECT "name","type","city","graduated"
FROM "schools"
JOIN "graduation_rates" ON "graduation_rates"."school_id" = "schools"."id";
