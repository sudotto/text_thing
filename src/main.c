#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "charmap.h"

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("[ERROR] you fucking dumbass you forgot the words");
		return 1;
	}
	char* string = argv[1];
	int len = strlen(string);
	char* big[5];
	for(int line = 0; line < 5; line++){
		big[line] = malloc((len * 6) + 1); // 6 is width of each char map (5) + 1 (for spacer) +1 again for null term
		for(int letter = 0; letter < len; letter++){
			if(string[letter] == ' '){
				strcat(big[line], "      ");
			} else {
				int letter_index;
				string[letter] = toupper(string[letter]);  
				if(string[letter] >= 'A' && string[letter] <= 'Z'){
					// this way the char 'A' converts to 0 which is the index of 'A' int the charmap
					letter_index = string[letter] - 'A'; 
				} else if(string[letter] >= '0' && string[letter] <= '9'){
					// same shit that rosaOS does
					letter_index = string[letter] - '0' + 26; // 26 is offset in charmap for number section 
				}
				strcat(big[line], charmap[letter_index][line]);
				strcat(big[line], " "); // spacing
			}
		}
		printf("%s\n", big[line]);
	}
	return 0;
}
