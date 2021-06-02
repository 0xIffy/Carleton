# Braeden Hall
# 101143403

def readStats(f):
	'''Receives: A .csv file to containing player statistics
		 Does: Reads the information and creates a 2D list of all of the players and their stats
		 Returns: A 2D list that was created if the file is found or an empty list otherwise'''


	Players = []		# List that will contain all players and player stats


	try:
		file = open(f, 'r')
		lines = file.readlines()
		lines.pop(0)		# Removes the line containing column headers from the list


		for line in lines:
			# Removes the newline character from the end of each line and creates a list of stats for each player
			player = line.replace('\n','').split(',')

			for i in range(0,8):
				# Converts all the numbers read as strings into integers for every player
				player[3+i] = int(player[3+i])

			# Appends each new list of player stats to the main list of all players
			Players.append(player)


		file.close()

		return Players

	except FileNotFoundError:
		print(f'The file {f} does not exist')

		return Players

def statsForPlayer(players,name):
	'''Receives: The 2D list of all stats and a string with a players name
		 Does: Searches the list for the line of stats with a specified name
		 Returns: The list of stats associated with the player if the name is found or an empty list otherwise'''


	for player in players:
		if player[0] == name:
			return player

	else:
		return []

def filterByPos(players,pos):
	'''Receives: The 2D list of all stats and a string with a players position
		 Does: Searches the list for all players with the specified position and appends them to a new 2D list
		 Returns: A 2D list of players with the specified position'''


	playerPos = []		# List that will contain all players of a certain position


	for player in players:
		if player[2] == pos:
			playerPos.append(player)


	return playerPos

def sortByPoints(players):
	'''Receives: The 2D list of all stats
		 Does: Sorts the all the players by their 'points' statistic and appends them to a new list
		 Returns: A 2D list of players sorted by points highest to lowest'''


	players = players[:]				# Prevents the original list from being altered by the .pop() method
	playersByPnts = []					# List that will contain players sorted by points

	
	while len(players) > 0:
		playerIndex = 0						# Sets the index of the plsayer to be removed to the first player at the beginning of each loop
		maxPnts = players[0][6]		# Sets the max points value to the first player in the list at the beginning of each loop

		# Finds the player with the highest amount of points remaining in the players list {
		for i in range(0,len(players)):
			if players[i][6] > maxPnts:
				maxPnts = players[i][6]
				playerIndex = i 						# }

		# Appends the player with the most points to the new list
		playersByPnts.append(players[playerIndex])

		# Removes the player with the most points from the players list for the remaining loops
		players.pop(playerIndex)


	return playersByPnts

def buildBestTeam(players,f):
	'''Receives: The 2D list of all stats and a file name to write information to
		 Does: Searches for the player with the most points in every position and writes their names to the given file
		 Returns: Nothing'''


	try:
		file = open(f, 'w')
		players = sortByPoints(players)				# Sets players to the list of players sorted by points
		teamPos = ['C','LW','RW','D','D']			# The list of the positions needed for a team
		bestTeam = []													# List that will contain the best possible team


		for pos in teamPos:
			# Ensures that there are players remaining in the list of a certain position
			if len(filterByPos(players,pos)) > 0:
				# Finds the player with the most points for the given position 
				player = filterByPos(players,pos)[0]

				# Appends the players name to the best team list
				bestTeam.append(player[0])

				# Removes the  player from the list so they can't be chosen again
				players.remove(player)

			# If there are no players left with the given position
			else:
				bestTeam.append('')


		# Writes all the teamates names to the provided file
		for name in bestTeam:
			file.write(name+'\n')


		file.close()

	except OSError:
		print(f"There was an error writing to the file {f}.")

def displayTeamStats(players,f):
	'''Receives: The 2D list of all stats and the name of a file containing player names
		 Does: Reads the names in the file and searches for their stats the list of players. Displays this info in a formatted table
		 Returns: Nothing'''


	try:
		file = open(f, 'r')
		lines = file.readlines()
		team = []			# List that will contain the team of players read from file

		for line in lines:
			# Uses player's name to find their stats and appends them to the team list
			team.append(statsForPlayer(players,line.replace('\n','')))


		# Formats the column headers for the table
		print(f"{'Name':24}{'Team':7}{'Pos':7}{'Games':7}{'G':7}{'A':7}{'Pts':7}{'PIM':7}{'SOG':7}{'Hits':7}{'BS':5}")
		print("="*91)


		for player in team:
			# Prints all players' stats in the formatted table
			print(f"{player[0]:24}{player[1]:7}{player[2]:7}{player[3]:<7}{player[4]:<7}{player[5]:<7}{player[6]:<7}{player[7]:<7}{player[8]:<7}{player[9]:<7}{player[10]:<5}")


		file.close()

	except FileNotFoundError:
		print(f"There was an error reading from the file {f}.")

def pointsPerTeam(players,f):
	'''Receives: The 2D list of all stats and the name of a file containing player names
		 Does: Reads the names from the file and searches for their stats. Totals the amount of points for the given players
		 Returns: The total points for the team'''

	try:
		file = open(f, 'r')
		lines = file.readlines()
		team = []				# List that will contain the team of players read from file
		points = 0			# Initializes the variable that will hold the teams total points

		for line in lines:
			# Uses player's name to find their stats and appends them to the team list
			team.append(statsForPlayer(players,line.replace('\n','')))

		# Adds a specific players' points to the total if they they have stats (i.e. if there are stats for that player)
		for player in team:
			if len(player) > 0:
				points+=player[6]


		file.close()

		return points

	except FileNotFoundError:
		print(f"There was an error reading from the file {f}.")
		return 0

	except IndexError:
		print("No player statistics were found.")
		return 0

def testing():
	'''Receives: Nothing
		 Does: Runs tests for each function to ensure that they are all working in the intended way
		 Returns: True if all the fdunctions work correctly or false otherwise'''

	testCounter = 0
	players = readStats('nhl_2018.csv')

	# Test 1
	if len(players) == 906:
		testCounter+=1

	# Test 2
	if len(readStats("noFile.txt")) == 0:
		testCounter+=1

	# Test 3
	player = statsForPlayer(players,'Brock Boeser')

	if player[0] == 'Brock Boeser' and player[1] == 'VAN':
		testCounter+=1

	# Test 4
	defencemen = filterByPos(players,'D')

	for man in defencemen:
		if not man[2] == 'D':
			break
	else:
		testCounter+=1

	# Test 5
	sortedPlayers = sortByPoints(players)

	if sortedPlayers[0][6] > sortedPlayers[-1][6]:
		testCounter+=1

	# Test 6
	buildBestTeam(players,'my_team.txt')

	try:
		file = open('my_team.txt', 'r')
		lines = file.readlines()

		if len(lines) == 5:
			testCounter+=1

		file.close()

	except FileNotFoundError:
		print("The file was not found.")

	# Test 7
	if pointsPerTeam(players,'sample_team.txt') == 311:
		testCounter+=1

	if testCounter < 7:
		return False
	else:
		return True

# print(sortByPoints(readStats('nhl_2018.csv')))
print(testing())