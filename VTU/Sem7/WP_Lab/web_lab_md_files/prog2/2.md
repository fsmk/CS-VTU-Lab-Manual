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

