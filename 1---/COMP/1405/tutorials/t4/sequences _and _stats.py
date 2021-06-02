# Braeden Hall
# 101143403

# Initializing all required variables and setting them to 0
count = 0
nSum = 0
evenSum = 0
largeNum = 0

print("Enter integers, 'stop' to exit.")
# Tells the user to input numbers until they wish to stop
while True:
	i = input("> ")
	if i == 'stop':
		break
	elif i.isdigit():
		i = int(i)
		nSum+=i
		# If i is even
		if i%2 == 0:
			evenSum+=i
		# If i is greater than the previous largest number
		if i > largeNum:
			largeNum = i
		# Increments the amount of numbers that have been input each time it loops through
		count+=1
	else:
		print("Invalid input")

# If the user chose not to input any values
if count == 0:
	print("No integers were input.")
# Prints the output to the screen
else:
	print(f"\nSum: {nSum}")
	print(f"Average: {nSum/count:.3f}")
	print(f"Even Sum: {evenSum}")
	print(f"Largest Number: {largeNum}\n")