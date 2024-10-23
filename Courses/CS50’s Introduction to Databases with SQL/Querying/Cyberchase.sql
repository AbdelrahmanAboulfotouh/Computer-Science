/*
For each of the following questions, you should write a single SQL query that outputs the results specified by each problem.
Your response must take the form of a single SQL query. 
You should not assume anything about the ids of any particular episodes:
    your queries should be accurate even if the id of any particular episode were different.
 Finally, each query should return only the data necessary to answer the question:
    if the problem only asks you to output the names of episodes, 
    for example, then your query should not also output each episodes’s air date.

*/

-- 1)In 1.sql, write a SQL query to list the titles of all episodes in Cyberchase’s original season, Season 1.
SELECT "title"  
FROM "episodes" 
WHERE "season" = 1;

--2)In 2.sql, list the season number of, and title of, the first episode of every season.
SELECT "season", "title"  
FROM "episodes" 
WHERE "episode_in_season" = 1;

--3)In 3.sql, find the production code for the episode “Hackerized!”.
SELECT "production_code" 
FROM "episodes" 
WHERE "title" ="Hackerized!";

--4)In 4.sql, write a query to find the titles of episodes that do not yet have a listed topic.
SELECT "title" 
FROM "episodes" 
WHERE "topic" IS NULL ;

--5)In 5.sql, find the title of the holiday episode that aired on December 31st, 2004.
SELECT "title" 
FROM "episodes" 
WHERE "air_date" = '2004-12-31';

--6)In 6.sql, list the titles of episodes from season 6 (2008) that were released early, in 2007.
SELECT "title" 
FROM "episodes" 
WHERE "season" = 6 AND "air_date" LIKE '2007%';

--7)In 7.sql, write a SQL query to list the titles and topics of all episodes teaching fractions.
SELECT "title", "topic" 
FROM "episodes" 
WHERE "topic" LIKE '%Fractions%';

/*8)In 8.sql, write a query that counts the number of episodes released in the last 6 years, from 2018 to 2023, inclusive.
You might find it helpful to know you can use BETWEEN with dates, such as BETWEEN '2000-01-01' AND '2000-12-31'.*/
SELECT COUNT("title") as " Number of episodes released in the last 6 years"  
FROM "episodes"  
WHERE "air_date" BETWEEN '2018%' AND '2024%';

--9)In 9.sql, write a query that counts the number of episodes released in Cyberchase’s first 6 years, from 2002 to 2007, inclusive.
SELECT COUNT("title") as " Number of episodes released in Cyberchase’s first 6 years"  
FROM "episodes"  
WHERE "air_date" BETWEEN '2002%' AND '2008%';

--10)In 10.sql, write a SQL query to list the ids, titles, and production codes of all episodes. Order the results by production code, from earliest to latest.
SELECT "id", "title","production_code" 
FROM "episodes" 
ORDER BY "production_code" ASC ;

--11)In 11.sql, list the titles of episodes from season 5, in reverse alphabetical order.
SELECT "title" 
FROM "episodes" 
WHERE "season" = 5 
ORDER BY "title" DESC;

--12)In 12.sql, count the number of unique episode titles.
SELECT COUNT(DISTINCT "title") 
FROM "episodes" ;

/*13)In 13.sql, write a SQL query to explore a question of your choice. This query should:
Involve at least one condition, using WHERE with AND or OR*/
SELECT * FROM "episodes" 
WHERE "episode_in_season" BETWEEN 1 AND 10   AND  "topic" IS NULL 
ORDER BY  "episode_in_season" ASC ;













