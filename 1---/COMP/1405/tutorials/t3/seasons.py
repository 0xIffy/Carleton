# Braeden Hall
# 101143403

import sys		#Allows use of exit command

print("Welcome to season checker!\nPlease input the date that you would like to check")
month = int(input("Month: "))
day = int(input("Day: "))

Dates = {"January": [1,31], "Febuary": [2,28], "March": [3,31], "April": [4,30], "May": [5,31], "June": [6,30], "July": [7,31], "August": [8,31], "September": [9,30], "October": [10,31], "November": [11,30], "December": [12,31]}		#List of months and their maximum number of days

Seasons = {"Spring": [3,20,6,20], "Summer": [6,21,9,22], "Fall": [9,23,12,20], "Winter": [12,21,3,19]}		#Range of the seasons (month,day,month,day)

for date in Dates:		#Finds the string name for the month that the user entered
	if Dates[date][0] == month:
		strMonth = date
		break
else:
	print("Sorry you did not enter a valid month.\nThe program will now close.")
	sys.exit()

if day > Dates[strMonth][1] or day <= 0:		#Checks that the day entered is valid for the given month
	print(f"Sorry, you did not enter a valid day in {strMonth}.\nThe program will now close.")
	sys.exit()
else:			#Set the season that the date is in
	if (month == 12 and day >= 21) or (month <= 3 and day <= 19):
		szn = "Winter"
	elif (month >= 3 and day >= 20) or (month <= 6 and day <= 20):
		szn = "Spring"
	elif (month >= 6 and day >= 21) or (month <= 9 and day <= 22):
		szn = "Summer"
	elif (month >= 9 and day >= 23) or (month <= 12 and day <= 20):
		szn = "Fall"
	print(f"{strMonth} {day} is in the season of {szn}")