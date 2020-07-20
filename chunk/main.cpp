#include <iostream> 
#include <deque> 
#include <chrono>
 
using namespace std; 
  
int main() 
{
  auto start = std::chrono::high_resolution_clock::now();
    deque <int> gquiz; 
 

    for(int i = 0; i < 500000;i++)
    {
    gquiz.push_back(10); 
    gquiz.push_front(20); 
    }

  auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

 cout << "Anfügen: "<< microseconds << endl;

     start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 500000;i++)
    {
    gquiz.pop_back(); 
    gquiz.pop_front(); 
    }


  elapsed = std::chrono::high_resolution_clock::now() - start;

 microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

 cout << "Entfernen: "<< microseconds << endl;

    return 0; 
} 
