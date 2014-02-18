





## Program 10: Write a PHP program to store page views count in SESSION, to increment the count on each refresh, and to show the count on web page.
***

### Tags used:
     session_start() - Start new session or resume existing session

### Code: 
*10.php*

     <?php
     	#start session
     	session_start();
     		#check if session exists
     		if(isset($_SESSION['count']))
     			{
     				echo "Pageviews: " .$_SESSION['count'];
     				#increment the count
     				$_SESSION['count']++;
     			}
     		else
     			{
     				#if no session exists
     				$_SESSION['count']=1;
     				echo "Pageviews" .$_SESSION['count'];
     			}
     ?>
     
### Output:
*Steps for checking output-*

* Save the .php file in the folder `/var/www`
* Change the file permission of the PHP file by running the command `sudo chmod 777 10.php`
* Open a browser and in the address bar type `localhost/10.php`
* The output is displayed on the browser with the last visit time. On sucessive refresh, the timestamp gets updated.

### Screenshot:

![output_1](10.png)





## Program 11: Create a XHTML form with Name, Address Line 1, Address Line 2, and E-mail text fields. On submitting, store the values in MySQL table. Retrieve and display the data based on Name.
***

### Setting up the database (MySQL):
1. Open a terminal and run the command `mysql`
2. In the MySQL prompt run `show databases;`
3. Choose an existing database by running the command `use test;` where test is the name of an already existing database.
4. Now, create a new table by running the command `create table student(name varchar(20),addr1 varchar(20),addr2 varchar(20),email varchar(20));`
5. Run the command `exit` to exit from the MySQL prompt.

### Code: 
*11.html*

     <html>
     	<h2>Insert Info</h2>
     		<form action="insert.php">
     			Name:<input type=text name=name /><br>
     			Address Line 1:<input type=text name=addr1><br>
     			Address Line 2:<input type=text name=addr2><br>
     			Email-ID:<input type=text name=email><br>
     			<input type=submit value=insert />
     			<input type=reset value=reset />
     		</form>
     	<h2>Search Info</h2>
     		<form action="search.php">
     			Name:<input type=text name=name /><br>
     			<input type=submit value=search />
     			<input type=reset value=reset />
     		</form>
    </html>

*insert.php*

     <?php
     	# take inputs & store in local variables
     	$name=$_REQUEST['name'];
     	$addr1=$_REQUEST['addr1'];
     	$addr2=$_REQUEST['addr2'];
     	$email=$_REQUEST['email'];
     		# create a database handle
     		# mysql_connect() connects the script to MySQL server
     		# the parameters are hostname
     		$con=mysql_connect("localhost") or die('Could not connect');
     			# select a database
     			mysql_select_db("test",$con);
     				# query
     				if(mysql_query("insert into student values('$name','$addr1','$addr2','$email')"))
     					{
     						echo "Data inserted successfully!";
     					}
     		# release the database handle by closing the connection
     		mysql_close($con);
     ?>

*search.php*

     <html>
     	<h2>Search Result</h2>
     		<table border=1>
     		<tr>
     			<th>Name</th><th>Address Line 1</th><th>Address Line 2</th><th>Email-ID</th>
     		</tr>
     			<?php
     				$name=$_REQUEST['name'];
     					$con=mysql_connect("localhost") or die('Could not connect');
     						mysql_select_db("test",$con);
     							# query
     							$result=mysql_query("select * from student where name like '%".$name."%'");
     							# retrieve all rows with matches
     							while($row=mysql_fetch_array($result))
     								{
     									# display result
     									echo "<tr>";
     									echo "<td>".$row['name']."</td>";
     									echo "<td>".$row['addr1']."</td>";
     									echo "<td>".$row['addr2']."</td>";
     									echo "<td>".$row['email']."</td>";
     									echo "</tr>";
     								}
     					mysql_close($con);
     			?>
     		</table>
     </html>
     
### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .php files in the folder `/var/www/html`
* Change the file permission of the php files by running the command `sudo chmod 777 insert.php search.php`
* Make sure the database is set before executing the program.
* Open a browser and in the address bar type `localhost/html/11.html`
* Input the `name`,`Address 1`,`Address 2` and `email` which are stored in the database.
* The output is displayed on the browser by retrieving the values from the database.
* To check if the value is stored correctly in the database, 
	* Open a terminal and run `mysql`
	* Run the command `use test;`
	* Run the command `select * from student;` for fetching all the inputs stored in the database.

### Screenshot:

![input](11_1.png)

![output](11_2.png)






