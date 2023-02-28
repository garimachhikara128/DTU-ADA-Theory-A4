#include<iostream>
#include<limits.h>

using namespace std ;

int MCMRec(int arr[], int si, int ei)
{
    if(si + 1 == ei)
        return 0 ;

    int min = INT_MAX ;

    for(int k = si+1 ; k <= ei-1 ; k++)
    {
        int fp = MCMRec(arr, si, k) ;
        int sp = MCMRec(arr, k, ei) ;
        int sw = arr[si] * arr[k] * arr[ei] ;

        int total = fp + sp + sw ;

        if(total < min)
            min = total ;
    }

    return min ;
}

int MCMTD(int arr[], int si, int ei, int **strg)
{
    if(si + 1 == ei)
        return 0 ;

    if(strg[si][ei] != -1)
        return strg[si][ei] ;

    int min = INT_MAX ;

    for(int k = si+1 ; k <= ei-1 ; k++)
    {
        int fp = MCMTD(arr, si, k, strg) ;
        int sp = MCMTD(arr, k, ei, strg) ;
        int sw = arr[si] * arr[k] * arr[ei] ;

        int total = fp + sp + sw ;

        if(total < min)
            min = total ;
    }

    strg[si][ei] = min ;

    return min ;
}

int MCMBU(int arr[], int n)
{
    int strg[n][n] ;

    for(int slide = 1 ; slide <= n-1 ; slide++)
    {
        for(int si = 0 ; si <= n-slide-1 ; si++)
        {
            int ei = si + slide ;

            if(si + 1 == ei)
                strg[si][ei] = 0 ;
            else
            {
                int min = INT_MAX ;

                for(int k = si+1 ; k <= ei-1 ; k++)
                {
                    int fp = strg[si][k] ;
                    int sp = strg[k][ei] ;
                    int sw = arr[si] * arr[k] * arr[ei] ;

                    int total = fp + sp + sw ;

                    if(total < min)
                        min = total ;
                }

                strg[si][ei] = min ;
            }

        }
    }

    return strg[0][n-1] ;
}

int main()
{
    int arr[] = {4,2,3,5,1,7,1,2,3,4,5,9,10,12,13,15} ;
    int n = 16 ;
    cout << MCMRec(arr, 0, n-1) << endl ; 

    int **strg = new int*[n] ;
    for(int i = 0 ; i < n ; i++)
    {  
        strg[i] = new int[n] ;
        for(int j = 0 ; j < n ; j++)
            strg[i][j] = -1 ;
    }

    cout << MCMTD(arr, 0, n-1, strg) << endl ;
    cout << MCMBU(arr, n) << endl ;

    return 0 ;
}