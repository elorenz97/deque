#include "deque-rp.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h> //INT_MAX


int main()
{   struct timeval  begin, end;
    struct timezone tzp;
    long seconds, useconds;

   if(gettimeofday(&begin, &tzp))
	{
		fprintf(stderr,"can not get time\n");
		return 0;	
	}
   struct deque *q = init_deque(); 

    for(int i = 0; i < 100000; i++)
    {
        put(q,INT_MAX);
        push(q,INT_MAX);
    }


    if(gettimeofday(&end, &tzp))
	{
		fprintf(stderr,"can not get time\n");
		return 0;	
	}

	seconds = end.tv_sec - begin.tv_sec;
	useconds = end.tv_usec - begin.tv_usec;

	if(useconds < 0){
		useconds +=1000000;
		seconds--;
	}

    //gettimeofday(&t, &tzp);
    printf("Anfügen: sec: %ld, usec: %ld\n",seconds, useconds);


    if(gettimeofday(&begin, &tzp))
	{
		fprintf(stderr,"can not get time\n");
		return 0;	
	}

        for(int i = 0; i < 100000; i++)
    {
        pop(q);
        get(q);
    }

    free_deque(q);


    if(gettimeofday(&end, &tzp))
	{
		fprintf(stderr,"can not get time\n");
		return 0;	
	}

	seconds = end.tv_sec - begin.tv_sec;
	useconds = end.tv_usec - begin.tv_usec;

	if(useconds < 0){
		useconds +=1000000;
		seconds--;
	}

    //gettimeofday(&t, &tzp);
    printf("Entnehmen: sec: %ld, usec: %ld\n", seconds ,useconds);
    return 0;
}