## Program 12: 
### Build a Rails application to accept book information viz. Accession number, title, authors, edition and publisher from a web page and store the information in a database and to search for a book with the title specified by the user and to display the search results with proper headings.
***

### Procedure for execution:

* Open a terminal and run `mkdir rails_app && cd $_` 
* Create a new app called books using the command `rails new books -d mysql`
* Run the command `cd books/config` and open the database.yml file to set mysql username and password by running the command `nano database.yml`. The *username* and *password* are required to be filled at 3 sections in the file.
* The following is a sample snippet from the database.yml file-

     adapter: mysql2  
     encoding: utf8  
     reconnect: false  
     database: books_development  
     pool: 5
     username: root  
     password: pass  
     socket: /var/run/mysqld/mysqld.sock

* Save the file by `ctrl+x` and then `y`.
* Now run `cd ..` and make sure that you are present in the `rails_app/books` directory.
* Run the command `rake db:create`
* Next, run `rails generate controller books index`
* Next, run `rails generate model book access_no:integer title:string author:string edition:integer
publisher:string`
* Run `rake db:migrate`
* Now, `cd app/views/books` and edit the file `nano index.html.erb` - 
     
* Also, edit the file `nano search.html.erb`
* Now, `cd ../../controllers` and edit the file `nano books_controller.rb`
* Next, run `cd ../../config` and edit `nano routes.rb` file.
* Finally, run `cd ..` and start the rails server by running the command `rails s`
* Open a browser and in the address bar type `localhost:3000` to check if the rails server is running. If yes, add to the URL, `localhost:3000/books/index`.
* Enter the input & on successfully inserting data, search for the same from the browser. The output is displayed in a table on the browser.

###Explaination

* The rails new command has created a Rails application in a new directory called books
* The -d options in the rails new command allows us to specify which DBMS to use. The default is sqlite. However we use mysql 
* The database.yml file has all the cofiguration information which allows our application to connect, create and modify the database
* You run rake db:create once and only once, and you run it first. Then you run rake db:migrate every time you add/change a migration
* The rails generate controller command created a lot of files and directories. We are interested in two of them for now :-
    * app/controllers/books_controller.rb
    * app/views/books/index.html.erb
* Inside Rails application, the controller file is placed inside app/controllers directory
* ####The Controller 
    * User types a URL, lets say http://localhost:3000/pages/home. If the Rails server is running, the request first reaches the Rails router.
    * ![Alt text](./l6_block_dia_vc.png)
    
    * The Router checks the config/routes.rb file to see if there is an entry matching the URL requested. In our case there is a route entry - get "pages/home". In short, the route matches incoming URL `/pages/home` to home action in Pages controller. So the request is forwarded to the Pages controller, home action.
    
    * ![Alt text](./l5_pages.png)
 

    * In our program the BooksController is a class. Intially there is an empty method index inside the class. The method is also called index action in the Books controller.
    
                class BooksController < ApplicationController
    
                def index
    
                end

    * This action serves the url /books/index when accessed. Even though the index action is an empty method, it fetches the file /apps/views/books/index.html.erb and displays it on the browser.
    
* ####The Model
    * Rails interact with the database through models. In our program we have a model called Book. This ensures that the our model is independent of the DBMS
    * When you create a model, the name is singular and the name starts with capital letter. Book, instead of Books
    * In our model we have the following attributes
    
        * access_no:integer
        * title:string
        * author:string
        * edition:integer
        * publisher:string
        
    * The `rails generate model` command also creates a migration file present under db/migrate
    * The migration file is like schema which defines the database table structure
    * rake db:migrate pushes the database changes from the migration file to the actual database
    * If you end up doing a mistake you can always undo the creation of a model using
           
                   rails destroy model Book
                 
    * If you want to delete the database from the DBMS once the model has been migrated use 
                    
                    rake db:rollback
* ####Ruby Tags
* RoR has the following 2 tags :
    * <% %> : The output of this tag will NOT be displayed on the browser
    * <%= %> : The output will be displayed on the browser   
