# Braeden Hall
# 101143403

# Dictionary containing all info pertaining to each sub including the name, price and number associated
Subs = {1: ["\"Meat\"-ball sub",7.99], 2: ["Cold-cut Club sub",8.25], 3: ["Philly's Cheese Mis-Steak sub",9.55], 4: ["Veggie Pile sub",6.75]}

# Dictionary containing all available toppings and the initial amount of said topping is on the sub
Toppings = {'lettuce': 0,'tomatoes': 0,'onions': 0,'peppers': 0,'jalepenos': 0,'pickles': 0,'cucumbers': 0,'olives': 0,'guacamole': 0}

def validate_topping(top):
	'''Checks user's input against toppings in the topping dictionary, if valid returns true else returns false'''
	for topping in Toppings:
		if top.lower() == topping:
			return True
			break
	else:
		return False

def main():
	'''The main function that displays and validates all user inputs'''
	print("\nWelcome to Seb's Sub Shoppe where subs are shopped!!\n")

	# Displays all subs in a list
	for sub in Subs:
		print(f"{sub}. {Subs[sub][0]} ({Subs[sub][1]})")

	# Ensures that user's choice of sub is valid
	while True:
		choice = int(input(f"\nPlease select the number of the sub you would like to order: "))
		if choice > 0 and choice <= 4:
			break
		else:
			print(f"The number you entered ({choice}) is not associated with any of the subs currently available.")

	print("\nSelect your toppings (unlimitted).\nNote that guacamole costs $1.50 extra.\nToppings are listed as follows:\n")

	i=0
	# Displays and formats all toppings
	for topping in Toppings:
		print(f"{topping:<9}\t",end='')
		i+=1
		if i == 3:
			i = 0
			print("\n")

	print("Type 'done' once you are satisfied with your toppings.")

	# Ensures that topping entered is valid
	while True:
		top = input(">> ")
		if top == 'done':
			break
		elif validate_topping(top):
			# Counts the number of times a specific topping is typed
			Toppings[top.lower()]+=1
		else:
			print(f"{top} is not a valid topping")

	# Displays to the user all info pertaining to their order
	print("\nPlease validate your order:")
	print(f"Sub: {Subs[choice][0]}")
	print(f"Toppings: ",end='')

	# Lists all toppings that the user input and the amount of times the were input
	for topping in Toppings:
		if Toppings[topping] > 0:
			print(f"{Toppings[topping]} serving(s) of {topping}",end=', ')

	# Asks the user if order is correct and validates their input
	while True: 
		valid = input("\nIs your order correct? (y/n) ")
		if valid == 'y':
			break
		elif valid == 'n':
			print("My appologies, please start your order again from the beginning.\n")
			exit()
		else:
			print(f"Very sorry, {valid} is not a valid response. Please retype.")

	# Calculates the order subtotal
	sTotal = Subs[choice][1]+(1.5*Toppings['guacamole'])

	# Prints and formats all info pertaining to the reciept
	print(f"\n{'Reciept':^25}")
	print("-"*25)
	print(f"{'Subtotal:':<9}\t${sTotal:.2f}\n{'Tax:':<9}\t${sTotal*0.13:.2f}")
	print("-"*25)
	print(f"{'Total:':<9}\t${sTotal*1.13:.2f}")
	print("-"*25)

	print("\nThank you for shopping subs at Seb's Subs.\nEnjoy your day!\n")

# Calls main function	
main()