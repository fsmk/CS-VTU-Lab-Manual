SELECT book_title,b.book_isbn,courseno FROM text t,book_adoption b
WHERE t.book_isbn=b.book_isbn AND courseno IN (	
	SELECT courseno FROM book_adoption
	WHERE courseno IN (SELECT courseno FROM course WHERE dept='Computer Science')
	GROUP BY courseno HAVING count(courseno)>2)
ORDER BY book_title;
