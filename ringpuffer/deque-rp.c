#include "deque-rp.h"
#include <stdio.h>
#include <stdlib.h>

deque * init_deque ()
{
     deque *q = malloc(sizeof(struct deque));
	if (q != NULL)
    {
    q->first = q->last =  q->count = 0;
	return q;
    }
    return 0;
}

void free_deque  (deque * q)
{
    free(q);
}

int push(deque * q,int val)
{       
   if(q->count == 0)
    {   
        q->values[q->last]= val;
        q->count++;
        
    }
    else
    {    
        if (q->last == DEQUE_SIZE-1) q->last = 0;
        else q->last++;
        q->values[q->last] = val; 
        if(q->count == DEQUE_SIZE)
        {
            if(q->first == DEQUE_SIZE-1)
            {q->first = 0;} 
            else q->first++;
        }  
        else q->count++;
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
        if (q->last != q->first) 
        {
            if(q->last == 0 ) q->last = DEQUE_SIZE-1;
            else q->last--;
        }
        return out;
    }
    else{
        fprintf(stderr,"Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
}
//nur auslesen
int last (deque * q)
{
   if(q->count == 0)
    {    
        fprintf(stderr,"Error: Kein Feld in der Deque enthalten\n");
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
        if (q->first == 0) {q->first = DEQUE_SIZE-1;}
        else {q->first--;}
        q->values[q->first] = val;   
        if(q->count == DEQUE_SIZE)
        {
            if(q->last == 0)
            {q->last = DEQUE_SIZE-1;} 
            else q->last--;
        }
        else {q->count++;}
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
        if (q->last != q->first) 
        {
            if(q->first == DEQUE_SIZE-1) { q->first = 0;}
            else  q->first++;
        }
        return out;
    }
    else{
        fprintf(stderr,"Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
}
//nur auslesen
int first (deque * q)
{
    if(q->count == 0)
    {    
        fprintf(stderr,"Error: Kein Feld in der Deque enthalten\n");
        return 0;
    }
    else return q->values[q->first];
}
