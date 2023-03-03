#include <iostream>
using namespace std;
 
struct Item
{
    int price ;
    int weight ;
} ;

// item a should come before item b ?
// true : no swapping
// false : swapping
bool compare(Item a, Item b)
{
    double ra = (double)a.price / (double) a.weight ;
    double rb = (double) b.price / (double) b.weight ;

    return ra > rb ;
}

int fractionalKnapsack(Item arr[], int n, int cap)
{
    sort(arr, arr+n, compare) ;

    double totalProfit = 0.0 ;

    for(int i = 0 ; i < n ; i++)
    {
        // put the item entirely
        if(arr[i].weight <= cap)
        {
            totalProfit += arr[i].price ;
            cap -= arr[i].weight ;
        }
        // put a fraction of item
        else
        {
            totalProfit += arr[i].price * ((double)cap / (double)arr[i].weight);
            break ;
        }
    }

    return totalProfit ;
}

int main()
{
    Item arr[] = {{60,10}, {120,30}, {100,20}} ;
    int cap = 50 ;
    int n = sizeof(arr) / sizeof(arr[0]) ;

    cout << fractionalKnapsack(arr,n,cap) << endl ;

    return 0;
}