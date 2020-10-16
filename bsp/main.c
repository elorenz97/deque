#include "deque-dll.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


int main()
{  
	char eing;
   struct deque *q = init_deque(); 
	// vorn: v , hinten: h , anfügen= a, entnehmen: e, beenden : b;

	
	while (1)
	{
	
		printf("welches Ende? [v/h]:");
		if(!scanf("%s",&eing)) while ( getchar() != '\n' );
		if(strcmp(&eing, "v")==0)
		{
			printf("Anfügen oder Entnehmen? [a/e]:");
			if(!scanf("%s",&eing)) while ( getchar() != '\n' );
			if(strcmp(&eing, "a") == 0)
			{
				printf("Wert:");
				if(!scanf("%s",&eing)) while ( getchar() != '\n' );
				put(q,atoi(&eing));
			}
			else if (strcmp(&eing, "e") == 0)
			{
				get(q);
			}
			else printf("Error: Falsche eingabe!");
		}
		else if (strcmp(&eing, "h")==0)
		{
			printf("Anfügen oder Entnehmen? [a/e]:");
			if(!scanf("%s",&eing)) while ( getchar() != '\n' );
			if(strcmp(&eing, "a")==0)
			{
				printf("Wert:");
				if(!scanf("%s",&eing)) while ( getchar() != '\n' );
				push(q,atoi(&eing));
				
			}
			else if (strcmp(&eing, "e")==0)
			{
				pop(q);
			}
			else printf("Error: Falsche eingabe!");
		}
		else printf("Error: Falsche eingabe!");
		
	all(q);
	printf("Weiter? [j/n]:");
	if(!scanf("%s",&eing)) while ( getchar() != '\n' );
	if(strcmp(&eing, "n") == 0)
	{	  
	   	free_deque(q);
		return 0;
	}
	if(strcmp(&eing, "j") != 0)
	{
		printf("Error: Falsche eingabe!\n");
	}
	
	}
    return 0;
}