###Code:
* **index.html.erb**

    &lt;h1>Books&#60;/h1><br>
    &lt;h3 style="text-align: center;">Add a book&lt;/h3><br>
    <%= form_tag("/books/add", :method=>"post") do %>  
    //creates a form tag in html i.e   
    &lt;form action="/books/add" method="post"> <br> 
    Access No:<%= text_field_tag(:b_access_no) %>      
    //creates a input tag whose type is text and id is :b_access_no i.e   
    &lt;input type="text" id=":b_access_no"><br>
    &lt;br>Title: <%= text_field_tag(:b_title) %>       
    //creates a input tag whose type is text and id is :b_title i.e   
    &lt;input type="text" id=":b_title"><br>
    &lt;br>Author: <%= text_field_tag(:b_author) %>        
    //creates a input tag whose type is text and id is :b_author i.e   
    &lt;input type="text" id=":b_author"><br>
    &lt;br>Edition: <%= text_field_tag(:b_edition) %>         
    //creates a input tag whose type is text and id is :b_edition i.e   
    &lt;input type="text" id=":b_edition"><br>
    &lt;br>Publisher: <%= text_field_tag(:b_publisher) %>   
    //creates a input tag whose type is text and id is :b_pubisher i.e   
    &lt;input type="text" id=":b_publisher"><br>
    &lt;br><br> 
    <%= submit_tag("Add Book") %>   
    //creates a submit button which is a input tag whose type is submit and value is Add Book i.e   
    &lt;input type="submit" value="Add Book"><br>
    <% end %> 
    //end the form tag  
    <br>
    &lt;h3 style="text-align: center;">Search for a book&lt;/h3><br>
    <%= form_tag("/books/search", :method=>"post") do %>  
    //creates a form tag in html i.e   
    &lt;form action="/books/search" method="post"><br>
    Title: <%= text_field_tag(:bs_title) %>  
    //creates a input tag whose type is text and id is :bs_title i.e   
    &lt;input type="text" id=":bs_title"><br>
    &lt;br><br>
    <%= submit_tag("Search") %>   
    //creates a submit button which is a input tag whose type is submit and value is Search i.e   
    &lt;input type="submit" value="Search"><br>
    <% end %>  
    //end the form tag
    <br>
    
* **search.html.erb**

    &lt;h1>Search Result&lt;/h1><br>
    &lt;table border=1><br>
    <% @t=Book.find_by_title(params[:bs_title]) %>  
    //RoR creates a find_by_attribute method for our model. In our case we are asked to search by title hence we are using the find_by_title function. This function takes a string as parameter. Here we are using the the value in :bs_title that was passed on using post method when the button was pressed. This function returns an array. Arrays in ruby begin with the '@' symbol
    <br>
    &lt;tr><br>
    &lt;th>Access No.&lt;/th><br>
    &lt;th>Title&lt;/th><br>
    &lt;th>Author&lt;/th><br>
    &lt;th>Edition&lt;/th><br>
    &lt;th>Publisher&lt;/th><br>
    &lt;/tr><br>
    &lt;tr><br>
    &lt;td> <%=  @t.access_no %> &lt;/td>   
    //Elements of an array are accessed by the "." operator followed by the attribute name. In our case we are accessing the access_no that was returned to the array t
    <br>
    &lt;td> <%= @t.title %> &lt;/td>  
    //we are accessing the title that was returned to the array t<br>
    &lt;td> <%= @t.author %> &lt;/td>  
    //we are accessing the author that was returned to the array t<br>
    &lt;td> <%= @t.edition %> &lt;/td>  
    //we are accessing the edition that was returned to the array t<br>
    &lt;td> <%= @t.publisher %> &lt;/td>  
    //we are accessing the publisher that was returned to the array t<br>
    &lt;/tr><br>
    &lt;/table><br>
    &lt;br>&lt;br><br>
    &lt;a href="/books/index">Back&lt;/a>  
    //A link to go back to home page
    <br>

* **books_controller.rb**

    class BooksController < ApplicationController    
    //auto-generated  code  
    def index   
    //auto-generated  code  
    end   
    //auto-generated  code<br>
    def add   
    //create a new action called add which performs the below action 
    Book.create(:access_no=>params[:b_access_no],:title=>params[:b_title],:author=>params[:b_author],:edition=> params[:b_edition],:publisher=> params[:b_publisher])   
    //the create method is used to add a vlaue to the DB. The values to be added are fetched from the post method using the param function
    redirect_to :action => 'index'  
    //once the add button is clicked this specifes which page is to be displayed.Here the index page is redisplayed  
    end  
    def search   
    //defines the search action. Just displayes search.html.erb on browser  
    end  
    end  

* **routes.rb**
    
    Books::Application.routes.draw do   
    //auto generated code  
    match "books/index" => "books#index", :as => :index   
    //use the action defined under index when request for /books/index is recieved<br>
    match  "books/add" => "books#add", :via => :post   
    //use action defined under add when request for books/add is recieved via post method<br>
    match  "books/search" => "books#search", :via => :post   
    //use action defined under search when request for books/search is recieved via post method<br>
    

