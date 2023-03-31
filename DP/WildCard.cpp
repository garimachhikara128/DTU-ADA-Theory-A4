#include<iostream>
#include<string.h>

using namespace std ;

int WCMRec(string src, string pat, int svidx, int pvidx)
{
    // both are blank
    if(svidx == src.length() && pvidx == pat.length())
        return 1 ;

    // src is not blank but pattren is blank
    else if(svidx < src.length() && pvidx == pat.length())
        return 0 ;
    
    // src is blank but pattern is not blank
    else if(svidx == src.length() && pvidx < pat.length())
    {
        for(int i = pvidx ; i < pat.length() ; i++)
        {
            if(pat[i] != '*')
                return 0 ;
        }

        return 1 ;
    }

    char sch = src[svidx] ;
    char pch = pat[pvidx] ;

    int ans ;

    if(sch == pch || pch == '?')
    {
        ans = WCMRec(src, pat, svidx+1, pvidx+1) ;
    }
    else if (pch == '*')
    {
        int o1 = WCMRec(src, pat, svidx, pvidx+1) ;
        int o2 = WCMRec(src, pat, svidx+1, pvidx) ;

        ans = o1 || o2 ;
    }
    else
    {
        ans = 0 ;
    }

    return ans ;
}

int WCMTD(string src, string pat, int svidx, int pvidx, int **strg)
{
    // both are blank
    if(svidx == src.length() && pvidx == pat.length())
        return 1 ;

    // src is not blank but pattren is blank
    else if(svidx < src.length() && pvidx == pat.length())
        return 0 ;
    
    // src is blank but pattern is not blank
    else if(svidx == src.length() && pvidx < pat.length())
    {
        for(int i = pvidx ; i < pat.length() ; i++)
        {
            if(pat[i] != '*')
                return 0 ;
        }

        return 1 ;
    }

    if(strg[svidx][pvidx] != -1)
        return strg[svidx][pvidx] ;

    char sch = src[svidx] ;
    char pch = pat[pvidx] ;

    int ans ;

    if(sch == pch || pch == '?')
    {
        ans = WCMTD(src, pat, svidx+1, pvidx+1, strg) ;
    }
    else if (pch == '*')
    {
        int o1 = WCMTD(src, pat, svidx, pvidx+1, strg) ;
        int o2 = WCMTD(src, pat, svidx+1, pvidx, strg) ;

        ans = o1 || o2 ;
    }
    else
    {
        ans = 0 ;
    }

    strg[svidx][pvidx] = ans ;

    return ans ;
}

bool WCMBU(string src, string pat)
{
    bool strg[src.length()+1][pat.length()+1] ;

    strg[src.length()][pat.length()] = true ;

    // last column
    for(int i = src.length() - 1 ; i >=0 ; i--)
        strg[i][pat.length()] = 0 ;
    // last row
    for(int j = pat.length()-1 ; j >=0 ; j--)
    {
        if(pat[j] == '*')
            strg[src.length()][j] = strg[src.length()][j+1] ;
        else
            strg[src.length()][j] = false ;
    }
    
    for(int i = src.length() - 1 ; i >=0 ; i--)
    {
        for(int j = pat.length() - 1 ; j >=0 ; j--)
        {
            char sch = src[i] ;
            char pch = pat[j] ;

            int ans ;

            if(sch == pch || pch == '?')
            {
                ans = strg[i+1][j+1] ;
            }
            else if (pch == '*')
            {
                int o1 = strg[i][j+1] ; 
                int o2 = strg[i+1][j] ;

                ans = o1 || o2 ;
            }
            else
            {
                ans = 0 ;
            }

            strg[i][j] = ans ;
        }
    }

    for(int i = 0 ; i <= src.length() ; i++)
    {  
       for(int j = 0 ; j <= pat.length() ; j++)
            cout << strg[i][j] << " " ;
        cout << endl ;
    }

    return strg[0][0] ;
}

int main()
{
    string src = "abcd" ;
    string pat = "?*?c**" ;

    // cout << WCMRec(src, pat, 0, 0) << endl ;

    int row = src.length() ;
    int col = pat.length() ;
    
    int **strg = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {  
        strg[i] = new int[col] ;
        for(int j = 0 ; j < col ; j++)
            strg[i][j] = -1 ;
    }

    cout << WCMTD(src, pat, 0, 0, strg) << endl ;

    cout << WCMBU(src, pat) << endl ;

}