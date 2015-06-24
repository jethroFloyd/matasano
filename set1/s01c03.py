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

def hexCheck(number, length):
	# We need to extract the last two digits.
	hexToString = ''
	for i in range(length/2):
		lastTwo = int(number & 0xff)
		lastChar = chr(lastTwo)
		hexToString = lastChar + hexToString
		number = number >> 8

	return hexToString

inputString = raw_input("Please enter hex-encoded string:\n ")
inputInt = int(inputString,16)
inputStringASCII = inputString.decode("hex")
length = len(inputStringASCII)
stringChar = "x"
stringTest = stringChar*length
stringTestHex = stringTest.encode("hex")
bestKey = "a"
e = 0
old_e = 0


for i in range(26):
	stringChar = str(unichr(65+i))
	print stringChar
	stringTest = stringChar*(length)
	#print stringTest
	stringTestHex = int(binascii.hexlify(stringTest), 16)
	#print stringTestHex

	testOutput = stringTestHex ^ inputInt
	print "%x"  %(testOutput)
	testOutputString = hexCheck(testOutput, (length*2))
	print testOutputString
#	testOutputString ="o"

		#testOutputString = testOutput.decode("hex")
	#print testOutput
	# Now we have the hex representation of testOut. We need to unhexlify it.
#	print binascii.unhexlify(str(testOutput))
#	testOutputString = testOutputString.decode("hex")
	# print testOutputString
	#print testOutputString
	# Now check if 'e' is the most common letter
	for j in range(length):
		if 'o' in testOutputString:
			e+=1
		else:
			pass
	# e should be higher than a, and e/length should be ~ .12
	if e > old_e:
		bestKey = stringChar
		old_e = e
	e = 0


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



