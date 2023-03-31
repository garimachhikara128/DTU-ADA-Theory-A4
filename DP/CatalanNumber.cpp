#include<iostream>

using namespace std ;

int CNRec(int n)
{
    if(n == 0 || n == 1)
        return 1 ;

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++)
    {
        int left_bsts = CNRec(i-1) ;
        int right_bsts = CNRec(n-i) ;

        int total_bsts_ith_rn = left_bsts * right_bsts ;

        ans += total_bsts_ith_rn ;
    }

    return ans ;

}

int CNTD(int n, int strg[])
{
    if(n == 0 || n == 1)
        return 1 ;

    if(strg[n] != -1)
        return strg[n] ;

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++)
    {
        int left_bsts = CNTD(i-1, strg) ;
        int right_bsts = CNTD(n-i, strg) ;

        int total_bsts_ith_rn = left_bsts * right_bsts ;

        ans += total_bsts_ith_rn ;
    }

    strg[n] = ans ;

    return ans ;

}

int CNBU(int tn)
{
    int strg[tn+1] ;
    strg[0] = strg[1] = 1 ;

    for(int n = 2 ; n <= tn ; n++)
    {
        int ans = 0 ;

        for(int i = 1 ; i <= n ; i++)
        {
            int left_bsts = strg[i-1] ;
            int right_bsts = strg[n-i] ;

            int total_bsts_ith_rn = left_bsts * right_bsts ;

            ans += total_bsts_ith_rn ;
        }

        strg[n] = ans ;
    }

    for(int i = 0 ; i <= tn ; i++)
    {
        cout << strg[i] << " ";
    }
    cout << endl ;

    return strg[tn] ;
}

int main()
{
    int n = 15 ;

    int strg[n+1] ;
    for(int i = 0 ; i <= n ; i++)
    {
        strg[i] = -1 ;
    }

    // cout << CNRec(1000) << endl ;
    cout << CNTD(n, strg) << endl ;

    cout << CNBU(n) ;
    return 0 ;
}