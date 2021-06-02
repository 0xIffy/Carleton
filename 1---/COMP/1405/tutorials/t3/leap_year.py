# Braeden Hall
# 101143403

year = int(input("Please enter a year to check if it is a leap year: "))

y = year

while y >= 4:
	if y >= 400:
		y-=400
	elif y == 100 and year%100 == 0:		#Checks to make sure that the year is not the 100th year
		break
	elif y >= 4:
		y-=4

if y == 0:
	print(f"{year} is a leap year")
else:
	print(f"{year} is not a leap year")