### Screenshots:

![input_1](12_1.png)
![input_2](12_2.png)
![output](12_3.png)






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






## Program 2:
### a) Develop and demonstrate, using Javascript script, a XHTML document that collects the USN ( the valid format is: A digit from 1 to 4 followed by two upper-case characters followed by two digits followed by two upper-case characters followed by three digits; no embedded spaces allowed) of the user. Event handler must be included for the form element that collects this information to validate the input. Messages in the alert windows must be produced when errors are detected.
### b) Modify the above program to get the current semester also (restricted to be a number from 1 to 8).
***

### Tags used:
     finder - It is a variable which takes function() as a parameter and executes the entire code as if a single statement.
     onsubmit - The onsubmit event occurs when the submit button in a form is clicked.

### Code:
*2a.html*

     <html>
     	<body>
     			<script type="text/javascript">
     				//define a function finder to perform the search and display appropriate message
     				finder=function()
     					{
     						//get input
     						var a=document.getElementById('usn').value;
     						//find the length of the input 'a'
     						if(a.length==0)
     							{
     								alert("USN is empty");
     								return;
     							}
     						//convert the upper case input to lower case
     						var b=a.toLowerCase();
     						//check if the entered input is of the format "DAADDAADDD" where D=digit & A=alphabet
     						var str=b.search(/^[1-4][a-z][a-z][0-9][0-9][a-z][a-z][0-9][0-9][0-9]/);
     						if(str==0)
     							alert("usn is valid");
     						else
     							alert("usn is invalid");
     					}
     			</script>
     		<!-- create a form to accept input & pass the input to the function finder() on submission of the form -->
     		<form onsubmit=finder()>
     			Enter USN in Upper Case(DAADDAADDD):<input id=usn type=text><br>
     			<input type=submit value=submit>
     		</form>
     	</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* Input the value and observe the output.

### Screenshots:

![output_1](2a_1.png)

![output_2](2a_2.png)

### Code:
*2b.html*

     <html>
     	<body>
     			<script type="text/javascript">
     				finder=function()
     					{
     						//get inputs
     						var a=document.getElementById('usn').value;
     						var s=document.getElementById('sem').value;
     						if(a.length==0 || s.length==0)
     							//if one of the input is not given
     							{
     								alert("One of the field is empty");
     								return;
     							}
     						//initialize two flags (one for USN & one for SEM) to hold the status of the data entered
     						var usn_flag=0;
     						var sem_flag=0;
     						var b=a.toLowerCase();
     						//Check if USN is of the format "DAADDAADDD" where D=digit & A=alphabet
     						var str=b.search(/^[1-4][a-z][a-z][0-9][0-9][a-z][a-z][0-9][0-9][0-9]/);
     						if(str==0)
     							//if USN matches, set the flag
     							usn_flag=1;
     						//Check if SEM is between 1-8
     						str=s.search(/^[1-8]$/);
     						if(str==0)
     							//if SEM matches, set the flag
     							sem_flag=1;
     						if(!sem_flag && !usn_flag)
     							//if SEM & USN don't match the requirement
     							alert("Both USN & SEM are invalid");
     						else if(sem_flag && !usn_flag)
     							//if SEM matches & USN doesn't
     							alert("Sem is valid\nUSN is invalid");
     						else if(!sem_flag && usn_flag)
     							//if USN matches & SEM doesn't
     							alert("USN is valid\nSem is invalid");
     						else
     							//if both USN & SEM matches
     							alert("Both USN and Sem are valid");
     					}
     			</script>
     		<!-- create a form to accept inputs & pass the input to the function finder() on submission of the form -->
     		<form onsubmit=finder()>
     			Enter USN in Upper Case(DAADDAADDD):<input type=text id=usn><br>
     			Enter Sem(1-8):<input type=text id=sem><br>
     			<input type=submit value=submit>
     		</form>
     	</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* Input the value and observe the output.

### Screenshots:

![output_1](2b_1.png)

![output_2](2b_2.png)

![output_3](2b_3.png)







## Program 3:
### a) Develop and demonstrate, using Javascript script, a XHTML document that contains three short paragraphs of text, stacked on top of each other, with only enough of each showing so that the mouse cursor can be placed over some part of them. When the cursor is placed over the exposed part of any paragraph, it should rise to the top to become completely visible.
### b) Modify the above document so that when a paragraph is moved from the top stacking position, it returns to its original position rather than to the bottom.
***

