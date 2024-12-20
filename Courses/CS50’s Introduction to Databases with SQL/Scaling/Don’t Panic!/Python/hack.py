from cs50 import SQL

db = SQL("sqlite:///dont-panic.db")
Admin_password = input("Enter password")

db.execute(
    """
    UPDATE "users"
    SET "password" = ?
    WHERE "username" = 'admin';
    """
    , Admin_password
)
