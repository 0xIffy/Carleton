# Braeden Hall
# 101143403

import turtle

drawing = int(input("What shape would you like to draw?\n1. Triangle\n2. Rhombus\n3. Star\n"))
color = input(f"What color would you like your {drawing} to be? (blue/orange/purple)\t")

print(f"A {color} {drawing} will now be drawn.")

turtle.up()			# Positions the turtle pointer
turtle.left(90)
turtle.forward(100)
turtle.down()
turtle.color(color)

if drawing == 1:		#Draw the triangle
	turtle.right(150)
	for i in range(3):
		turtle.forward(200)
		turtle.right(120)

elif drawing == 2:		#Draw the rhombus
	turtle.right(135)
	for i in range(4):
		turtle.forward(180)
		turtle.right(90)

elif drawing == 3:		#Draw the star
	turtle.right(162)
	for i in range(5):
		turtle.forward(150)
		turtle.right(144)
	turtle.up()

turtle.exitonclick()