### Tags used:
    z-index - The z-index property specifies the stack order of an element.

### Code:
*3a.html*

     <html>
	<head>Stack Ordering
		<title>Stack Ordering</title>
			<!-- Define styling properties -->
			<style type="text/css">
				.layer1
					{
						border:solid thick black;
						background-color:brown;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:100px;
						left:200px;
						z-index:0;
					}
				.layer2
					{
						border:solid thick black;
						background-color:gray;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:120px;
						left:220px;
						z-index:0;
					}
				.layer3
					{
						border:solid thick black;
						background-color:white;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:140px;
						left:240px;
						z-index:0;
					}
			</style>
	</head>
		<body>
			<script type=text/javascript>
				var topLayer="layer3";
				//function to place the choosen layer on the top
				function mover(toTop)
					{
						document.getElementById(topLayer).style.zIndex="0";
						document.getElementById(toTop).style.zIndex="1";
						topLayer=toTop;
					}
			</script>
			<p class=layer1 id=layer1 onMouseOver=mover('layer1');>This is the last layer</p>
			<p class=layer2 id=layer2 onMouseOver=mover('layer2');>This is the middle layer</p>
			<p class=layer3 id=layer3 onMouseOver=mover('layer3');>This is the first layer</p>
		</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* On the browser, hover the mouse over the stack layer. When the mouse is hovered out, the layer on the top will not return to it's original position. (visible for middle and last layers clearly)

### Screenshots:

![output](3a.png)

### Code:
*3b.html*

     <html>
     	<head>Stack Ordering with moveback
    		<title>Stack Ordering with moveback</title>
    			<!-- Define styling properties -->
     			<style type="text/css">
    				.layer1
					{
						border:solid thick black;
						background-color:brown;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:100px;
						left:200px;
						z-index:1;
					}
				.layer2
					{
						border:solid thick black;
						background-color:gray;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:120px;
						left:220px;
						z-index:2;
					}
				.layer3
					{
						border:solid thick black;
						background-color:white;
						padding:10px;
						width:300px;
						height:200px;
						position:absolute;
						top:140px;
						left:240px;
						z-index:3;
					}
    			</style>
     	</head>
    	<body>
    		<script type=text/javascript>
    			var topLayer="layer3";
     			var origpos;
    			//function to place the choosen layer on the top
     			function mover(toTop,pos)
     				{
     					document.getElementById(toTop).style.zIndex="4";
     					topLayer=toTop;
     					origpos=pos;
     				}
     			//function to place the choosen layer back to it's original place
      			function moveBack()
     				{
     					document.getElementById(topLayer).style.zIndex=origpos;
     				}
    		</script>
    		<p class=layer1 id=layer1 onMouseOver=mover('layer1','1'); onMouseOut=moveBack()>This is the last layer</p>
    		<p class=layer2 id=layer2 onMouseOver=mover('layer2','2'); onMouseOut=moveBack()>This is the middle layer</p>
    		<p class=layer3 id=layer3 onMouseOver=mover('layer3','3'); onMouseOut=moveBack()>This is the first layer</p>
    	</body>
     </html>

### Output:
*Steps for checking output-*

* Locate the file in the filesystem.
* `Right-click` on the file and select `open-with` firefox/iceweasel/chromium/chrome.
* On the browser, hover the mouse over the stack layer. When the mouse is hovered out, the layer on the top will return to it's original position. (visible for middle and last layers clearly)

### Screenshots:

![output](3b.png)






## Program 4:
### a) Design an XML document to store information about a student in an engineering college affiliated to VTU. The information must include USN, Name, Name of the College, Brach, Year of Joining, and e-mail id. Make up sample data for 3 students. Create a CSS style sheet and use it to display the document.
### b) Create an XSLT style sheet for one student element of the above document and use it to create a display of that element.
***

### Tags used:
     <xsl:stylesheet> - Defines that the document is an XSLT style sheet document (along with the version number and XSLT namespace attributes).
     <xsl:template> - The <xsl:template> element is used to build templates. A template contains rules to apply when a specified node is matched.
     <xsl:for-each> - This element can be used to select every XML element of a specified node-set.
     <xsl:value-of> - This element is used to extract the value of a selected node.

