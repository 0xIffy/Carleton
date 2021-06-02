#Braeden Hall
#101143403

import random
import operator

randNums = []
ops = {'+': [operator.add,0],'-': [operator.sub,1],'*': [operator.mul,2]}
randOp = random.randrange(0,3)		#Picks a random operator

for op in ops:		#Assigns the correct string the the sign variable for the chosen operator
	if ops[op][1] == randOp:
		sign = op

for i in range(2):		# Find random numbers
	randNums.append(random.randint(1,100))

userInt = int(input(f"Please answer the following problem:\n{randNums[0]} {sign} {randNums[1]} = "))	 		#Ask user for the answer to the problem

if userInt == ops[sign][0](randNums[0],randNums[1]):
	print("Congrdulations! You are correct!")
else:
	print(f"Sorry you are incorrect. The answer was {ops[sign][0](randNums[0],randNums[1])}")