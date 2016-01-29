#include <string.h>
#include <errno.h>
#include <stdio.h>


#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length) {

	if(str) {
		if(length != 0) {
			if(*(str+length-1) == '\0')
				return true;
		}
	}
	return false;
}

char *string_duplicate(const char *str, const size_t length) {
	if(str) {
		if(length != 0) {
			int sizeLeng = strlen(str);
			if(sizeLeng+1 >= length) {
				char* newString = (char *)malloc(length);
				if(newString) {
					for(int i = 0; i < length; i++) {
						*(newString+i) = *(str+i);
					}
					*(newString+length) = '\0';
					return newString;
				}
			}
		}
	}
	return NULL;

}

bool string_equal(const char *str_a, const char *str_b, const size_t length) {	
	
	if(str_a && str_b) {
		if(length != 0) {
			if(strlen(str_a) != 0 || strlen(str_b) != 0) {
				for (int i = 0; i < length; i++) {
					if(*(str_a+i) != *(str_b+i))
						return false;
				}
				return true;
			}
			else
				return true;
		}
	}
	return false;
}

int string_length(const char *str, const size_t length) {
	if(str || length == 0) {
		for (int i = 0; i < length; i++) {
			if(str[i] == '\0')
				return i;	
		}	
	}
	return -1;
}

int string_tokenize(const char *str, const char *delims, const size_t str_length,char **tokens, const size_t max_token_length, const size_t requested_tokens) {

	return 0;
}

bool string_to_int(const char *str, int *converted_value) {

	return true;
}
