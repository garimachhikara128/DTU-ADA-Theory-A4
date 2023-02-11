#include<iostream>

using namespace std ;

int FibRec(int n)
{
    if(n == 0 || n == 1)
        return n ;

    int fnm1 = FibRec(n-1) ;
    int fnm2 = FibRec(n-2) ;

    int fn = fnm1 + fnm2 ;

    return fn ;
}

// 1. copy change the fxn name
// 2. strg array
// 3. at problem index -> solution
// 4. reuse the result
int FibTD(int n, int strg[])
{
    if(n == 0 || n == 1)
        return n ;

    if(strg[n] != -1) // re-using
        return strg[n] ;

    int fnm1 = FibTD(n-1, strg) ;
    int fnm2 = FibTD(n-2, strg) ;

    int fn = fnm1 + fnm2 ;

    strg[n] = fn ; // storing

    return fn ;
}

int FibBU(int n)
{
    int strg[n+1] ;

    strg[0] = 0 ;
    strg[1] = 1 ;

    for(int i = 2 ; i <= n ; i++)
    {
        strg[i] = strg[i-1] + strg[i-2];
    }

    return strg[n] ;

}

int FibBUSE(int n)
{
    int a = 0 ;
    int b = 1 ;

    for(int slide = 1 ; slide <= n ; slide++)
    {
        int sum = a+ b ;
        a = b ;
        b = sum ;
    }

    return a ;
}

int main()
{
    int n = 100 ;
    int strg[n] ;
    for(int i = 0 ; i <= n ; i++)
    {
        strg[i] = -1 ;
    }

    // cout << FibRec(n) << endl ;
    cout << FibTD(n, strg) << endl ;
    cout << FibBU(n) << endl ;
    cout << FibBUSE(n) << endl ;

    return 0 ;
}