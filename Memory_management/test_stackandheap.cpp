#include <iostream>

using namespace std;
int get_overflow(int n){
   return get_overflow(n+1);
}
int cnt_to_zero(int n){
   if (n == 0){
       return 0;
   }
   else{
       cout << "Value of n: "<< n << " Address of n:" << &n << endl;;
       return cnt_to_zero(n-1);
   }
}
int keeping_malloc(int n){
   if (n == 0){
       return 0;
   }
   int *p = (int*)malloc(sizeof(int));
   *p = n;
   cout << "Value of n: "<< *p << " Address of n:" << p << endl;
   n=n-1;
   return keeping_malloc(n);
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
   keeping_malloc(x);// call heap
   return 0;
}