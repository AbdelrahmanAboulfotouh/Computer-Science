
CREATE TABLE "triplets" (
    "sentence_id" INTEGER,
    "char_id" INTEGER,
    "length" INTEGER
);
INSERT INTO "triplets" ("sentence_id","char_id","length")
VALUES
        (14,	98,	4),
        (114,	3,	5),
        (618,	72,	9),
        (630,	7,	3),
        (932,	12,	5),
        (2230,	50,	7),
        (2346,	44,	10),
        (3041,	14,	5);

CREATE VIEW "message" AS
SELECT substr("sentence", "char_id", "length") AS phrase
FROM "sentences"
JOIN "triplets" ON "sentences"."id" = "triplets"."sentence_id";

