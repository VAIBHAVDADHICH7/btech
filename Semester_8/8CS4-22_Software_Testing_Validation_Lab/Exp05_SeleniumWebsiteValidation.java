// Exp 5: Automated Website Validation using Selenium WebDriver
import org.openqa.selenium.*;
import org.openqa.selenium.chrome.ChromeDriver;

public class Exp05_SeleniumWebsiteValidation {
    public static void main(String[] args) {
        WebDriver driver = new ChromeDriver();
        try {
            driver.get("https://example.com");
            String title = driver.getTitle();
            if (!title.contains("Example")) {
                throw new AssertionError("Unexpected title: " + title);
            }
            System.out.println("Selenium Validation Passed! Title: " + title);
        } finally {
            driver.quit();
        }
    }
}
