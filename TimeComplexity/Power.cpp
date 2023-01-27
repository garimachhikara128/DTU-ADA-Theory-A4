#include<iostream>

using namespace std ;

int power (int, int) ;

int main()
{
    cout << power(3,683646876876658l) ;
    return 0 ;
}

// FAST EXPONENTIATION METHOD
int power(int x, int n)
{
    if(n == 0)
        return 1;

    int sp = power(x,n/2) ;
    if (n % 2 == 0)
    {
        return  sp * sp  ;
    }
    else
    {
        return sp * sp * x ;
    }
}