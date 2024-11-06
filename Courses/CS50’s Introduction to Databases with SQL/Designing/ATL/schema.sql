CREATE TABLE Passengers (
    "id",
    "first_name" TEXT  NOT NULL,
    "last_name" TEXT NOT NULL,
    "age" INTEGER NOT NULL,
    PRIMARY KEY("id")
);
CREATE TABLE Check_Ins(
    "id",
    "passengers_id",
    "flight_id",
    "date_and_time" NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY("id")
    FOREIGN KEY("passengers_id") REFERENCES "Passengers"("id")
    FOREIGN KEY("flight_id") REFERENCES "Flights"( "id")

);
CREATE TABLE Airlines(
    "id",
    "name" TEXT NOT NULL,
    "concourse" TEXT NOT NULL CHECK ("concourse" IN ('A', 'B', 'C', 'D', 'E', 'F', 'T')),
    PRIMARY KEY("id")

);
CREATE TABLE Flights(
    "id",
    "flight_number" NUMERIC NOT NULL ,
    "airline",
    "from_airport_code" TEXT NOT NULL,
    "to_airport_code" TEXT NOT NULL ,
    "departure_date_time" NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP ,
    "arrival_date_time"NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY("id")
    FOREIGN KEY ("airline") REFERENCES "Airlines"("name")


);
