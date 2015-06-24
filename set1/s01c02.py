#####################################################
#													#
# Solution to Set 1 - Challenge 2                   #
# Matasano Crypto challenge 						#
# http://cryptopals.com/sets/1/challenges/2/ 		#
#													#
# Author: Ritobroto Maitra, 2015					#
#													#
# Write a function that takes two equal-length 		#
# buffers and produces their XOR combinations. 		#
# If your function works properly,  				#
# then when you feed it the string: 				#
# 1c0111001f010100061a024b53535009181c 				#
# after hex decoding, and when XOR'd against:       #
# 686974207468652062756c6c277320657965 				#
# should produce: 									#
# 746865206b696420646f6e277420706c6179 				#
# 													#
#####################################################

from sys import exit

def die(errorValue):
	print errorValue
	exit(0)

inputString1 = raw_input("First input: ")
inputString2 = raw_input("Second input: ")

if (len(inputString1)) != (len(inputString2)):
	die("The lengths do not match!")

# If the program reaches this line, 
# it means that the two inputs are equal-length.
# At this stage, we are not checking 
# if both are valid hex streams.

input1 = int(inputString1, 16)
input2 = int(inputString2, 16)

output = input1 ^ input2

print hex(output)