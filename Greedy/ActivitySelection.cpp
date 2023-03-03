#include <iostream>
using namespace std;
 
struct Activity
{
    int start ;
    int finish ;
} ;

// a should come before b ?
// true : no swapping
// false : swapping
bool compare(Activity a, Activity b)
{
    return a.finish < b.finish ;   
}

void maxActivity(Activity arr[], int n)
{
    sort(arr, arr+n, compare) ;

    // i will keep a track of last class that you attended
    int i = 0 ;
    cout << arr[i].start << ", " << arr[i].finish << endl ;

    for(int j = 1 ; j < n ; j++)
    {
        if(arr[j].start >= arr[i].finish)
        {
            cout << arr[j].start << ", " << arr[j].finish << endl ;
            i = j ;
        }

    }
}

int main()
{
    Activity arr[] = {{5,9}, {1,2}, {3,4}, {0,6}, {5,7}, {8,9}} ;
    int n = sizeof(arr) / sizeof(arr[0]) ;
    maxActivity(arr, n) ;

    return 0;
}