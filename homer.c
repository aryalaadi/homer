/*
	file:		homer.c
	license:	public domain
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

char *filename(int randint) {
	char *rt = calloc(24, sizeof(char));
	sprintf(rt, "%d.txt", randint+1);
	return rt;
}

int main(int argc, char **argv) {

	int n;
	if (argv[1] == NULL) {
		n = 5;	
	}
	else {
		n = atoi(argv[1]);	
	}


	FILE *fp;
	srand(time(NULL));
	int r = rand() % n;

	char datadir[] = ".poem/";
	char *fn = calloc(255, sizeof(char));
	strncpy(fn, datadir, strlen(datadir));
	
	char *tmp = filename(r);
	strncat(fn, tmp, 24);
	free(tmp);
	
	fp = fopen(fn, "r");
	if (fp == NULL) {
		printf("its over.");
		return -1;
	}

	char *buf = calloc(8192, sizeof(char));
	while (fgets(buf, 8192, fp)) {
		printf("%s", buf);
	}
   	fclose(fp); 	
}
