# Braeden Hall
# 101143403

from random import randrange

def generateRandomGrid(n):
	grid = []
	for i in range(n):
		lst = []
		for j in range(n):
			lst.append(randrange(1,100))
		grid.append(lst)
	return grid
# print(generateRandomGrid(9))
def searchGrid(g):
	small=g[0][0]
	for lst in g:
		lst.sort()
		if lst[0] < small:
			small = lst[0]
	return small
print(searchGrid(generateRandomGrid(4)))