### Code:
*4a.xml*

     <?xml version="1.0" ?>
     	<!-- Obtain stylesheet. Note that the xml file & css file should be in the same directory/location -->
     	<?xml-stylesheet type="text/css" href="4a.css" ?>
     		<student>
     			Student 1 details:
     				<info>
    					USN:<usn>1AB10EC002</usn>
    					Name:<name>abc</name>
    					College:<coll>AB</coll>
    					Branch:<branch>ECE</branch>
    					Year Of Joining:<yoj>2010</yoj>
    					Email-ID:<email>abc@samp.com</email>
    				</info>
    			Student 2 details:
    				<info>
    					USN:<usn>1PQ10CS025</usn>
    					Name:<name>pqr</name>
    					College:<coll>PQ</coll>
    					Branch:<branch>CSE</branch>
    					Year Of Joining:<yoj>2010</yoj>
    					Email-ID:<email>pqr@samp.com</email>
    				</info>
    			Student 3 details:
    				<info>
    					USN:<usn>1XY10IS005</usn>
    					Name:<name>xyz</name>
    					College:<coll>XY</coll>
    					Branch:<branch>ISE</branch>
    					Year Of Joining:<yoj>2010</yoj>
    					Email-ID:<email>xyz@samp.com</email>
    				</info>
    		</student>

*4a.css*

     /* Define styling properties for each tag of the xml file */
     student {margin-top:15px;font-weight:bold;color:black;}
     info {display:block;margin-left:15px;color:gray;}
     usn, name {color:red;font-size:15pt;}
     coll, branch {color:blue;font-size:15pt;}
     yoj, email {color:green;font-size:15pt;}

### Output:
*Steps for checking output-*

* Locate the xml file in the filesystem.
* Make sure that the .xml & .css file are in the same directory.
* `Right-click` on the xml file and select `open-with` firefox/iceweasel/chromium/chrome.
* Observe the output on the browser.

### Code:
*4b.xml*

     <?xml version="1.0" ?>
     <!-- Obtain stylesheet. Note that the xml file & xsl file should be in the same directory/location -->
     <?xml-stylesheet type="text/xsl" href="4b.xsl" ?>
    	<student>
    		<info>
    			<usn>1PQ10CS025</usn>
    			<name>pqr</name>
    			<coll>PQ</coll>
    			<branch>CSE</branch>
    			<yoj>2010</yoj>
    			<email>pqr@samp.com</email>
    		</info>
    	</student>

*4b.xsl*

     <?xml version="1.0"?>
    	<!-- create new namespace instance -->
    	<xsl:stylesheet version="1.0"
    	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    		<!-- match all -->
    		<xsl:template match="/">
    			<html>
    				<!-- create table to display -->
    				<table border="1">
    					<tr>
    						<th>USN</th><th>Name</th><th>College</th><th>Branch</th><th>Year Of Joining</th><th>Email-ID</th>
    					</tr>
    					<xsl:for-each select="student/info">
    						<tr>
    							<!-- get each value -->
    							<td><xsl:value-of select="usn" /></td>
    							<td><xsl:value-of select="name" /></td>
    							<td><xsl:value-of select="coll" /></td>
    							<td><xsl:value-of select="branch" /></td>
    							<td><xsl:value-of select="yoj" /></td>
    							<td><xsl:value-of select="email" /></td>
    						</tr>
    					</xsl:for-each>
    				</table>
    			</html>
    		</xsl:template>
    	</xsl:stylesheet>

### Output:
*Steps for checking output-*

* Locate the xml file in the filesystem.
* Make sure that the .xml & .xsl file are in the same directory.
* `Right-click` on the xml file and select `open-with` firefox/iceweasel/chromium/chrome.
* Observe the output on the browser.

### Screenshot:

![output](4.png)






# Program 5:
## a) Write a Perl program to display various Server Information like Server Name, Server Software, Server protocol, CGI Revision etc.
## b) Write a Perl program to accept UNIX command from a HTML form and to display the output of the command executed.
***

### Tags used:
     <form> - The <form> tag is used to create a HTML form for user input.
     <input> - The <input> tag specifies an input field where the user can enter data. 
     <th> - The <th> tag defines a header cell in a HTML table.
     print<<here; (known as here-document) - used for interpolating large chunks of text and for displaying multiple lines easily. We use it for printing multiple lines on to the browser.
     use CGI - imports cgi module.
     Content-type:text/html - to pass output of script to the browser.

### Code: 
*5a.html*

     <html>
     <!-- path to perl file -->
     	<form action="http://localhost/cgi-bin/5a.pl">
     		<center>
     		<input type=submit value=Show_Server_Info />
     		</center>
     	</form>
     </html>

