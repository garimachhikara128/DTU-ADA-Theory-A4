#include<iostream>

using namespace std ;

void SOE (int) ;

int main()
{
    SOE(25);
    return 0 ;
}

// SIEVE OF ERATOSTHENISE
void SOE(int n)
{
    bool *primes = new bool[n+1] ;

    for(int i = 0 ; i <= n ; i++)
        primes[i] = true ;
    
    primes[0] = false ;
    primes[1] = false ;

    for(int table = 2 ; table * table <= n ; table++)
    {
        if(primes[table] == false)
            continue ;

        for(int mult = 2 ; table * mult <= n; mult++)
        {
            primes[table * mult] = false ;
        }
    }

    for(int i = 0 ; i <= n ; i++)
    {
        if(primes[i] == true)
            cout << i << endl ;
    }
}