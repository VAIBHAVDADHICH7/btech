<%-- Module 6: JSP, Expression Language (EL) & JSTL Core/Functions --%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<!DOCTYPE html>
<html>
<head><title>Student Dashboard</title></head>
<body>
    <h2>Welcome, ${sessionScope.user}</h2>
    <c:set var="courses" value="Computer Graphics,Compiler Design,Analysis of Algorithms,Advance Java" />
    <ul>
        <c:forEach var="course" items="${fn:split(courses, ',')}">
            <li><c:out value="${course}" /></li>
        </c:forEach>
    </ul>
</body>
</html>
