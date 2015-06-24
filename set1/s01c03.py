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
#####################################################

from sys import exit
from collections import Counter
import binascii

inputString = raw_input("Please enter hex-encoded string:\n ")

inputInt = int(inputString,16)
print inputInt
inputStringASCII = inputString.decode("hex")
print inputStringASCII
length = len(inputStringASCII)
print length
stringChar = "x"
stringTest = stringChar*length
stringTestHex = stringTest.encode("hex")
print stringTestHex
bestKey = "a"
e = 0
a = 0


for i in range(26):
	stringChar = str(unichr(97+i))
	print stringChar
	stringTest = stringChar*length
	print stringTest
	stringTestHex = stringTest.encode("hex")
	print stringTestHex
	stringTestHexNum = int(stringTestHex,16)
	testOutput = stringTestHexNum ^ inputInt
	#testOutputString = testOutput.decode("hex")
	print testOutput
	testOutputString = str(testOutput)
	
	testOutputString = testOutputString.decode("hex")
	print testOutputString
	# Now check if 'e' is the most common letter
	for j in range(length):
		if 'e' in testOutputString:
			e+=1
		elif 'a' in testOutputString:
			a+=1
		else:
			pass
	# e should be higher than a, and e/length should be ~ .12
	if e > a:
		if  0.1 < float(e/length) < 0.15:
			bestKey = stringChar
	e = 0
	a = 0


stringChar = bestKey
stringTest = stringChar*length
stringTestHex = stringTest.encode("hex")
stringTestHexNum = int(stringTestHex,16)
testOutput = stringTestHexNum ^ inputInt
testOutputString = str(testOutput)
testOutputString = testOutputString.decode("hex")
testOutputString

print "The character key is: " , bestKey
print "The output is: ", testOutputString



