#include <stdio.h>
#include <stdlib.h>
#include "deque-arr.h"



deque * init_deque ()
{
    deque *d = malloc(sizeof(struct deque));
	if (d != NULL)
        {
		d->first = d->last = DEQUE_SIZE/2-1;
        d->count = 0;
        }
	return d;
}

void free_deque  (deque * q)
{
    free(q);
}

//HINTERES ENDE
// einfügen
int push(deque * q,int val)
{       
    if(q->count == 0)
    {   
        q->values[q->last]= val;
        q->count++;
    }
    else
    {    if(q->last == DEQUE_SIZE-1)
        {
        printf("Error: Es kann kein Wert mehr am Ende angefügt werden!\n");
        return 0;
        }
        else{
        q->last += 1;
        q->values[q->last] = val;
        q->count++;
        }
    }
    
    return 1;
}
//entnehmen und entfernen
int pop (deque * q)
{  
    if ((q->count) !=0)
    {   
        int out = q->values[q->last];
        q->values[q->last] = 0;
        q->count--;
        if (q->last != q->first) q->last--;

        return out;
    }
    else{
        printf("Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
}
//nur auslesen
int last (deque * q)
{
   if(q->count == 0)
    {    
        printf("Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
    else return q->values[q->last];
}

//VORDERES ENDE
// einfügen
int put(deque * q,int val)
{   
    if(q->count == 0)
    {   
        q->values[q->first]= val;
        q->count++;
    }
    else
    {   
        if(q->first == 0)
        {
        printf("Error: Es kann kein Wert mehr am Anfang angefügt werden!\n");
        return 0;
        }
        else{
        q->first -= 1;
        q->values[q->first] = val;
        q->count++;
        }
    }
    
    return 1;
}
//entnehmen und entfernen
int get (deque * q)
{  
     if ((q->count) !=0)
    {   
        int out = q->values[q->first];
        q->values[q->first] = 0;
        q->count--;
        if (q->last != q->first) q->first++;
        return out;
    }
    else{
        printf("Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
}
//nur auslesen
int first (deque * q)
{
    if(q->count == 0)
    {    
        printf("Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
    else return q->values[q->first];
}

void all (deque * q)
{   int s = q->first;
    for(int i = 0; i < q->count; i++)
    {
    printf("------------\n");
    printf("|%10i|",q->values[s]);
    printf("\n");
    printf("------------\n");
    s++;
    }
}
}
