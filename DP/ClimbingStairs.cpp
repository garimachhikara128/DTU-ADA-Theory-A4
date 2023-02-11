#include<iostream>
#include<string>

using namespace std ;

void CSWays(int curr, int n, string ans)
{
    if(curr == n)
    {
        cout << ans << endl ;
        return ; 
    }

    if(curr > n)
        return ;

    CSWays(curr+1, n, ans +"1") ;
    CSWays(curr+2, n, ans +"2") ;
    CSWays(curr+3, n, ans +"3") ;
}

int CSRec(int curr, int n)
{
    if(curr == n)
        return 1; 

    if(curr > n)
        return 0;

    int c1 = CSRec(curr+1, n) ;
    int c2 = CSRec(curr+2, n) ;
    int c3 = CSRec(curr+3, n) ;

    return c1 + c2 + c3 ;
}

int CSTD(int curr, int n, int *strg)
{
    if(curr == n)
        return 1; 

    if(curr > n)
        return 0;

    if(strg[curr] != -1)
        return strg[curr] ;

    int c1 = CSTD(curr+1, n, strg) ;
    int c2 = CSTD(curr+2, n, strg) ;
    int c3 = CSTD(curr+3, n, strg) ;

    strg[curr] = c1 + c2 + c3 ;

    return c1 + c2 + c3 ;
}

int CSBU(int n)
{
    int strg[n+3] ;
    strg[n] = 1 ;
    strg[n+1] = 0 ;
    strg[n+2] = 0 ;

    for(int i = n-1 ; i >=0 ; i --)
        strg[i] = strg[i+1] + strg[i+2] + strg[i+3] ;

    return strg[0] ;

}

int CSBUSE(int n)
{
    int strg[3] ;
    strg[0] = 1 ;
    strg[1] = 0 ;
    strg[2] = 0 ;

    for(int slide = 1 ; slide <= n ; slide++)
    {
        int sum = strg[0] + strg[1] + strg[2] ;
        strg[2] = strg[1] ;
        strg[1] = strg[0] ;
        strg[0] = sum ;
    }

    return strg[0] ;

}

int main()
{
    int n = 5 ;
    // cout << CSRec(0, n) << endl ;

    int strg[n] ;
    for(int i = 0 ; i <= n ; i++)
    {
        strg[i] = -1 ;
    }
    cout << CSTD(0, n, strg) << endl ;
    cout << CSBU(n) << endl ;
    cout << CSBUSE(n) << endl ;
    
    return 0 ;
}