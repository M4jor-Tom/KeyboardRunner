#define ESC 27
#define ENTER 13

#include "../Headers/generic.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	srand(time(NULL));
	
	char kbhit = 0, key = 0;
	unsigned long int score = 0, hiScore = 0, successesPlusOne = 1, messes = 0;
	float avgTime = 0.0, lastTime = 0.0, totalTime = 0.0;
	clock_t startClock = 0, hitClock = 0;
	
	printf("Push a random key to start!\n");
	getch();
		
	//Measure time
	startClock = clock();
		
	//Generate key to hit
	key = random('A', 'Z');
	
	do
	{
		
		//Display
		system("cls");
		if(score == 0 && messes)
			printf("Nope! [%c]\n\n", toUpper(kbhit));
		else
			printf("\n\n");
		printf("Hit: %c\n\nScore: %d\n\nLast key time: %.3f\n\nAverage time: %.3f\n", key, score, lastTime, avgTime);
		
		//Get user key
		kbhit = getch();
		
		//Update score
		if(kbhit == key || kbhit == key - 'A' + 'a')
		{
			//Right key
			score++;
			
			//Get time measures
			hitClock = clock();
			lastTime = ((hitClock - startClock) / (float)CLOCKS_PER_SEC);
			
			totalTime = totalTime + lastTime;
			avgTime = totalTime / (float)successesPlusOne;
			
			successesPlusOne++;
			
			//Measure time
			startClock = clock();
			
			//Generate key to hit
			key = random('A', 'Z');
		}
		else if(kbhit != ESC && kbhit != ENTER && kbhit != ' ')
		{
			score = 0;
			messes++;
		}
		
		hiScore = score > hiScore
			? score
			: hiScore;
	}while(kbhit != ESC && kbhit != ENTER && kbhit != ' ');
	
	system("cls");
	printf("Hi-Score: %d\n\nAverage time: %.3f\n\nTotal messes: %d", hiScore, avgTime, messes);
	
	getch();
	return 0;
}
