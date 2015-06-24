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

	int i,j,k=0;

	// Take the input 3-bytes at a time (6 hex characters) at a time, and divide it into 4 blocks.
	// First check if the number of input bytes is divisible by 3. 
	// If it is, we are clean. If it isn't, we need to pad.

	int sizeCheck = (inputSize/2) % 3;

	uint8_t hex[6] = {0};
	uint8_t hex2[3] = {3};
	int sizeOfBase64 = 4 * (inputSize/3);
	uint8_t base64[10800] = {0};
	char base64char[10800];

	// Add padding to string.

	if (sizeCheck == 1) {
		input[inputSize] = '0';
		input[inputSize + 1 ] = '0';
		input[inputSize + 2 ] = '0';
		input[inputSize + 3 ] = '0';
	}

	if (sizeCheck == 2) {
		input[inputSize] = '0';
		input[inputSize + 1] = '0';
	}

	// Recompute sizeCheck now!

	int sizeCheck2 = 0;

	// if the size is perfectly divisible by 3, then take the blocks one by one.

	if (sizeCheck2 == 0) {
		for (i = 0; i < inputSize; i+=6) {

			// Process six-hex-character block.
			for (j=i; j<(i+6);j++){
				// First check if the concerned digit is a number.
				if(isdigit(input[j])) {
					hex[j-i] = (uint8_t)((int)input[j] - 48);
				}
				else if(isalpha(input[j])) {
					hex[j-i] = (uint8_t)((int)input[j] - 87);
				}
				else {
					die("The system encountered an error.");
				}

			}

			// Now let us fuse two hex characters together - 8 bits, to form our octet.

			

			hex2[0] = (hex[1] | (hex[0] << 4));
			hex2[1] = (hex[3] | (hex[2] << 4));
			hex2[2] = (hex[5] | (hex[4] << 4));

			// Now we have the 3 octets.

			base64[0] = hex2[0] >> 2;
			base64[1] = (hex[2] | ((hex[1] & 3) << 4));
			hex[4] = hex[4] >> 2;
			hex[4] = hex[4] << 2;
			hex[3] = hex[3] << 4;
			base64[2] = (hex[3] | hex[4])>>2;
			base64[3] = hex2[2] & 0x3f;

			// Now we have the four base64 characters from this six-hex-block.

			for(j=k; j<(k+4); j++){
				if(base64[j-k] < 26) {
					base64char[j] = (char)(base64[j-k] + 65);
				}
				else if(base64[j-k] < 52) {
					base64char[j] = (char)(base64[j-k] + 71);
				}
				else if(base64[j-k] < 62) {
					base64char[j] = (char)(base64[j-k] - 4);
				}
				else if (base64[j-k] == 62) {
					base64char[j] = '+';
				}
				else {
					base64char[j-k] = '/';
				}
			}

			k+=4;
		}
	}

	// Now let us find out the state of the base64char thing.

	if (sizeCheck == 0) {
		base64char[k] = '\0';
	}
	else if (sizeCheck == 1) {
		base64char[k-2] = '=';
		base64char[k-1] = '=';
		base64char[k] = '\0';
	}
	else if (sizeCheck == 2) {
		base64char[k-1] = '=';
		base64char[k] = '\0';
	}

	// Print out the final output.

	printf("The base64 encoding is:\n%s\n", base64char);
}