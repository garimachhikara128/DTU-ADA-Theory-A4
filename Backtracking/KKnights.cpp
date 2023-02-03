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
    int rows[4] = {-1,-2,-2,-1} ;
    int cols[4] = {-2, -1,1, 2} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        int nr = row + rows[i] ;
        int nc = col + cols[i] ;

        if(nr >= 0 && nr < n && nc >=0 && nc < n && board[nr][nc])
            return false ;
    }

    return true ;
    
}


void kKnights(bool board[][n], int row, int col, int k, int qpsf, string ans)
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
        kKnights(board, row, col+1, k, qpsf + 1, ans + "{" + to_string(row) + "-" + to_string(col) + "}") ;
        board[row][col] = false ;
    }

    // Dont Place
    kKnights(board, row, col+1, k, qpsf, ans) ;
}

int main()
{
    bool board[n][n] = {{false}} ;
    kKnights(board, 0, 0, 4, 0, "") ;
    return 0 ;
}