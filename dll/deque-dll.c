#include "deque-dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>


deque * init_deque ()
{
    deque *d = malloc(sizeof(struct deque));
	if (d != NULL)
        {
		d->first = d->last = NULL;
        d->count = 0;
        }
	return d;
}

void free_deque  (deque * q)
{   node * n;
   for(int i = 0; i < q->count;i++)
    {   n = q->first;
        q->first = n->next;
        free(n);
    }
    
    free(q);
}

//HINTERES ENDE
// einfügen
void push(deque * q,int val)
{   
    struct node * n = malloc(sizeof(struct node));
    
    n->value = val;
    n->next = NULL;    
    if(q->count == 0)
    {
        q->first = n;
        q->last = n;
        n->prev = NULL;
    }
    else
    {   n->prev = q->last;
        q->last->next = n;
        q->last = n;
    }
    q->count++;
}
//entnehmen und entfernen
int pop (deque * q)
{  
    if ((q->count) !=0)
    {   struct node * last = q->last;
         int v = last->value; 
        if ((q->count) ==1)
        {
            q->last = NULL;
            q->first = NULL;
        }
        else
        {   
            q->last = last->prev;
            last->prev->next = NULL;
        }
        q->count--;
        free(last);
        return v;
        
        
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
    return q->last->value;
}

//VORDERES ENDE
// einfügen
void put(deque * q,int val)
{   
    struct node * n = malloc(sizeof(struct node));
    n->value = val;
    n->prev = NULL;    
    if(q->count == 0)
    {
        q->first = n;
        q->last = n;
        n->next = NULL;
    }
    else
    {   n->next = q->first;
        q->first->prev = n;
        q->first = n;
    }
    q->count++;
}
//entnehmen und entfernen
int get (deque * q)
{  
    if ((q->count) !=0)
    {   struct node * first = q->first; 
        int v = first->value;
        if ((q->count) ==1)
        {
            q->last = NULL;
            q->first = NULL;
        }
        else
        {   
            q->first = first->next;
            first->next->prev = NULL;
        }
        q->count--;
        free(first);
        return v;
             
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
    return q->first->value;
}

