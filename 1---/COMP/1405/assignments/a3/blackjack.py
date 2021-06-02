# Braeden Hall
# 101143403

from random import randint

def sumHand(lst):
	'''Receives: A list of the string value for each card in the hand
		 Does: Calculates the value of the hand based on the assigned values of each hand
		 Returns: The hands sum'''

	# Dictionary containing the string valuer for every card in the deck and its original point value
	DeckValue = { 'A': 11, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, 'J': 10, 'Q': 10, 'K': 10 }

	handSum = 0			# Variable to total the sum of a hand
	aceCounter = 0		# Variable to count the amount of aces in a hand

	# Adds the point value of each card in your hand to the hand total
	for i in range(0,len(lst)):
		handSum+=DeckValue[lst[i]]

	# If the total of the hand is more than 21 and there is an ace in the hand subtracts 10 from the total points
	while handSum > 21 and lst.count('A') > aceCounter:
		handSum-=10
		aceCounter+=1

	return handSum

def displayHand(lst):
	'''Receives: A list of the string equivalents for each card in the hand
		 Does: Prints the string equivalent of each card in the hand as well as the sum of the hand to the screen
		 Returns: Nothing'''

	print("Your Hand: ",end=' ')
	for i in range(0,len(lst)):
		print(f"{lst[i]}",end=' ')
	print(f"({sumHand(lst)})")

def dealCard(deck):
	'''Bonus Attempted
		 Receives: A dictionary containg the deck of cards
		 Does: Generates a random integer from 1-13 inclusive to represent a card and ensures that it is still available in the deck
		 Returns: The randomly generated number'''

	# Continues until the it generates a number associated with a 'card' that has more than 0 variants left in the deck
	while True:
		card = randint(1,13)

		# Checks if there is still a version of the generated card is still available in the deck
		if deck[card][1] > 0:
			break
		else:
			continue
		
	return card

def strCard(lst,deck):
	'''Receives: The user's hand stored in a list and a dictionary containing the deck of cards
		 Does: Creates a list containing the string equivalents of each card in the user's hand
		 Returns: The list of string equivalents'''

	strHand = []
	for i in range(0,len(lst)):
		strHand.append(deck[lst[i]][0])

	return strHand

def getRank(num):
	'''Receives: An integer containing the score the user acheived
		 Does: Compares the user score to specified values for certain ranks
		 Returns: The rank the the user achieved'''
		 
	if num >= 95:
		return "Ace!"
	elif num >= 85:
		return "King"
	elif num >= 75:
		return "Queen"
	elif num >= 50:
		return "Jack"
	elif num >= 25:
		return "Commonor"
	else:
		return "Noob"

def main():
	# Dictionary containing numbers 1 to 13 and their associated face value and the original amount of them in the deck
	Deck = { 1: ['A',4], 2: ['2',4], 3: ['3',4], 4: ['4',4], 5: ['5',4], 6: ['6',4], 7: ['7',4], 8: ['8',4], 9: ['9',4], 10: ['10',4], 11: ['J',4], 12: ['Q',4], 13: ['K',4] }

	score = 100			# Initial score for the user
	
	# Loops for the 5 rounds the user will play
	for rnd in range(1,6):
		# 'Shuffles' all cards back into the deck/ensures that there are 4 of each card available to be randomly generated each round
		for card in Deck:
			Deck[card][1] = 4

		hand = []				# The user's hand for the round
		handScore = 0		# The value of the user's hand during the round
		bust = False		# Initializes user bust variable to false

		# Calls deal card to generate 2 random cards and removes them from the deck
		for i in range(0,2):
			hand.append(dealCard(Deck))
			Deck[hand[-1]][1]-=1


		print(f"\nRound: {rnd}\nScore: {score}")
		displayHand(strCard(hand,Deck))

		# Loops until the user is bust or they type stand
		while True:
			# If the user's hand value is greater than 21 ends loop and switches bust boolean
			if sumHand(strCard(hand,Deck)) > 21:
				print("Bust!")
				bust = True
				break

			if sumHand(strCard(hand,Deck)) == 21:
				print("Shiii you lucky mf...")
				break

			choice = input("Would you like to 'hit' or 'stand': ")

			if choice == 'hit':
				hand.append(dealCard(Deck))
				Deck[hand[-1]][1]-=1
				displayHand(strCard(hand,Deck))
			elif choice == 'stand':
				break
			else:
				continue

		# Updates the value of the user's hand value if the user did not bust during the round
		if not bust:
			handScore = sumHand(strCard(hand,Deck))

		# Updates the user's final score based on how they did during the round
		score-=21-handScore

	print(f"\nGame Over.\nFinal Score: {score}\nRank: {getRank(score)}\n")

main()