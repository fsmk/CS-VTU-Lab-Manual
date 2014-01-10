<?xml version = "1.0" ?> 
<xsl:stylesheet version = "1.0" 
	xmlns:xsl = "http://www.w3.org/1999/XSL/Transform" 
	xmlns = "http://www.w3.org/1999/xhtml"> 

<xsl:template match = "vtu"> 

<html>
	<head>
		<title> STYLE SHEET FOR 6b.xml </title>
	</head> 
<body> 
<h2> VTU STUDENT'S DESCRIPTIONS </h2> 

<span style = "font-style: italic; color: blue;">USN: </span>
<xsl:value-of select = "usn" /> <br /> 

<span style = "font-style: italic; color: blue;">NAME: </span> 
<xsl:value-of select = "name" /> <br /> 

<span style = "font-style: italic; color: blue;">COLLEGE: </span> 
<xsl:value-of select = "college" /> <br /> 

<span style = "font-style: italic; color: blue;">BRANCH: </span> 
<xsl:value-of select = "branch" /> <br />

<span style = "font-style: italic; color: blue;">YEAR OF JOINING: </span> 
<xsl:value-of select = "yoj" /> <br />

<span style = "font-style: italic; color: blue;">E-MAIL: </span> 
<xsl:value-of select = "email" /> <br /><hr /> 

</body>

</html> 

</xsl:template> 

</xsl:stylesheet>