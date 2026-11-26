// Module 5: Java Servlet Lifecycle, Session Handling & Filter (requires jakarta/javax.servlet API)
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Exp05_LoginServletAndFilter extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String user = req.getParameter("username");
        HttpSession session = req.getSession(true);
        session.setAttribute("user", user);
        resp.setContentType("text/html");
        resp.getWriter().println("<h2>Welcome, " + user + " (Session: " + session.getId() + ")</h2>");
    }
}
