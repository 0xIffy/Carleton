# Braeden Hall
# 101143403
# COMP 1405
# Assignment 1 part 4

num = []			# initialization of the list of numbers to be entered by the user

for i in range(4):
	num.append(int(input(f"{i+1}. Please enter a number: ")))

# Finds the largest and the smallest nums in the list and subtract them to find the difference and print to user
print(f"The largest difference is: {max(num)-min(num)}\n")