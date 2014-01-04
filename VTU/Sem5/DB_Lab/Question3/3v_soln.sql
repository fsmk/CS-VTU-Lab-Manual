SELECT c.dept,b.book_isbn,t.book_title,t.publisher
FROM COURSE c,BOOK_ADOPTION b,TEXT t
WHERE c.courseno=b.courseno AND b.book_isbn=t.book_isbn AND c.dept='Computer Science'AND t.publisher='Tata McGraw Hill';

#You can replace values for c.dept and t.publisher with suitable values for other departments and publishers
