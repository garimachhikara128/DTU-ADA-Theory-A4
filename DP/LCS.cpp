#include<iostream>
#include<string.h>

using namespace std ;

int LCSRec(string s1, string s2, int vidx1, int vidx2)
{
    if(vidx1 == s1.length() || vidx2 == s2.length())
        return 0 ;

    int ans ;

    if(s1[vidx1] == s2[vidx2])
    {
        ans = LCSRec(s1, s2, vidx1+1, vidx2+1) + 1 ;
    }
    else
    {
        int o1 = LCSRec(s1, s2, vidx1, vidx2+1) ;
        int o2 = LCSRec(s1, s2, vidx1+1, vidx2) ;

        ans = max(o1, o2) ;
    }

    return ans ;
}

int LCSTD(string s1, string s2, int vidx1, int vidx2, int **strg)
{
    if(vidx1 == s1.length() || vidx2 == s2.length())
        return 0 ;

    if(strg[vidx1][vidx2] != -1)
        return strg[vidx1][vidx2] ;

    int ans ;

    if(s1[vidx1] == s2[vidx2])
    {
        ans = LCSTD(s1, s2, vidx1+1, vidx2+1, strg) + 1 ;
    }
    else
    {
        int o1 = LCSTD(s1, s2, vidx1, vidx2+1, strg) ;
        int o2 = LCSTD(s1, s2, vidx1+1, vidx2, strg) ;

        ans = max(o1, o2) ;
    }

    strg[vidx1][vidx2] = ans ;

    return ans ;
}

int LCSBU(string s1, string s2)
{
    int row = s1.length() ;
    int col = s2.length() ;
    int strg[row+1][col+1] ;

    // bc -> last row
    for(int j = 0 ; j <= col ; j++)
        strg[row][j] = 0 ;
    
    // bc -> last col
    for(int i = 0 ; i <= row ; i++)
        strg[i][col] = 0;

    for(int i = row-1 ; i >=0 ; i--)
    {
        for(int j = col-1 ; j >=0 ; j--)
        {
            if(s1[i] == s2[j])
            {
                strg[i][j] = strg[i+1][j+1] + 1 ;
            }
            else
            {
                strg[i][j] = max(strg[i][j+1], strg[i+1][j]) ;
            }
        }
    }

    return strg[0][0] ;
}

int main()
{
    string s1 = "abcdgdcugsduyvgceugweucgheucghuyguysdgcuwgheuchcgdshvcgehjgcuwegfcyu" ;
    string s2 = "agcfdcdhgcuygsduycge" ;

    // cout << LCSRec(s1, s2, 0, 0) << endl ;
    int row = s1.length() ;
    int col = s2.length() ;
    
    int **strg = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {  
        strg[i] = new int[col] ;
        for(int j = 0 ; j < col ; j++)
            strg[i][j] = -1 ;
    }

    cout << LCSTD(s1, s2, 0, 0, strg) << endl ;
    cout << LCSBU(s1, s2) << endl ;
    return 0 ;
}