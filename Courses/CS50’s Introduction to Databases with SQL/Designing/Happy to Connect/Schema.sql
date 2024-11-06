CREATE TABLE Users(
    "id" INTEGER ,
    "first_name" TEXT NOT NULL,
     "last_name" TEXT NOT NULL,
      "username" TEXT NOT NULL ,
      "password" TEXT NOT NULL,
      PRIMARY KEY("id")
);
CREATE TABLE Schools_and_Universities (
    "id" INTEGER,
    "school_name"  TEXT NOT NULL,
    "school_type" TEXT  NOT NULL,
    "school_location" TEXT  NOT NULL,
    "foundation_year" NUMERIC NOT NULL,
    PRIMARY KEY("id")

);
CREATE TABLE Companies(
    "id"INTEGER,
    "company_name" TEXT  NOT NULL,
    "company_industry" TEXT  NOT NULL,
    "company_location" TEXT  NOT NULL,
    PRIMARY KEY("id")
);

CREATE TABLE People_Connections(
    "id"INTEGER,
    "user_A",
    "user_B",
    PRIMARY KEY("id")
    FOREIGN KEY ("user_A") REFERENCES "Users"("id")
    FOREIGN KEY ("user_B") REFERENCES "Users"("id")
);
CREATE TABLE School_Connection(
    "id"INTEGER,
    "school_id",
    "student_id",
    "start_date" NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "end_date" DEFAULT CURRENT_TIMESTAMP,
    "degree_type" TEXT  NOT NULL,
    PRIMARY KEY("id")
    FOREIGN KEY ("school_id") REFERENCES "Schools_and_Universities"("id")
    FOREIGN KEY("student_id") REFERENCES "Users"("id")

);
CREATE TABLE Companies_Connection(
     "id"INTEGER,
    "company_id",
    "user_id",
    "start_date" NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "end_date" DEFAULT CURRENT_TIMESTAMP,
    "title" TEXT  NOT NULL,
    PRIMARY KEY("id")
    FOREIGN KEY ("company_id") REFERENCES "Companies"("id")
    FOREIGN KEY("company_id") REFERENCES "Users"("id")
);
