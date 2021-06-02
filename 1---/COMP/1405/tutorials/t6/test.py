def checkboard(n):
	if n>0:
		for i in range(0,n):
			if i%2 == 1:
				print(" ",end='')
			for j in range(0,n):
				print("# ",end='')
			print("\n")
	else:
		print(f"{n} is not a positive integer")

checkboard(4)