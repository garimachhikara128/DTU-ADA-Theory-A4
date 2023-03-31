#include<iostream>
#include<map>
#include<queue>

using namespace std ;

class Graph
{
    map<int, map<int, int> > strg ;
    int V ;

    public :

    Graph(int V)
    {
        this->V = V ;
    }

    void addEdge(int u, int v, int cost)
    {
        strg[u][v] = cost ;
        strg[v][u] = cost ;
    }

    void display()
    {
        cout << strg[0][1] << endl ;
        for(int i = 0; i < V ; i++)
        {
            cout << i << "\t" ;

            map<int, int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cout << itr->first << "@" << itr->second << ", " ;
            
            cout << endl ;
        }
    }

    bool isItSafe(int path[], int nbr)
    {
        for(int i = 0 ; i < V ; i++)
        {
            if(path[i] == nbr)
                return false ;
        }

        return true ;
    }

    int TSP(int src, int curr, int path[], int idx)
    {
        if(idx == V)
        {
            if(strg[src].count(curr) != 0)
                return strg[curr][src] ;
            else
                return 100000 ;
        }
       
        int minimum = INT_MAX ;
        map<int, int>::iterator itr ;

        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if(isItSafe(path, nbr))
            {
                path[idx] = nbr ;
                int rc = TSP(src, nbr, path, idx+1) + strg[curr][nbr] ;
                minimum = min(minimum, rc) ;
                path[idx] = -1 ;
            }
        }

        return minimum ;

    }

} ;

int main()
{
    int n = 4 ;
    Graph g(n) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,2,8) ;
    g.addEdge(0,3,7) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,5) ;
    g.addEdge(2,3,1) ;


    g.display() ;
    int path[n] ;
    for(int i = 0 ; i < n ; i++)
        path[i] = -1 ; 
    path[0] = 0 ;

    cout << g.TSP(0, 0, path, 1) << endl ;

    return 0 ;
}