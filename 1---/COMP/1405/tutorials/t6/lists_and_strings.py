# Braeden Hall
# 101143403

import random

lst = [1,2,4,2,3,1]

def product(L):
	prod = 1
	for i in L:
		prod*=i
	return prod

def makeRandomList(n):
	randLst = []
	for i in range(0,n):
		randLst.append(random.randrange(1,100))
	return randLst

def removeDuplicates(L):
	dupes = []
	for i in L:
		if not i in dupes:
			dupes.append(i)
	return dupes

def palindrome(s):
	s = s.lower().replace(' ','')
	revS = ''
	for i in range(len(s),0,-1):
		revS+=s[i-1]
	if revS == s:
		return True
	else:
		return False

def encode(s):
	return s.upper().replace('A','4').replace('B','8').replace('E','3').replace('L','1').replace('O','0').replace('S','5').replace('T','7')

def remove(s,tok):
	count = 0
	slcStart = [0]
	slcEnd = []
	newStr = ''
	while True:
		if not s.find(tok,slcStart[-1]) == -1:
			slcEnd.append(s.find(tok,slcStart[-1]))
			slcStart.append(slcEnd[-1]+len(tok))
			count+=1
		else:
			break
	for i in range(0,count):
		newStr+=s[slcStart[i]:slcEnd[i]]
	return newStr

print(f"{product([3,2,5,2])}\n{makeRandomList(5)}\n{removeDuplicates([1,5,3,1,2,7,1,3,5])}\n{palindrome('Taco Cat')}\n{encode('Bob is an elite haxor')}\n{remove('This is as it is.', 'is')}")