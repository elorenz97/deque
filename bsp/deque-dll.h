
typedef struct node
{
    unsigned int value;
    struct node * next;
    struct node * prev;    
}node;


typedef struct deque
{
    struct node * first;
    struct node * last;
    int count;
} deque;


deque * init_deque  ();
void free_deque  (deque * q);

//VORDERES ENDE
// einfügen
void put(deque * q,int val);
//entnehmen und entfernen
int get (deque * q);
//nur auslesen
int first (deque * q);

//HINTERES ENDE 
//einfügen
void push(deque * q,int val);
//entnehmen und entfernen
int pop (deque * q);
//nur auslesen
int last (deque * q);
//alles ausgeben
void all(deque * q);
