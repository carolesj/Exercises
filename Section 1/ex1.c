/*
 * Caroline Jesuino Nunes da Silva
 * Solution to exercise number one of the first section of the book
 * 		Cracking the Code interview: determine if a string has all unique
 * 		characters.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 0
#define FALSE -1
#define ERRORNULLINPUT -2

int is_valid (char * str) {
	int length = strlen(str);
	if (length > 256) {
		return FALSE;
	} else if (length <= 0) {
		return ERRORNULLINPUT;
	} else {
		return length;
	}
}

int analysis_with_another_ds (char * str) {
	int length = is_valid (str);
	if (length <= 0) return length;
	int count[256] = {0};
	for (int i = 0; i < length; i++) {
		if (count[str[i]] == 1) { 
			return FALSE;
		} else {
			count[str[i]] = 1;
		}
	}
	return TRUE;
}

int analysis_without_another_ds (char * str) {
	int length = is_valid (str);
	if (length <= 0) return length;
	char current_char = str[0];
	for (int i = 1; i < length; i++) {
		for (int current_pos = i; current_pos < length; current_pos++) {
			if (current_char == str[current_pos]) {
				return FALSE;
			}
		}
		current_char = str[i];
	}
	return TRUE;
}

int main (int argc, char ** argv) {
	char * str;
	
	scanf("%ms", &str);
	//int status = analysis_with_another_ds(str);
	int status = analysis_without_another_ds(str);
	if (status == TRUE) {
		printf("YES\n");
	}
	else if (status == FALSE) { 
		printf("NO\n");
	}
	else { 
		printf("ERROR: NULL STRING GIVEN AS INPUT\n");
	}
	
	free(str);
	return 0;
}
