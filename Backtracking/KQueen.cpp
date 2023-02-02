#include<iostream>
#include<string.h>

using namespace std ;

const int n = 4 ;
int c = 0 ;

bool isItSafe(bool board[][n], int row, int col)
{

    // vertically up
    int r = row - 1 ;
    int c = col ;

    while(r >= 0)
    {
        if(board[r][c] == true)
            return false ;

        r -- ;
    }

    // diagonally left
    r = row -1 ;
    c = col -1 ;

    while(r >=0 && c >=0)
    {
        if(board[r][c] == true)
            return false ;

        r -- ;
        c-- ;
    }

    // diagonally right
    r = row -1 ;
    c = col +1 ;

    while(r >=0 && c < n)
    {
        if(board[r][c] == true)
            return false ;

        r -- ;
        c ++ ;
    }

    return true ;
}

void kQueen(bool board[][n], int row, string ans, int k, int qpsf)
{
    if(qpsf == k)
    {
        cout << (++c) << " " << ans << endl ;
        return ;
    }

    if(row == n)
        return ;

    for(int col = 0 ; col < n ; col++)
    {
        if(isItSafe(board, row, col))
        {
            board[row][col] = true ;
            kQueen(board, row+1, ans + "{" + to_string(row) + "-" + to_string(col) + "}", k, qpsf+1) ;
            board[row][col] = false ;
        }
    } 

    kQueen(board, row+1, ans, k , qpsf) ;      
}

int main()
{
    bool board[n][n] = {{false}} ;
    kQueen(board, 0, "", 3, 0) ;
    return 0 ;
}