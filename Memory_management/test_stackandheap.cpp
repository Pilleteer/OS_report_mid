#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int get_overflow(int n){
   return get_overflow(n+1);
}
int cnt_to_zero(int n){
   if (n == 0){
       return 0;
   }
   else{
       cout << "Value of stack: "<< n << " Address of stack:" << &n << endl;;
       return cnt_to_zero(n-1);
   }
}
int keeping_malloc(){
    int *h1=(int *)malloc(sizeof(int));
    int *h2=(int *)malloc(sizeof(int));
    int *h3=(int *)malloc(sizeof(int));

    cout << "Address of h1: " << h1 << endl;
    cout << "Address of h2: " << h2 << endl;
    cout << "Address of h3: " << h3 << endl;

    free(h1);
    free(h2);
    free(h3);
    return 0;
}
int main() {
   int x,get_of;
   cout << "Enter a number: ";
   cin >> x;
   cout << "Do you want to overflow[enter 1 to get overflow]: ";
   cin >> get_of;
   if(get_of==1){
       get_overflow(get_of);
   }
   cnt_to_zero(x);// call stack
   keeping_malloc();// call heap
   return 0;
}