# Bareden Hall
# 101143403
# COMP 1405
# Assignment 1 part 2 

import numpy			# library used for the arange function

dCm = float(input("Please input a distance in centimetres: "))
dInch = 0					# initialization of variable used for amount of inches
dFeet = 0					# initialization of variable used for amount of feet

# For loop using a float as a step
for i in numpy.arange(0,dCm,2.54): 
	# If amount of cm entered by user is more than current number of inches (1 inch = 2.54 cm)
	if dCm > i:			
		dInch+=1
	# If num inches = 12 set it back to 0
	if dInch == 12:			
		dFeet+=1
		dInch = 0

# Display answer to the user
print(f"\t{dCm:.2f}cm is approximately {dFeet}'{dInch}\".\n")