import csv
import math
from enum import Enum

class SquareType(Enum):
	START = 0
	GOAL = 1
	WALL = 2
	HAZARD = 3
	REG = 4

class Node:
	def __init__(self, sqrStr, x, y):
		self.x = x
		self.y = y

		self.parent = None
		self.pathCost = -1
		self.heuristic = -1

		if sqrStr == "S":
			self.type = SquareType.START
		elif sqrStr == "G":
			self.type = SquareType.GOAL
		elif sqrStr == "X":
			self.type = SquareType.WALL
		elif sqrStr == "H":
			self.type = SquareType.HAZARD
		elif sqrStr == "O":
			self.type = SquareType.REG

class Graph:
	def __init__(self, data):
		self.grid = []
		self.numRows = 0
		self.startState = None
		self.goalState = None

		for row in data:
			self.numCols = 0
			r = []

			for s in row:
				node = Node(s, self.numCols, self.numRows)

				if node.type == SquareType.START:
					node.pathCost = 0
					self.startState = node
				elif node.type == SquareType.GOAL:
					self.goalState = node

				r.append(node)
				self.numCols += 1

			self.numRows += 1
			self.grid.append(r)

		for row in self.grid:
			for node in row:
				if node.heuristic < 0:
					if node.type == SquareType.WALL:
						node.heuristic = float("inf")
					elif node.type == SquareType.HAZARD:
						node.heuristic = float("inf")
						nbrs = self.getNeighbours(node)
						for n in nbrs:
							n.heuristic = float("inf")
					else:
						node.heuristic = abs(node.x - self.goalState.x) + abs(node.y - self.goalState.y)

	
	def getNeighbours(self, node):
		neighbours = []

		if node.y - 1 >= 0:
			neighbours.append(self.grid[node.y - 1][node.x])

		if node.y + 1 < self.numRows:
			neighbours.append(self.grid[node.y + 1][node.x])
		
		if node.x - 1 >= 0:
			neighbours.append(self.grid[node.y][node.x - 1])

		if node.x + 1 < self.numCols:
			neighbours.append(self.grid[node.y][node.x + 1])

		return neighbours


def pathfinding(input_filepath):
	graph = None

	with open(input_filepath, newline='') as f:
		data = csv.reader(f, delimiter=',')
		graph = Graph(data)

	f.close()

	frontier = []
	frontier.append(graph.startState)
	optimal_path = []
	explored_list = []
	optimal_path_cost = 0

	leaf = None
	

	while True:
		if frontier == []:
			break

		frontier.sort(key=calcCost)
		leaf = frontier.pop(0)
		explored_list.append((leaf.y,leaf.x))

		if leaf == graph.goalState:
			break

		nbrs = graph.getNeighbours(leaf)
		for n in nbrs:
			currPathCost = leaf.pathCost + 1
			if (n not in frontier and (n.y,n.x) not in explored_list) or (n in frontier and currPathCost < n.pathCost):
				n.parent = leaf
				n.pathCost = currPathCost
				if n not in frontier:
					frontier.append(n)

	if leaf != None:
		optimal_path_cost = leaf.pathCost
		n = leaf
		while n != None:
			# print("hey")
			optimal_path.insert(0,(n.y,n.x))
			n = n.parent

	return optimal_path, explored_list, optimal_path_cost

def calcCost(node):
	return float(node.pathCost) + node.heuristic


# filepath = "Examples/Example2/input.txt"

# t = pathfinding(filepath)
# print(f"{t[0]}\n{t[1]}\n{t[2]}",)

# print(f"\n\n{len(t[1])}")
	