#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/generic.h"

void *safeMalloc(int sizeof_, char *errorMessage)
{
	void *malloc_ = malloc(sizeof_);
	if(malloc_ == NULL)
	{
		printf("<safeMalloc> Error: %s\n", errorMessage);
		return 0;
	}
	else return malloc_;
}

void *safeRealloc(void *ptr, int sizeof_, char *errorMessage)
{
	void *realloc_ = realloc(ptr, sizeof_);
	if(realloc_ == NULL)
	{
		printf("<safeRealloc> Error: %s\n", errorMessage);
		return 0;
	}
	else return realloc_;
}

void *safeAlloc(void *ptr, int sizeof_, char *errorMessage)
{
	if(ptr == NULL)
	{
		//printf("safealloc:malloc\n");
		return safeMalloc(sizeof_, errorMessage);
	}
	else 
	{
		//printf("safealloc:realloc\n");
		return safeRealloc(ptr, sizeof_, errorMessage);
	}
}

/*void freeHyper(int *mainHeader, unsigned int *lengths, unsigned int dimentions)
{
	if(dimentions > 0)
	{
		int i;
		for(i = 0; i < lengths[0]; i++)
		{
			freeHyper(mainHeader[i], &lengths[1], dimentions - 1);
			free(mainHeader);
		}
	}
}*/

void freeMatress(void **mainHeader, unsigned int headersLength)
{
	int i;
	for(i = 0; i < headersLength; i++)
		free(mainHeader[i]);
	//freeHyper(mainHeader, &headersLength, 2);
}

int array_search(char needle, char *haystack, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		//printf("needle: %c // haystack[%d] = %c\n", needle, i, haystack[i]);
		if(haystack[i] == needle)
			return i;
	}
	return - 1;
}

char toLower(char char_)
{
	return char_ >= 'A' && char_ <= 'Z'
			? char_ - 'A' + 'a'
			: char_;
}

char toUpper(char char_)
{
	return char_ >= 'a' && char_ <= 'z'
		? char_ - 'a' + 'A'
		: char_;
}

void strToLower(char* str)
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		str[i] = toLower(str[i]);
	}
}

int random(int min, int max)
{
	if(min > max)
	{
		printf("min: %d\nmax: %d\n", min, max);
		return 0;
	}
	else
	{
		return (rand() % (max - min)) + min;
	}
}
