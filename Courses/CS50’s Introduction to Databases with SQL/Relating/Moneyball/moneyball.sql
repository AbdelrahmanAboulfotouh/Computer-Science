--1.sql
SELECT "year" , ROUND(AVG("salary"),2) AS "average salary"
FROM "salaries"
GROUP BY "year"
ORDER BY "year" DESC;


--2.sql
SELECT "year", "salary"
FROM "salaries"
WHERE "player_id" IN (
    SELECT "id" FROM "players" WHERE "first_name" = "Cal" AND "last_name" = "Ripken"
)
ORDER BY "year" DESC;

--3.sql
SELECT "year","HR"
FROM "performances"
WHERE "player_id" = (
    SELECT "id" FROM "players" WHERE "first_name" ="Ken" AND "last_name" = "Griffey" AND "birth_year" = "1969"
)
ORDER BY "year" DESC;



--4.sql
SELECT "first_name", "last_name", "salary"
FROM "players"
JOIN "salaries" ON "salaries"."player_id" = "players"."id"
WHERE "year" = "2001"
ORDER BY "salary" ASC , "first_name" ASC , "last_name" ASC , "players"."id" ASC
LIMIT 50;

--5.sql
SELECT "name"
FROM "teams"
WHERE "id" IN (
    SELECT "team_id" FROM "performances" WHERE "player_id" IN(
        SELECT "id" FROM "players" WHERE "first_name" ="Satchel" AND "last_name" = "Paige"
    )
)

--6.sql

SELECT "teams"."name" ,SUM("performances"."H") AS "total hits"
FROM "teams"
JOIN "performances" ON "performances"."team_id" = "teams"."id"
WHERE "performances"."year" = "2001"
GROUP BY "performances"."team_id"
ORDER BY "total hits"DESC
LIMIT 5;

--7.sql
SELECT "first_name","last_name"
FROM "players"
WHERE "id" = (
    SELECT "player_id" FROM "salaries"
    ORDER  BY "salary" DESC
    LIMIT 1

    )
;


--8.sql
SELECT "salary"
FROM "salaries"
WHERE "player_id" = (
    SELECT "player_id" FROM "performances" WHERE "year" = "2001"
    ORDER BY "HR" DESC
    LIMIT 1
)
AND "year" = "2001";

--9.sql
SELECT "name" ,ROUND(AVG("salary"),2)AS "average salary"
FROM "teams"
JOIN "salaries" ON "salaries"."team_id" = "teams"."id"
WHERE "salaries"."year" = "2001"

GROUP BY "salaries"."team_id"
ORDER BY "average salary" ASC
LIMIT 5;

--10.sql
SELECT "first_name","last_name","salaries"."salary","performances"."HR","salaries"."year"
FROM "players"
JOIN "salaries" ON  "salaries"."player_id" = "players"."id"
JOIN "performances" ON "performances"."player_id" = "salaries"."player_id" AND "performances"."year" = "salaries"."year"
ORDER BY
        "players"."id" ASC,
        "salaries"."year" DESC,
        "performances"."HR" DESC,
        "salaries"."salary" DESC;




--11.sql
SELECT "players"."first_name","players"."last_name" ,"salaries"."salary" / "performances"."H" AS "dollars per hit"
FROM "players"
JOIN "salaries" ON "salaries"."player_id" = "players"."id"
JOIN "performances" ON "performances"."player_id" = "players"."id" AND "performances"."year" = "salaries"."year"

WHERE "salaries"."year" = "2001" AND
      "performances"."year" = "2001" AND
       "performances"."H" != 0
       
ORDER BY    "dollars per hit" ASC,
            "players"."first_name" ASC,
            "players"."last_name" ASC


LIMIT 10;

--12.sql
SELECT "first_name", "last_name"
FROM (

        SELECT "first_name","last_name","id"
        FROM (
            SELECT"players"."first_name", "players"."last_name","players"."id"
                FROM "players"
                JOIN "performances" ON "players"."id" = "performances"."player_id"
                JOIN "salaries" ON  "salaries"."player_id" = "players"."id" AND "salaries"."year" = "performances"."year"

                WHERE "salaries"."year" ="2001" AND "performances"."RBI" != 0
                ORDER BY ("salaries"."salary" / "performances"."RBI") ASC
                LIMIT 10
        )

    INTERSECT
        SELECT "first_name", "last_name","id"
        FROM (
                SELECT"players"."first_name", "players"."last_name","players"."id"
                FROM "players"
                JOIN "performances" ON "players"."id" = "performances"."player_id"
                JOIN "salaries" ON  "salaries"."player_id" = "players"."id" AND "salaries"."year" = "performances"."year"

                WHERE "salaries"."year" ="2001" AND "performances"."H" != 0
                ORDER BY ("salaries"."salary" / "performances"."H") ASC
                LIMIT 10
        )




)
ORDER BY "id";

