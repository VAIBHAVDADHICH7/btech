// Exp 1(d): Extract Site Name from Commercial URLs (www.<name>.com)
import java.util.regex.*;

public class Exp01d_UrlExtractor {
    private static final Pattern P = Pattern.compile("^www\\.([a-zA-Z0-9-]+)\\.com$");
    public static String extractSiteName(String url) {
        Matcher m = P.matcher(url.trim());
        return m.matches() ? m.group(1) : "INVALID";
    }
    public static void main(String[] args) {
        for (String u : new String[]{"www.google.com", "www.rtu.ac.in", "www.flipkart.com"})
            System.out.println(u + " -> " + extractSiteName(u));
    }
}
