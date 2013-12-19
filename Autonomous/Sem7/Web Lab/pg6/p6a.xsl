<?xml version = "1.0" ?>
<xsl:stylesheet version = "1.0"
	xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
	xmlns = "http://www.w3.org/1999/xhtml">

<xsl:template match="vtu">
	<h2> Students </h2>
	<xsl:for-each select = "student">
		<span style = "color: red"> USN </span> <br />
		<xsl:value-of select = "usn" />

		<span style = "color: red"> Name </span> <br />
		<xsl:value-of select = "name" />

		<span style = "color: red"> AGE </span> <br />
		<xsl:value-of select = "age" />
	</xsl:for-each>
</xsl:template>
</xsl:stylesheet>