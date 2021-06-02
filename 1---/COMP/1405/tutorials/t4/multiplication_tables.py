# Braeden Hall
# 101143403

# Takes input from user
rows = int(input("Enter a number (1-9): "))

# Displays the top row of all the numbers with column names
for i in range(rows):
	if i == 0:
		print("  |",end='')
	print(f"{i+1:^9}|",end='')
print("\n  " + "-"*10*rows,end='-')

# Creates a new row for the multiplication table
for i in range(rows):
	print("\n" + f"{i+1:>2}|",end='')
	# Fills each column with the correct product for each multiplication operation
	for j in range(rows):
		print(f"{(i+1)*(j+1):^9}|",end='')
print("\n")