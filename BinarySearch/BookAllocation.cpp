#include<iostream>

using namespace std ;

bool isItPossible(int pages[], int nob, int nos, int max)
{
    int students = 1 ;
    int pagesRead = 0 ;

    int i = 0 ;

    while(i < nob)
    {
        if(pagesRead + pages[i] <= max)
        {
            pagesRead += pages[i] ;
            i++ ;
        }
        else
        {
            students ++ ;
            pagesRead = 0 ;

            if(students > nos)
                return false ;
        }
    }

    return true ;

}

int main()
{

    int pages[] = {10,20,30,40} ;
    int nos = 2 ;
    int nob = 4 ;

    int lo = 0 ;
    int hi = 0 ;

    for(int val : pages)
        hi += val ;
    
    int res = 0 ;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2 ;

        if(isItPossible(pages, nob, nos, mid))
        {
            res = mid ;
            hi = mid - 1 ;
        }
        else
            lo = mid + 1 ;
    }

    cout << res ;

    return 0 ;
}