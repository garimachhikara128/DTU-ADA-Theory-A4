#include<iostream>
#include<string>

using namespace std ;

int const size = 5 ;

int WineRec(int arr[], int si, int ei, int yr)
{
    if(si == ei)
        return arr[si] * yr ;

    int start = WineRec(arr, si+1, ei, yr+1) + arr[si] * yr; 
    int end = WineRec(arr, si, ei-1, yr+1) + arr[ei] * yr ; 

    int ans = max(start, end) ;

    return ans ;
}

int WineTD(int arr[], int n, int si, int ei, int strg[][size])
{

    int yr = n - (ei-si+1) + 1 ;

    if(si == ei)
        return arr[si] * yr ;

    if(strg[si][ei] != -1)
        return strg[si][ei] ;

    int start = WineTD(arr, n, si+1, ei, strg) + arr[si] * yr; 
    int end = WineTD(arr, n, si, ei-1, strg) + arr[ei] * yr ; 

    int ans = max(start, end) ;

    strg[si][ei] = ans ; 

    return ans ;
}

int WineBU(int arr[], int n)
{
    int strg[n][n] ;

    for(int slide = 0 ; slide <= n-1 ; slide++)
    {
        for(int si = 0 ; si <= n-slide-1; si++)
        {
            int ei = si + slide ;

            // si, ei cell fill
            int yr = n - (ei-si+1) + 1 ;

            if(si == ei)
                strg[si][ei] = arr[si] * yr ;
            else
            {
                int start = strg[si+1][ei] + arr[si] * yr; 
                int end = strg[si][ei-1] + arr[ei] * yr ; 
                int ans = max(start, end) ;
                strg[si][ei] = ans ;   
            }

        }
    }

    return strg[0][n-1] ;
}

int main()
{
    int n = 5 ;
    int arr[] = {1,3,9,2,4} ;
    cout << WineRec(arr, 0, n-1, 1) << endl ;
    int strg[size][size] ;

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            strg[i][j] = -1 ;
        }
    }

    cout << WineTD(arr, n, 0, n-1, strg) << endl ;
    
    cout << WineBU(arr,n) << endl ;

    return 0 ;
}