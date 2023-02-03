#include<iostream>

using namespace std ;

const int n = 4 ;
int c = 0 ;
void display(bool arr[][n])
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << arr[i][j] << " " ;
        }
        cout << endl ;
    }

    cout << "-------------------------" << endl ;
}

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

    // horizontally left
    r = row ;
    c = col - 1 ;

    while(c >= 0)
    {
        if(board[r][c] == true)
            return false ;

        c -- ;
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


void kQueen2(bool board[][n], int row, int col, int k, int qpsf, string ans)
{
    if(qpsf == k)
    {
        // display(board) ;
        cout << (++c) << " " << ans << endl ;
        return ;
    }

    if(col == n)
    {
        row ++ ;
        col = 0;
    }

    if(row == n)
    {
        return ;
    }

    // Place
    if(isItSafe(board, row, col))
    {
        board[row][col] = true ;
        // kQueen2(board, row, col+1, k, qpsf + 1, ans + "{" + to_string(row) + "-" + to_string(col) + "}") ;
        kQueen2(board, row+1, 0, k, qpsf + 1, ans + "{" + to_string(row) + "-" + to_string(col) + "}") ;

        board[row][col] = false ;
    }

    // Dont Place
    kQueen2(board, row, col+1, k, qpsf, ans) ;
}

int main()
{
    bool board[n][n] = {{false}} ;
    kQueen2(board, 0, 0, 3, 0, "") ;
    return 0 ;
}