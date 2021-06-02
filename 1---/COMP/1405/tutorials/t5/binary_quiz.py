# Braeden Hall
# 101143403

import random

def pow2(num):
	'''Takes in an integer and returns the largest power of two that is less than or equal to the given integer'''
	bigPow = 1

	for i in range(0,num):
		if 2**i <= num:
			bigPow = 2**i
	return bigPow

def decToBin(decNum):
	'''Takes in a decimal number as an integer and returns a string that is equivalent to that integer in binary'''
	binNum = ''
	j = pow2(decNum)

	while j >= 1:
		if j <= decNum:
			decNum-=j
			binNum+='1'
		else:
			binNum+='0'
		j/=2
	return binNum

def userBin(randNum):
	'''Displays an integer to the user and asks them to input the equivalent binary number in a string. Returns the sting'''
	while True:
		userAswr = input(f"Please input the number {randNum} in binary: ")
		if not userAswr == "":
			break
		else:
			"You have not provided an answer, try again."
	return userAswr

def main():
	score = 0
	while True:
		print(f"Score: {score}")
		randNum = random.randint(0,256)
		userAswr = userBin(randNum)
		binNum = decToBin(randNum)

		if userAswr == 'stop':
			print(f"Thanks for playing!\nFinal score: {score}")
			break
		elif userAswr == binNum:
			score+=1
			print("Congradulations, you are correct!!")
		else:
			print(f"Incorrect, you entered {userAswr} but the answer is {binNum}")
main()