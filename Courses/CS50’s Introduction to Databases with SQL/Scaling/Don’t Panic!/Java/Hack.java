import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Scanner;

public class Hack {
    public static void main(String[] args) throws Exception {
        Connection sqliteConnection = DriverManager.getConnection("jdbc:sqlite:dont-panic.db");
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter password: ");
        String  password = scanner.nextLine();
        String query =
            """
            UPDATE "users"
            SET "password" = ?
            WHERE "username" = 'admin';
            """;
            PreparedStatement sqliteStatement = sqliteConnection.prepareStatement(query);
            sqliteStatement.setString(1, password);

            sqliteStatement.executeUpdate();

            sqliteConnection.close();

    }
}