*5a.pl*

     #!/usr/bin/perl
     #this is a here-document
     print<<here;
     	Content-type:text/html\n\n
     	<html>
    	<center>
     	<table border=1>
     	<tr>
     		<th>ENV_VARIABLES</th><th>Value</th>
     	</tr>
     here
     #end of here document
     #display values in a table
     foreach $i(sort keys %ENV)
     	{
     		print "<tr><td>$i</td><td>$ENV{$i}</td></tr>";
     	}
     print "</table></center></html>";
     
### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 5a.pl`
* Open a browser and in the address bar type `localhost/html/5a.html`
* By clicking the `Show_Server_Info button`, the output will be displayed on the browser.

### Screenshots:

![input](5a_1.png)

![output](5a_2.png)

### Code:
*5b.html*

     <html>
     	<!-- path to perl file -->
     	<form action="http://localhost/cgi-bin/5b.pl">
          	<!-- input command name -->
          	Command:<input type=text name=com>
          		<input type=submit value=submit />
     	</form>
     </html>

*5b.pl*

     #!/usr/bin/perl
     use CGI':standard';
     #the following line is used for displaying the output of the script in the browser
     print "Content-type:text/html\n\n";
     	#take the input command from the browser and store in the variable
     	$c=param('com');
      	#process the command
     	system($c);
     exit(0);

### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 5b.pl`
* Open a browser and in the address bar type `localhost/html/5b.html`
* Enter a UNIX command as input to view the output of the command on the browser.

### Screenshots:

![input_1](5b_1.png)

![input_2](5b_2.png)

![output](5b_3.png)






# Program 6:
## a) Write a Perl program to accept the User Name and display a greeting message randomly chosen from a list of 4 greeting messages.
## b) Write a Perl program to keep track of the number of visitors visitingthe web page and to display this count of visitors, with proper headings.
***

### Tags used:
     open() - opens a file if existing otherwise creates a new one. 
     '<filename' is opened for input 
     '<filename' is opened for output starting at the beginning of the file

### Code: 
*6a.html*

     <html>
     	<!-- path to perl file -->
     	<form action="http://localhost/cgi-bin/6a.pl">
     		<center>
     			<!-- input -->
     			<h2>Enter your name:</h2>
     			<input type=text name=name />
     			<input type=submit value=submit />
     		</center>
     	</form>
     </html>     

*6a.pl*

     #!/usr/bin/perl
     use CGI;
     #create new CGI object to handle query
     $q=new CGI;
     	#take input and store in local variable
     	$cmd=$q->param('name');
     	#define various greeting messages
     	@greet=("Hello","Hai","Nice meeting you","Have a nice day");
     	#choose a message based on the length of the input
     	$index=length($cmd)%4;
     print<<here;
     	Content-type:text/html\n\n
     	<html>
     	<center>
     	<h2>$cmd, $greet[$index]</h2>
     	</center>
     	</html>
     here
     
### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 6a.pl`
* Open a browser and in the address bar type `localhost/html/6a.html`
* Enter input to view the greeting message.

### Screenshots:

![output_1](6a_1.png)

![output_2](6a_2.png)

![output_3](6a_3.png)

![output_4](6a_4.png)

### Code:
*6b.html*

     <html>
     	<form action="http://localhost/cgi-bin/6b.pl">
     		<center>
     			<input type=submit value=Show_no_of_views />
     		</center>
     	</form>
     </html>

*6b.pl*

     #!/usr/bin/perl
     #load CGI standard routines
     use CGI':standard';
     print "Content-type:text/html\n\n";
     #open a file called count.txt to store values of number of views
     open(FILE,'<count.txt');
     	#contents of file are copied to the variable
     	$count=<FILE>;
     close(FILE);
     $count++;
     #append the new incremented value to the beginning of the file
     open(FILE,'>count.txt');
     	print FILE "$count";
     print "This page has been viewed $count times";

### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 6b.pl`
* Open a `terminal`. Change directory by `cd /var/www/cgi-bin` and then run the command `touch count.txt`. This initializes an empty file to store page views.
* Run the command `sudo chmod 777 count.txt` in order to continuously update the file on every view to the browser page.
* Open a browser and in the address bar type `localhost/html/6b.html`
* By clicking `Show_no_of_views`, the number of views to the browser page is displayed and on every refresh, the value gets incremented.

### Screenshots:

![output](6b.png)






## Program 7: Write a Perl program to display a digital clock which displays the current time of the server.
***

### Tags used:
     'Refresh:1' - used to dislay the refreshed time every second
     localtime() - uses the current time.

### Code: 
*7.html*

     <html>
     	<form action="http://localhost/cgi-bin/7.pl">
     		<center>
     			<input type=submit value=Click_to_display_time>
     		</center>
     	</form>
     </html>  

