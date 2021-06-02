# Braeden Hall
# 101143403
# COMP 1405
# Assignment 1 part 5

import math			# library required for the squareroot function

side = []				# initialization of the list of side lengths to be input by the user

for i in range(3):
	# Prompt user to input side lengths
	side.append(int(input(f"Please enter side {i+1} of the triangle ")))

# Calculations to determine area of triangle
s = (side[0]+side[1]+side[2])/2
area = math.sqrt(s*(s-side[0])*(s-side[1])*(s-side[2]))

# Sort side lengths from least to greatest
side.sort()
# Print the area of the triangle to the user
print(f"A triangle with the side lengths {side[0]}, {side[1]}, {side[2]} has an area of {area:.4f}\n")