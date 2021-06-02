# Braeden Hall
# 101143403
# COMP 1405
# Assignment 1 part 3

aMaxGrade = [18,22,15,30,35,50]							# list of max grades for each assignment in order
aWeight = [0.10,0.10,0.10,0.10,0.25,0.35]		# list of the weight of each assignment in order
finalGrade = 0

Tasks = {}				# initialization of dictionary that will contain all assignments

# Assigning all assignments (name, max grade, weight) to the dictionary
for j in range(4):			
	Tasks["Assignment "+ str(j+1)] = [aMaxGrade[j],aWeight[j]]
Tasks["Midterm "] = [aMaxGrade[4],aWeight[4]]
Tasks["Final Exam"] = [aMaxGrade[5],aWeight[5]]

for task in Tasks:
	# Take inupt of grades from user
	Tasks[task].insert(0,int(input(f"What grade did u get on {task} (/{Tasks[task][0]}): ")))
	# Application of all required mathematical operations and saving them to the dictionary 
	Tasks[task].append(Tasks[task][0]/Tasks[task][1])
	Tasks[task].append(Tasks[task][2]*Tasks[task][3]*100)
	# Adds the weighted pertage of each task to the final grade
	finalGrade += Tasks[task][4]
	

print("Your grades are as follows: \n" + "="*23)
for task in Tasks:
	# Prints the grade acheived for each assignment to the user
	print(f"{task}\t{Tasks[task][3]*100:6.2f}%")
# Prints the final grade acheived in the course to the user
print("="*23 + f"\nIn this course you have achieved a final grade of {finalGrade:.2f}%\n")