*7.pl*

     #!/usr/bin/perl
     use CGI':standard';
     #refresh the display every second
     print "Refresh:1\n";
     print "Content-type:text/html\n\n";
     	($s,$m,$h)=localtime(time);
     print br "The current server time is $h:$m:$s";
     print br "In words,the time is- $h hours, $m minutes and $s seconds";
     
### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 7.pl`
* Open a browser and in the address bar type `localhost/html/7.html`
* Click the button `Click_to_display_time` to view the current time of the server.

### Screenshot:

![output_1](7.png)





## Program 8: Write a Perl program to insert name and age information entered by the user into a table created using MySQL and to display the current contents of this table.
***

### Setting up the database (MySQL):
1. Open a terminal and run the command `mysql`
2. In the MySQL prompt run `show databases;`
3. Choose an existing database by running the command `use test;` where test is the name of an already existing database.
4. Now, create a new table by running the command `create table info(name varchar(20), age integer);`
5. Run the command `exit` to exit from the MySQL prompt.

### Code: 
*8.html*

     <html>
	<form action="http://localhost/cgi-bin/8.pl">
     		Name:<input type=text name=name><br>
     		Age:<input type=text name=age><br>
     		<input type=submit value=submit />
     	</form>
     </html>

*8.pl*

     #!/usr/bin/perl
     use CGI;
     #import database module
     use DBI;
     $q=new CGI;
     	#take inputs and store in local variables
     	$nm=$q->param('name');
     	$age=$q->param('age');
     		#connect takes parameter driver_name:database_name
     		#this creates a database handle & stores it in $db
     		$db=DBI->connect("DBI:mysql:test");
     			#query
     			$str=("insert into info values('$nm',$age)");
     			#compiles the query and returns an object reference which is called statement handle
     				$q=$db->prepare($str);
     				#execute the query using statement handle
     				$q->execute();
     				$q=$db->prepare("select * from info");
     				$q->execute();
     				print<<1;
     					Content-type:text/html\n\n
     					<html>
     					<table border=1>
     					<tr><th>Name</th><th>Age</th></tr>
     					1
     				#obtain all the rows with matching patterns
     				while(($nm,$age)=$q->fetchrow())
     					{
     						print "<tr><td>$nm</td><td>$age</td></tr>";
     					}
     				print "</table></html>";
     			#release the statement handle & database handle
     		$db->disconnect;
     $q->finish;
     
### Output:
*Steps for checking output-*

* Save the .html file in the folder `/var/www/html`
* Save the .pl files in the folder `/var/www/cgi-bin`
* Change the file permission of the perl file by running the command `sudo chmod 777 8.pl`
* Make sure the database is set before executing the program.
* Open a browser and in the address bar type `localhost/html/8.html`
* Input the `name` and `age`.
* The output is displayed on the browser by storing the input in the database.
* To check if the value is stored correctly in the database, 
	* Open a terminal and run `mysql`
	* Run the command `use test;`
	* Run the command `select * from info;` for fetching all the inputs stored in the database.

### Screenshot:

![output_1](8.png)






## Program 9: Write a PHP program to store current date-time in a COOKIE and display the ‘Last visited on’ date-time on the web page upon reopening of the same page.
***

### Tags used:
     date("G:i -m/d/y") - Gives the timestamp where,
     	* G represents 24-hour format of hour without leading zeros
     	* i represents Minutes with leading zeros
     	* m represents Numeric representation of a month, with leading zeros
     	* d represents Day of the month, 2 digits with leading zeros
     	* y represents A two digit representation of a year

### Code: 
*9.php*

     <?php
     	#calculate 60 days in the future: seconds * minutes * hours * days + current time
     	$itm=60*60*24*60+time();
     	#create cookie
     	setcookie('last_visit',date("G:i -m/d/y"),$itm);
     	#check if cookie exists
     	if(isset($_COOKIE['last_visit']))
     		{
     			$visit=$_COOKIE['last_visit'];
     			echo "Your last visit was- " .$visit;
     		}
     	else
     		#no cookies
     		echo "You have some stale cookies!" ;
     ?>
     
### Output:
*Steps for checking output-*

* Save the .php file in the folder `/var/www`
* Change the file permission of the PHP file by running the command `sudo chmod 777 9.php`
* Open a browser and in the address bar type `localhost/9.php`
* The output is displayed on the browser with the last visit time. On sucessive refresh, the timestamp gets updated.

### Screenshot:

![output_1](9.png)