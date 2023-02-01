#include<iostream>
#include<string.h>

using namespace std ;

void blockedMaze(int arr[][4], int cr, int cc, int er, int ec, string ans, bool visited[][4])
{
    if(cr == er && cc == ec)
    {
        cout << ans << endl ;
        return ; 
    }
    if(cr < 0 || cr > er || cc < 0 || cc > ec || visited[cr][cc] || arr[cr][cc] == 1)
        return ;

    visited[cr][cc] = true ;
    blockedMaze(arr, cr-1, cc, er, ec, ans+"T", visited) ; // T
    blockedMaze(arr, cr+1, cc, er, ec, ans+"B", visited) ; // B
    blockedMaze(arr, cr, cc-1, er, ec, ans+"L", visited) ; // L
    blockedMaze(arr, cr, cc+1, er, ec, ans+"R", visited) ; // R
    visited[cr][cc] = false ;
}

int main()
{
    int arr[4][4] = {{0,1,0,0},{0,0,0,0},{0,1,0,0},{0,0,1,0}} ;
    bool visited[4][4] = {{false, false, false, false},{false, false, false, false},{false, false, false, false},{false, false, false, false}} ;
    blockedMaze(arr, 0, 0, 3,3,"", visited) ;
    return 0 ;
}



