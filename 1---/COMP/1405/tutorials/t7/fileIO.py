# Braeden Hall
# 101143403

def makeHomepage(name,hobby):
	file = open('my_homepage.html', 'r')
	text = file.readlines()
	weather = getWeatherData()

	text.pop(6)
	text.insert(6, f"\t\t<p>Hello {name} I see that your favorite hobby is {hobby}</p>\n")
	text.pop(7)
	text.insert(7,f"\t\t<p>It is currently {weather['Conditions']} at a tempreature of {weather['Tempreature']}</p>\n")

	file.close()
	file = open('my_homepage.html', 'w')

	for i in range(0,len(text)):
		file.write(text[i])

	file.close()
	# print(text)

def getWeatherData():
	file = open('weather_data.html','r')
	text = file.readlines()
	i = 0
	count = 0
	
	while text[i].find('header3m') == -1 or count < 1:
		if not text[i].find('header3m') == -1:
			count+=1
		i+=1

	temp = text[i+1].strip().replace('(','').replace(')','') + ' degrees C'
	# print(temp)
	i = 0
	count = 0

	while text[i].find('header2') == -1 or count < 1:
		if not text[i].find('header2') == -1:
			count+=1
		i+=1

	conditions = text[i+4][text[i+4].find('<p>')+3:text[i+4].find('</p>')]

	Weather = { 'Tempreature': temp, 'Conditions': conditions }

	return Weather


makeHomepage('Braeden','Basketball')