# Braeden Hall
# 101143403

import turtle

lines = int(input("Enter a integer: "))

# Positions the turtle pointer
turtle.left(90)
# Increase speed of turtle
turtle.speed(5)

lineLength = 5		# set initial length of line

# Draws lines increasing the length of the line by 5 eact time
for i in range(lines):
	turtle.forward(lineLength)
	turtle.right(90)
	lineLength+=5

turtle.exitonclick()