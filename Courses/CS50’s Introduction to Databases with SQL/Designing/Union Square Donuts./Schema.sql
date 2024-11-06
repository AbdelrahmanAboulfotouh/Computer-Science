CREATE TABLE Ingredients(
    "id"  ,
    "name" TEXT NOT NULL,
    "price/unit" NUMERIC NOT NULL,
    "weight_unit" TEXT NOT NULL ,
    PRIMARY KEY("id")

);
CREATE TABLE Donuts(
    "id" ,
    "name" TEXT NOT NULL,
    "Is_gluten_free?" TEXT NOT NULL ,
    "price/unit" NUMERIC NOT NULL,
    "Ingredient_id",
    PRIMARY KEY("id")
    FOREIGN KEY("Ingredient_id") REFERENCES "Ingredients"("id")

);

CREATE TABLE Orders(
    "order_number" ,
    "customer_id",
    "ordered_donuts" TEXT NOT NULL,
    PRIMARY KEY("order_number")
    FOREIGN KEY ("customer_id")     REFERENCES "Customers"("id")
);
CREATE TABLE Customers(
    "id",
    "first_name" TEXT NOT NULL,
    "last_name"TEXT NOT NULL,
    "orders" TEXT NOT NULL,
    primary key ("id")

);
