/* Exp 1: Java Implementation & Test Cases for Library Management System */
import java.util.*;

class Book {
    final String isbn;
    final String title;
    boolean issued;

    Book(String isbn, String title) {
        this.isbn = isbn;
        this.title = title;
        this.issued = false;
    }
}

class LibraryService {
    private final Map<String, Book> catalog = new HashMap<>();

    public void addBook(String isbn, String title) {
        catalog.put(isbn, new Book(isbn, title));
    }

    public boolean issueBook(String isbn) {
        Book b = catalog.get(isbn);
        if (b == null || b.issued) return false;
        b.issued = true;
        return true;
    }

    public boolean returnBook(String isbn) {
        Book b = catalog.get(isbn);
        if (b == null || !b.issued) return false;
        b.issued = false;
        return true;
    }
}

public class exp01_LibraryManagementSystem {
    public static void main(String[] args) {
        LibraryService lib = new LibraryService();
        lib.addBook("978-0132350884", "Clean Code");
        lib.addBook("978-0201633610", "Design Patterns");

        // Automated Test Cases
        assert lib.issueBook("978-0132350884") : "TC1 Failed: Should issue available book";
        assert !lib.issueBook("978-0132350884") : "TC2 Failed: Should not double-issue";
        assert lib.returnBook("978-0132350884") : "TC3 Failed: Should return issued book";
        assert !lib.issueBook("UNKNOWN") : "TC4 Failed: Should reject missing ISBN";

        System.out.println("All LibraryManagementSystem test cases passed!");
    }
}
