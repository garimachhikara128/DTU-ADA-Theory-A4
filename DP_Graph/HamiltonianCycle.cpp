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

    bool hamiltonian(int src, int curr, int path[], int idx)
    {
        if(idx == V)
        {
            if(strg[src].count(curr) != 0)
            {   
                for(int i = 0 ; i < V ; i++)
                {
                    cout << path[i] << " " ;
                }
                cout << endl ;

                return true ;
            }

            return false ;
        }

        int ans = false ;
        map<int, int>::iterator itr ;

        for(itr = strg[curr].begin() ; itr != strg[curr].end() ; itr++)
        {
            int nbr = itr->first ;

            if(isItSafe(path, nbr))
            {
                path[idx] = nbr ;
                ans = hamiltonian(src, nbr, path, idx+1) || ans ;
                path[idx] = -1 ;
            }
        }

        return ans ;
    }

} ;

int main()
{
    int n = 5 ;
    Graph g(n) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,3,8) ;
    g.addEdge(1,2,7) ;
    g.addEdge(1,3,2) ;
    g.addEdge(1,4,5) ;
    g.addEdge(2,4,1) ;
    g.addEdge(3,4,2) ;

    g.display() ;
    int path[n] ;
    for(int i = 0 ; i < n ; i++)
        path[i] = -1 ; 
    path[0] = 0 ;

    cout << g.hamiltonian(0, 0, path, 1) << endl ;

    return 0 ;
}