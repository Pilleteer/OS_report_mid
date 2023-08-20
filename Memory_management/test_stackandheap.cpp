#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int g1;
int g2;
int g3=3;

int get_overflow(int n){
   return get_overflow(n+1);
}

int test_gb(){
    cout << "Address of global g2 in function: " << &g2 << endl;
    g2=2;
    cout << "Address of global g2 after get value: " << &g2 << endl;
    cout << "Value of global g2: " << g2 << endl;
    return 0;
}

int call_stack_address(int n){
    int s;
    if(n>=4){
        return 0;
    }
    cout << "Address of stack s"<< n << ": " << &s << endl;

    return call_stack_address(n+1);
}

int call_heap_address(){
    int *h1=(int *)malloc(sizeof(int));
    int *h2=(int *)malloc(sizeof(int));
    int *h3=(int *)malloc(sizeof(int));

    cout << "Address of heap h1: " << h1 << endl;
    cout << "Address of heap h2: " << h2 << endl;
    cout << "Address of heap h3: " << h3 << endl;

    free(h1);
    free(h2);
    free(h3);
    return 0;
}
int main() {
    char get_of;
    while(get_of!='y' && get_of!='n')
    {
        cout << "Do you want to stack overflow?[y/n]: ";
        cin >> get_of;
        if(get_of!='y' && get_of!='n')
            cout << "Please enter y or n" << endl;
        else
            break;
    }
    if(get_of=='y'){
        get_overflow(1);
    }

    cout << "-----Global variable-----" << endl;
    cout << "Address of global g1: " << &g1 << endl;
    cout << "Address of global g2: " << &g2 << endl;
    cout << "Address of global g3: " << &g3 << endl;
    cout << "-----Test g2 variable-----" << endl;
    test_gb();
    cout << "-----Test stack address-----" << endl;
    call_stack_address(1);// call stack
    cout << "-----Test heap address-----" << endl;
    call_heap_address();// call heap
    return 0;
}