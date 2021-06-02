# Author Braeden Hall 
# Student#: 101143403

space = '  ' # variable to format star

# Loop for first three lines of star
for i in range(3):			
	print(space, end = '')
	for j in range(i+1):
		print("\\", end = '')
	for k in range(i+1):
		print("/", end = '')	
	print('')
	space = space.replace(' ','',1)

# Loop for last three lines of star
for i in range(3,0,-1):	
	print(space, end = '')
	for j in range(i):
		print("/", end = '')
	for k in range(i):
		print('\\', end = '')	
	print('')
	space = space + ' '