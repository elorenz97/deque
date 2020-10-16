
#define DEQUE_SIZE 1000000

typedef struct deque
{
    int first;
    int last;
    int count;
    int values [DEQUE_SIZE];
} deque;

deque * init_deque ();
void free_deque  (deque * q);
//HINTERES ENDE
// einfügen
int push(deque * q,int val);
//entnehmen und entfernen
int pop (deque * q);
//nur auslesen
int last (deque * q);
//VORDERES ENDE
// einfügen
int put(deque * q,int val);
//entnehmen und entfernen
int get (deque * q);
//nur auslesen
int first (deque * q);
// alle ausgeben
void all(deque * q);


