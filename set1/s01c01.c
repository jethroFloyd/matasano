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
	uint8_t hex2[3] = {3};
	int sizeOfBase64 = 4 * (inputSize/3);
	uint8_t base64[10800] = {0};
	char base64char[10800];

	// if the size is perfectly divisible by 3, then take the blocks one by one.

	if (sizeCheck == 0) {
		for (i = 0; i < (inputSize/3); i++) {
			for (j=0; j<6;j++){
				// First check if the concerned digit is a number.
				if(isdigit(input[j])) {
					hex[j] = (uint8_t)((int)input[j] - 48);
				}
				else if(isalpha(input[j])) {
					hex[j] = (uint8_t)((int)input[j] - 87);
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

			printf("%d, %d\n", hex[3], base64[2]);

			for(j=0; j<4; j++){
				if(base64[j] < 26) {
					base64char[j] = (char)(base64[j] + 65);
				}
				else if(base64[j] < 52) {
					base64char[j] = (char)(base64[j] + 71);
				}
				else if(base64[j] < 62) {
					base64char[j] = (char)(base64[j] - 4);
				}
				else if (base64[j] == 62) {
					base64char[j] = '+';
				}
				else {
					base64char[j] = '/';
				}
			}

			printf("%c %c %c %c\n", base64char[0], base64char[1], base64char[2], base64char[3] );

		}
	}
}