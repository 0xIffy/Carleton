# Braeden Hall
# 101143403

# Takes input about number from user
num = int(input("Please enter a number with multiple digits: "))

# Ensures that number input is a positive integer
if num > 0:		
	digits = 1
	# Devides number by 10 everytime through to count the amount of decimals
	while num > 10:
		num/=10
		digits+=1

	print(f"There are {digits} digits in the number {num*10**(digits-1):.0f}\n")
# Prints incase the user's input is invalid
else:
	print("Invalid input for current program\n")