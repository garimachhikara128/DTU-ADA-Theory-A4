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

    int TSP(int src, int curr, int visited)
    {
        if(visited == ((1 << V) - 1))
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

            if((visited & (1 << nbr)) == 0)
            {
                int rc = TSP(src, nbr, (visited | (1 << nbr))) + strg[curr][nbr] ;
                minimum = min(minimum, rc) ;
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

    cout << g.TSP(0, 0, 1) << endl ;

    return 0 ;
}