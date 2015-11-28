#Network Simulation using ns-2  
Copy the programs and run then using command 'ns filename.tcl'.    
It will generate Two files one is Nam file and the Other is Trace file.  
Run the AWK scripts on the trace file(s).  
Output should be displayed on the Terminal.  

#Steps to execute  
1.Save the programs with .tcl extension.  
2.$ns filename.tcl, to run ns on the file.  
3.Nam file starts automatically, run AWK on the Trace files.  
4.$awk -f filename.awk filename.tr, to run AWK on the file.  
(optional)for the 5th program:  
	-$awk -f filename.awk filename1.tr>file1  
	-$awk -f filename.awk filename2.tr>file2 
	-$xgraph file1 file2
