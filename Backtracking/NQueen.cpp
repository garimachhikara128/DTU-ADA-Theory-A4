#include<iostream>
#include<string.h>

using namespace std ;

const int n = 5 ;
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

void nQueen(bool board[][n], int row, string ans)
{
    if(row == n)
    {
        cout << (++c) << " " << ans << endl ;
        return ;
    }
    for(int col = 0 ; col < n ; col++)
    {
        if(isItSafe(board, row, col))
        {
            board[row][col] = true ;
            nQueen(board, row+1, ans + "{" + to_string(row) + "-" + to_string(col) + "}") ;
            board[row][col] = false ;
        }
    } 
}

int main()
{
    bool board[n][n] = {{false}} ;
    nQueen(board, 0, "") ;
    return 0 ;
}