# Author Braeden Hall 
# Student#: 101143403

# take input from user for bill info
bill = float(input('What is the amount of the bill? '))
tip = float(input('What percentage would you like to tip? '))/100

# display info from user
print(f"A {tip*100:.2f}% tip on a bill of ${bill:.2f} equals ${bill*tip:.2f}")
print(f"The total bill will be ${bill+tip*bill:.2f}")