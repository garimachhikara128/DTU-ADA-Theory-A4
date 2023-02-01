#include<iostream>

using namespace std ;

bool isItPossible(int noc, int nos, int *stalls, int minDistance)
{
    int numCowsPlaced = 1 ;
    int lastPos = stalls[0] ;

    for(int s = 1 ; s < nos ; s++)
    {
        if(stalls[s] - lastPos >= minDistance)
        {
            numCowsPlaced ++ ;
            lastPos = stalls[s] ;
        }

        if(numCowsPlaced == noc)
            return true ;
    }

    return false ;
}

int main()
{
    int stalls[] = {1,2,4,8,9} ;
    // sort the stalls array

    int noc = 3 ;
    int nos = 5 ;

    // binary search
    int lo = 0 ;
    int hi = stalls[nos-1] - stalls[0] ;
    int res = 0 ;

    while(lo <= hi)
    {
        int mid = (lo+hi)/2 ;

        if(isItPossible(noc, nos, stalls, mid))
        {
            lo = mid + 1 ;
            res = mid ;
        }
        else
            hi = mid - 1;

    }

    cout << res << endl ;

    return 0 ;
}

