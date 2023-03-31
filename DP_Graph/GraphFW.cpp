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
    }

    void display()
    {
        for(int i = 0; i < V ; i++)
        {
            cout << i << "\t" ;

            map<int, int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cout << itr->first << "@" << itr->second << ", " ;
            
            cout << endl ;
        }
    }

    void FloydWarshall()
    {
        int cost[V][V] ;

        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j++)
            {
                if(i == j)
                    cost[i][j] = 0 ;
                else
                    cost[i][j] = 100000 ;
            }
        }

        for(int i = 0; i < V ; i++)
        {
            map<int, int>::iterator itr ;

            for(itr = strg[i].begin() ; itr != strg[i].end() ; itr++)
                cost[i][itr->first] = itr->second  ;
           
        }

        // check the shorter path via k vertex
        for(int k = 0 ; k < V ; k++)
        {
            for(int i = 0 ; i < V ; i++)
            {
                for(int j = 0 ; j < V ; j++)
                {
                    int oc = cost[i][j] ;
                    int nc = cost[i][k] + cost[k][j] ;

                    if(nc < oc)
                        cost[i][j] = nc ;
                }
            }
        }

        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j++)
                cout << cost[i][j] << " " ;

            cout << endl ;
        }

    }

} ;

int main()
{

    Graph g(4) ;
    
    g.addEdge(0,1,3) ;
    g.addEdge(0,3,7) ;
    g.addEdge(1,0,8) ;
    g.addEdge(1,2,2) ;
    g.addEdge(2,0,5) ;
    g.addEdge(2,3,1) ;
    g.addEdge(3,0,2) ;

    g.display() ;

    g.FloydWarshall() ;

    return 0 ;
}