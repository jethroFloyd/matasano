/**
 * Solution to Set 1 - Challenge 1 
 * Matasano Crypto Challenge
 * http://cryptopals.com/sets/1/challenges/1/
 *
 * Author: Ritobroto Maitra, 2015
 *
 **/

/**
 *
 *	Convert hex to base64 
 * 	Test Case: 
 *	The hex: 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
 *	should produce: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
 * 	
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <inttypes.h>

int die (char *string) {
	printf("%s", string);
	exit(0);
}

int main() {

	char input[8096]; // Putting arbitrary limit of characters, but can be changed any time.
	fgets(input, sizeof(input), stdin);

	int inputSize = strlen(input);
	inputSize--; // Truncating the NULL Character.

	int i,j;

	// Take the input 3-bytes at a time (6 hex characters) at a time, and divide it into 4 blocks.
	// First check if the number of input bytes is divisible by 3. 
	// If it is, we are clean. If it isn't, we need to pad.

	int sizeCheck = inputSize % 3;

	uint8_t hex[6] = {0};
	uint8_t base64[4] = {0};

	// if the size is perfectly divisible by 3, then take the blocks one by one.

	if (sizeCheck == 0) {
		for (i = 0; i < (inputSize/3); i++) {
			for (j=0; j<6;j++){
				// First check if the concerned digit is a number.
				if(isdigit(input[j])) {
					hex[j] = (uint8_t)((int)input[j] - 48);
				}
				else if(isxdigit(input[j])) {
					hex[j] = (uint8_t)((int)input[j] - 97);
				}
				else {
					die("The system encountered an error.");
				}

			}

		}
	}
}