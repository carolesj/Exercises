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

int analysis_with_another_ds (char * str) {
	int length = strlen(str);
	if (length > 256) {
		return FALSE;
	}
	else if (length <= 0) {
		return ERRORNULLINPUT;
	}
	else {
		int count[256] = {0};
		for (int i = 0; i < length; i++) {
			if (count[str[i]] == 1) { 
				return FALSE;
			} else {
				count[str[i]] = 1;
			}
		}
	}
	return TRUE;
}

int main (int argc, char ** argv) {
	char * str;
	
	scanf("%ms", &str);
	int status = analysis_with_another_ds(str);
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
