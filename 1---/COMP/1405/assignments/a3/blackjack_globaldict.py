# Braeden Hall
# 101143403

import random

Deck = { 1: ['A',11,4], 2: ['2',2,4], 3: ['3',3,4], 4: ['4',4,4], 5: ['5',5,4], 6: ['6',6,4], 7: ['7',7,4], 8: ['8',8,4], 9: ['9',9,4], 10: ['10',10,4], 11: ['J',10,4], 12: ['Q',10,4], 13: ['K',10,4] }

def sumHand(lst):
	handSum = 0
	aceCounter = 0

	for i in range(0,len(lst)):
		handSum+=Deck[lst[i]][1]

	while handSum > 21 and lst.count(1) > aceCounter:
		handSum-=10
		aceCounter+=1

	return handSum

def displayHand(lst):
	print("Your Hand: ",end=' ')
	for i in range(0,len(lst)):
		print(f"{Deck[lst[i]][0]}",end=' ')
	print(f"({sumHand(lst)})")

def dealCard():
	'''Bonus'''
	while True:
		card = random.randint(1,13)

		if Deck[card][2] > 0:
			break
		else:
			continue

	return card

# def strHand(lst,Deck):


def getRank(num):
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
	

	score = 100
	
	for rnd in range(1,6):
		for card in Deck:
			Deck[card][2] = 4

		hand = []
		handScore = 0
		bust = False

		for i in range(0,2):
			hand.append(dealCard())
			Deck[hand[-1]][2]-=1


		print(f"\nRound: {rnd}\nScore: {score}")
		displayHand(hand)

		while True:
			if sumHand(hand) > 21:
				print("Bust!")
				bust = True
				break
			choice = input("Would you like to 'hit' or 'stand': ")
			if choice == 'hit':
				hand.append(dealCard())
				Deck[hand[-1]][2]-=1
				displayHand(hand)
			elif choice == 'stand':
				break
			else:
				continue

		if not bust:
			handScore = sumHand(hand)

		score-=21-handScore

	print(f"\nGame over.\nFinal Score: {score}\nRank: {getRank(score)}\n")

main()