#####################################################
#													#
# Solution to Set 1 - Challenge 3                   #
# Matasano Crypto challenge 						#
# http://cryptopals.com/sets/1/challenges/3/ 		#
#													#
# Author: Ritobroto Maitra, 2015					#
#													#
# The hex encoded string:					 		#
# 1b37373331363f78151b7f2b783431333					#
# d78397828372d363c78373e783a393b3736 				#
# has been XOR-ed with one character. 				#
# Decrypt it. 										#
# 													#
# Key: X, Text: Cooking MC's like a pound of bacon	#
#####################################################


from sys import exit
from collections import Counter
import binascii

def hexCheck(number, length):
	hexToString = ''
	e = 0
	for i in range(length/2):
		lastTwo = int(number & 0xff)
		lastChar = chr(lastTwo)
		if (lastChar=="o"):
			e+=1
		hexToString = lastChar + hexToString
		number = number >> 8

	return hexToString, e 


inputString = raw_input("Please enter hex-encoded string:\n")
inputInt = int(inputString,16)
inputStringASCII = inputString.decode("hex")
length = len(inputStringASCII)
stringChar = "x"
stringTest = stringChar*length
stringTestHex = stringTest.encode("hex")
bestKey = "a"
index = 0
old_index = 0
finalResult = ''


for i in range(26):
	stringChar = str(unichr(65+i))
	stringTest = stringChar*(length)
	stringTestHex = int(binascii.hexlify(stringTest), 16)
	testOutput = stringTestHex ^ inputInt
	testOutputString, index = hexCheck(testOutput, (length*2))
	if index > old_index:
		bestKey = stringChar
		finalResult = testOutputString
	else:
		pass
	old_index = index
	index = 0


print "The character key is: " , bestKey
print "The output is: ", finalResult