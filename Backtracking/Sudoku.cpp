#include<iostream>

using namespace std ;

bool isItSafe(int arr[][9], int cr, int cc, int val)
{
    // row
    for(int c = 0 ; c < 9 ; c++)
    {
        if(arr[cr][c] == val)
            return false ;
    }

    // column
    for(int r = 0  ; r < 9 ; r++)
    {
        if(arr[r][cc] == val)
            return false ;
    }

    // 3 x 3 box
    int sr = cr / 3 * 3 ;
    int sc = cc / 3 * 3 ;

    for(int i = sr ; i < sr+3 ; i++)
    {
        for(int j = sc ; j < sc+3 ; j++)
        {
            if(arr[i][j] == val)
                return false ;
        }
    }

    return true ;
}
void display(int arr[][9])
{
    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }

    cout << "-------------------------" << endl ;
}
void sudoku(int arr[][9], int cr, int cc)
{
    if(cc == 9)
    {
        cr ++ ;
        cc = 0 ;
    }

    if(cr == 9)
    {
        display(arr) ;
        return ;
    }

    if(arr[cr][cc] != 0)
    {
        sudoku(arr, cr, cc+1) ;
        return ;
    }

    for(int i = 1 ; i <= 9 ; i++)
    {
        if(isItSafe(arr,cr, cc, i))
        {
            arr[cr][cc] = i ;
            sudoku(arr, cr, cc+1) ;
            arr[cr][cc] = 0 ;
        }
    }
}

int main()
{
    int arr[9][9] = {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}} ;

    sudoku(arr,0,0) ;

    return 0 ;
}