#include<iostream>

using namespace std ;

// n = 8
int RCRec(int price[], int n)
{
    int max = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {
        int fp = RCRec(price, left) ;
        int sp = RCRec(price, right) ;

        int total = fp + sp ;

        if(total > max)
            max = total ;

        left++ ;
        right-- ;
    }

    return max ;
}

// n = 8 
int RCTD(int price[], int n, int strg[])
{
    if(strg[n] != -1)
        return strg[n] ;

    int max = price[n] ;

    int left = 1 ;
    int right = n-1 ;

    while(left <= right)
    {
        int fp = RCTD(price, left, strg) ;
        int sp = RCTD(price, right, strg) ;

        int total = fp + sp ;

        if(total > max)
            max = total ;

        left++ ;
        right-- ;
    }

    strg[n] = max ;

    return max ;
}

// total = 9
int RCBU(int price[], int total)
{
    int strg[total] ;

    for(int n = 1 ; n < total ; n++)
    {
        int max = price[n] ;

        int left = 1 ;
        int right = n-1 ;

        while(left <= right)
        {
            int fp = strg[left] ;
            int sp = strg[right] ;

            int total = fp + sp ;

            if(total > max)
                max = total ;

            left++ ;
            right-- ;
        }

        strg[n] = max ;
    }

    return strg[total-1] ;
}

int main()
{
    int price[] = {0,3,5,8,9,10,17,17,20,23,56,89,12} ;
    int n = sizeof(price) / sizeof(int) ;

    cout << RCRec(price, n-1) << endl ;

    int strg[n] ;
    for(int i = 0 ; i < n ; i++)
        strg[i] = -1 ;
    cout << RCTD(price, n-1, strg) << endl ;

    cout << RCBU(price, n) << endl ;

    return 0 ;
}