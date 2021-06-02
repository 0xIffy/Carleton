# Braeden Hall
# 101143403

def readLevel(n):
	'''Receives: An integer containing the level number
		 Does: Reads the level board and creates a 2D list of all the symbols in rows and columns
		 Returns: The 2D list that is created'''


	try:
		file = open(f'levels/ascii_level{n}.txt','r')
		lines = file.readlines()
		board = []							# List that will contain all board symbols in rows and columns

		for line in lines:
			# Removes newline character from end of every line
			line = line.replace('\n','')

			lst = []							# List that will contain the row of symbols

			for c in line:
				# Appends each character in the line to the list
				lst.append(c)

			# Appends each row to the board list
			board.append(lst)

		
		file.close()


		return board

	except FileNotFoundError:
		print(f"File levels/ascii_level{n}.txt not found")
		exit()


def displayBoard(board):
	'''Receives: The 2D list of the board
		 Does: Prints the list to the screen in the format of a board
		 Returns: Nothing'''


	# Formats and prints column numbers at top of board
	print('\n   ',end='')
	for i in range(0,len(board[0])):
		print(i%10,end='')

	# Prints border
	print('\n   ' + '-'*len(board[0]))


	for i in range(0,len(board)):
		# Prints a beggining 0 in row number if necessary
		if i < 10:
			print('0',end='')
		# Prints the row number
		print(f'{i}|',end='')

		# Prints all the symbols in each row
		for sym in board[i]:
			print(f'{sym}',end='')

		# Prints newline
		print('')

def getUserAction(height,width):
	'''Receives: 2 integers, one with the number of rows and one with the number of columns in the board
		 Does: Ask the user for the symbol they wish to input and the place they wish for it to be placed
		 Returns: A dictionary containing all of the choices the user made'''


	symbols = ['&','@','#','%']						# List of all possible symbols that could be on the board


	while True:
		sym = input("Select your symbol: ")

		# Ensures that the input is one of the valid symbols
		if sym in symbols:
			break

		else:
			print("Symbol must be one of: '&' '@' '#' '%'.") 


	while True:
		try:
			row = int(input(f"Select row (0-{height}): "))

			# Ensures that the number entered is on the board
			if row >=0 and row <= height:
				break

			else:
				# Causes value error
				int('h')

		except ValueError:
			print(f"Row must be between 0 and {height}")

	while True:
		try:
			col = int(input(f"Selcet column (0-{width}): "))

			# Ensures that the number entered is on the board
			if col >= 0 and col <= width:
				break

			else:
				# Causes value error
				int('h')

		except ValueError:
			print(f"Column must be between 0 and {width}")


	return {'symbol': sym, 'row': row, 'column': col}

def fill(board,repSym,newSym,row,col):
	'''Receives: 2D list: the board; 2 strs: the symbol to replace, the new chosen symbol; 2 ints: row and col index on the board
		 Does: Recursively changes the symbol in the chosen spot and all matching contiguous symbols into the user input symbol
		 Returns: Nothing'''


	# Ensures that the symbol to be replaced is diffent the what it is being replaced with
	if repSym == newSym:
		return None

	# Ensures that the current board position is on the board
	if not row in range(0,len(board)) or not col in range(0,len(board[0])):
		return None


	if board[row][col] == repSym:
		# Replaces the old symbol with the new one
		board[row][col] = newSym

		# Calls the fill function on all cotiguous symbols
		fill(board,repSym,newSym,row+1,col)
		fill(board,repSym,newSym,row-1,col)
		fill(board,repSym,newSym,row,col+1)
		fill(board,repSym,newSym,row,col-1)


def boardFinished(board):
	'''Receives: The 2D list of the board
		 Does: Checks if the board has been complete by seeing if there are still multiple symbols on the board
		 Returns: True if there is only one symbol on the board and false otherwise'''


	symbols = ['&','@','#','%']						# List of all possible symbols that could be on the board
	

	for row in board:
		count = 0														# Variable to count the amount of symbols present in a single row

		for sym in symbols:
			# Adds one to count if a specific variable is present in a row
			if sym in row:
				count+=1

		if count > 1:
			return False

	else:
		return True


def main():
	print("\nWelcome to Ascii Fill. The game will now start.")


	while True:
		totalMoves = 0

		# Loops for all 5 levels/boards
		for lvl in range(1,6):
			moves = 0
			board = readLevel(lvl)

			# Ensures that the user can only play if the board is unfinished
			while not boardFinished(board):
				displayBoard(board)

				choice = getUserAction(len(board)-1,len(board[0])-1)

				fill(board,board[choice['row']][choice['column']],choice['symbol'],choice['row'],choice['column'])

				moves+=1

			# Displays finished board
			displayBoard(board)

			print(f"Level {lvl} completed in {moves} moves.")
			totalMoves+=moves

		print(f"Game Over, congradulations! You finished in {totalMoves} moves.")


		while True:
			replay = input("Would you like to play again? (y/n): ")

			# Validates user input
			if replay == 'y' or replay == 'n':
				break

			else:
				continue

		# Ends the game unless the user chooses to play again
		if replay != 'y':
			break

		else:
			continue

main()