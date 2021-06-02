Name: Braeden Hall
Student #: 101143403

Purpose: Generate reports based on the user's choices using data from the OECD.

Source Files:
	- main.c (implements the main control flow for the overall program)
	- init.c (contains functions to do with initializing the used data types)
	- print.c (contains functions to do printing reports and menues to the screen for the user to view)
	- data.c (cotains functions to do with read, editing and freeing the data stored in the created data types)

Header Files:
	- defs.h (contains the structure definitions for all custom data types used in the program. Also contains prototypes for all functions used)
	
Instructions:
- run the Makefile using the make command
- run the executable file that was created (p).

Description of Additional Reports:
	1: Top 5 and Bottom 5 countries for total number of grads per degree for all years and all genders
		- The user will choose which degree they wish to view the information for (Bachelor's, Master's, Doctorate or all)
		- Each country is be a row and there is one num grads column
		- Each cell in the num grads column shows the total number of graduates in that country for all years for the degree the user chose
		- Only the top 5 and bottom 5 countries in terms of num grads are shown
	2: Sample standard deviation for each country for all years and all genders per each degree
		- The user will choose which degree they wish to view the information for (Bachelor's, Master's, Doctorate or all)
			- In this instance choosing all degrees does not provide much useful information as for most countries the number of graduates varies significantly for each degree but I decided to include it anyway for completeness
		- Each country is a row and there is a column for the average/mean number of graduates followed by a column for the standard deviation from the mean
		- The average cell shows the mean number of graduates for that country for all genders for all the given years for degree chosen by the user
		- The standard deviation cell shows the standard deviation from the mean for that country for all genders for all the given years for degree chosen by the user