CREATE TABLE meteorits (
    "name",
    "id",
    "nametype",
    "class",
    "mass",
    "discovery",
    "year",
    "lat",
    "long",
    PRIMARY KEY("id")

);
.import --csv --skip 1 meteorites.csv meteorits


UPDATE "meteorits"
SET "mass" = NULL
WHERE "mass" = '';

UPDATE "meteorits"
SET "year" = NULL
WHERE "year" = '';

UPDATE "meteorits"
SET "lat" = NULL
WHERE "lat" = '';

UPDATE "meteorits"
SET "long" = NULL
WHERE "long" = '';

--2

UPDATE "meteorits"
SET "mass" = ROUND("mass",2);


UPDATE "meteorits"
SET "lat" = ROUND("lat",2);

UPDATE "meteorits"
SET "long" = ROUND("lat",2);

--3
DELETE  FROM "meteorits"
WHERE "nametype" = "Relict";

--4

CREATE TABLE meteorites (
    "name",
    "id",
    "class",
    "mass",
    "discovery",
    "year",
    "lat",
    "long",
    PRIMARY KEY("id")

);


INSERT INTO "meteorites"("name","id","class","mass","discovery","year","lat","long")
SELECT ROW_NUMBER() OVER (
		ORDER BY "year" ASC,"name" ASC
	    )
    AS id,"name","class","mass","discovery","year","lat","long"
FROM "meteorits";

DROP TABLE "meteorits";
