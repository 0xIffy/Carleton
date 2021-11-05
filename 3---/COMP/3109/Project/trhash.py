import math

secretX = 79 #will be an unknown value

#This will be given along with the challenge
HASHCONST = 99

def trhash(x):
	a = math.pi ** 9
	m = 0.5 * (math.sqrt(5) - 1)
	s = x * a
	# s = s - math.floor(s)
	q = math.floor(m * s)

	return q % 128

hashX = trhash(secretX)


#This they will need to figure out
y = hashX
print(f"{y}\n")

while True:
	z = trhash(y)

	print(f"{z}")
	if z == hashX:
		# print("yay\n")
		break
	else:
		y = z

	input("")

print(f"x' is {y}")