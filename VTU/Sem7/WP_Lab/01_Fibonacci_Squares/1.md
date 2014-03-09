## 1. Develop and demonstrate a XHTML file that includes JavaScript script for the following problems:
### a) Input: A number n obtained using prompt
### Output: The first n Fibonacci numbers
### b) Input: A number n obtained using prompt
### Output: A table of numbers from 1 to n and their squares using alert
***

### Tags used:
     <script> - used to define a client-side script, such as a JavaScript. It contains scripting statements.
     prompt() - A prompt box is often used if you want the user to input a value before entering a page.
     document.write() - The write() method writes HTML expressions or JavaScript code to a document.
     alert() - An alert box is often used if you want to make sure information comes through to the user. 
     <h2> - The <h1> to <h6> tags are used to define HTML headings. <h2> is used to define sub-headings.
     <table> - The <table> tag defines a HTML table.
     <tr> - The <tr> element defines a table row.
     <td> - The <td> element defines a table cell.

### Code: 
*1a.html*

     <html>
     	<body>
     		<script type="text/javascript">
         		//initialize variables
				var fib1=0,fib2=1,fib=0;
				var n=prompt("enter a number");
				if(n!=null && n>0)
					{
						document.write("<h1>First " + n + " fibonacci numbers are: </h1><br>");
     					//if input is one number
     					if(n==1)
     						document.write("<h1>" + fib1 + "</h1><br>");
	     				//if input is two numbers
     					else
     						document.write("<h1>" + fib1 + "</h1><br><h1>" + fib2 + "</h1><br>");
     						//if input is more than two numbers, find the next Fibonacci number
	     					for(i=3;i<=n;i++)
     							{
     								fib=fib1+fib2;
     								document.write("<h1>" + fib + "</h1><br>");
     								fib1=fib2;
     								fib2=fib;
     							}
					}
     			else
     				alert("No proper input");
    		</script>
     	</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* Input the value and observe the output.

### Screenshots:

![input_1](1a_1.png)

![input_2](1a_2.png)

![output](1a_3.png)

![no_input](1a_4.png)

### Code: 
*1b.html*

     <html>
    	<body>
     		<script type="text/javascript">
    			//input
    			var n=prompt("enter a number");
    			if(n!=null && n>0)
    				{
    					var i=0;
    					document.write("<h2>The first " + n + " numbers and their squares are: </h2>");
    					//display in a table
     					document.write("<table border=1><tr><th><b>Number</b></th><th><b>Square</b></th></tr><br>");
    					for(i=1;i<=n;i++)
    						document.write("<tr><td>" + i + "</td><td>" + i*i + "</td></tr><br>");
    						document.write("</table>");
    				}
    			else
    				alert("No input");
    		</script>
    	</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* Input the value and observe the output.

### Screenshots:

![input_1](1a_1.png)

![input_2](1a_2.png)

![output](1b.png)

![no_input](1a_4.png)
