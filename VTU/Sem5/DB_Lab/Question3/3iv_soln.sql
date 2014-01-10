SELECT book_title,b.book_isbn,courseno FROM TEXT t,BOOK_ADOPTION b
WHERE t.book_isbn=b.book_isbn AND courseno IN (	
	SELECT courseno FROM BOOK_ADOPTION
	WHERE courseno IN (SELECT courseno FROM COURSE WHERE dept='Computer Science')
	GROUP BY courseno HAVING count(courseno)>2)
ORDER BY book_title;
