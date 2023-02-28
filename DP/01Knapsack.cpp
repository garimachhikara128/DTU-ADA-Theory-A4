#include<iostream>

using namespace std ;

int KnapsackRec(int weight[], int price[], int n, int vidx, int cap)
{
    if(vidx == n || cap == 0)
        return 0 ;

    // exclude
    int exclude = KnapsackRec(weight, price, n, vidx+1, cap) ;

    // include
    int include = 0;
    if(cap >= weight[vidx])
        include = KnapsackRec(weight, price, n, vidx+1, cap-weight[vidx]) + price[vidx] ;

    int ans = max(exclude, include) ;

    return ans ;
}

int KnapsackTD(int weight[], int price[], int n, int vidx, int cap, int **strg)
{
    if(vidx == n || cap == 0)
        return 0 ;

    if(strg[vidx][cap] != -1)
        return strg[vidx][cap] ;

    // exclude
    int exclude = KnapsackTD(weight, price, n, vidx+1, cap, strg) ;

    // include
    int include = 0;
    if(cap >= weight[vidx])
        include = KnapsackTD(weight, price, n, vidx+1, cap-weight[vidx], strg) + price[vidx] ;

    int ans = max(exclude, include) ;

    strg[vidx][cap] = ans ; 
    return ans ;
}

int KnapsackBU(int weight[], int price[], int n, int cap)
{
    int strg[n+1][cap+1] ;

    for(int i = 0 ; i <= n ; i++)
        strg[i][0] = 0 ;
    for(int j = 0 ; j <= cap ; j++)
        strg[n][j] = 0 ;

    for(int i = n-1 ; i >=0 ; i--)
    {
        for(int j = 1 ; j <= cap ; j++)
        {
            // exclude
            int exclude = strg[i+1][j] ;

            // include
            int include = 0;
            if(j >= weight[i])
                include = strg[i+1][j-weight[i]] + price[i] ;

            int ans = max(exclude, include) ;

            strg[i][j] = ans ; 
        }
    }

    for(int i = 0 ; i < n ; i++)
    {  
        for(int j = 0 ; j < cap+1 ; j++)
           cout << strg[i][j] << "\t" ;
        cout << endl ;
    }

    return strg[0][cap] ;

}

int main()
{
    int weight[] = {1,3,4,5} ;
    int price[] =  {1,4,5,7} ;
    int n = sizeof(weight) / sizeof(int) ;
    int cap = 7 ;

    cout << KnapsackRec(weight, price, n, 0, cap) << endl ;

    int **strg = new int*[n] ;
    for(int i = 0 ; i < n ; i++)
    {  
        strg[i] = new int[cap+1] ;
        for(int j = 0 ; j < cap+1 ; j++)
            strg[i][j] = -1 ;
    }

    cout << KnapsackTD(weight, price, n, 0, cap, strg) << endl ;
    cout << KnapsackBU(weight, price, n, cap) << endl ;

}