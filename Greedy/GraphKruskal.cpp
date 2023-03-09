#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std ;

class Graph
{
    map<int, map<int, int> > strg ;
    int V ;
    vector<vector<int> > edgeList ; 

    public :

    Graph(int V)
    {
        this->V = V ;
    }

    void addEdge(int u, int v, int cost)
    {
        strg[u][v] = cost ;
        strg[v][u] = cost ;

        edgeList.push_back({u,v,cost}) ;
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

    class DisjointSet
    {
        int *parent ;
        int *rank ;

        public :

        DisjointSet(int n)
        {
            parent = new int[n] ;
            rank = new int[n] ;

            for(int i = 0 ; i < n ; i++)
            {
                parent[i] = i ;
                rank[i] = 0 ;
            }
        }

        int find(int v)
        {
            if(v == parent[v])
                return v ;
            
            int rr = find(parent[v]) ;
            parent[v] = rr ; // path compression
            return rr ;
        }

        void unite(int v1, int v2)
        {
            int re1 = find(v1) ;
            int re2 = find(v2) ;

            if(re1 != re2)
            {
                if(rank[re1] < rank[re2])
                    parent[re1] = re2 ;
                else if (rank[re1] > rank[re2])
                    parent[re2] = re1 ;
                else 
                {
                    parent[re2] = re1 ;
                    rank[re1] += 1 ;
                }
            }

        }
    } ;

    static bool compare(vector<int> vec1 , vector<int> vec2)
    {
        return vec1[2] < vec2[2] ;
    }

    void kruskal()
    {
        sort(edgeList.begin(), edgeList.end(), compare) ;

        DisjointSet ds(V) ;

        for(auto edge : edgeList)
        {
            int u = edge[0] ;
            int v = edge[1] ;
            int cost = edge[2] ;

            int re_u = ds.find(u) ;
            int re_v = ds.find(v) ;

            if(re_u != re_v)
            {
                ds.unite(u, v) ;
                cout << u << "-" << v << "@" << cost << endl ;
            }
        }


    }

} ;

int main()
{

    Graph g(7) ;
    
    g.addEdge(0,1,2) ;
    g.addEdge(1,2,3) ;
    g.addEdge(2,3,1) ;
    g.addEdge(0,3,6) ;
    g.addEdge(3,4,8) ;
    g.addEdge(4,5,5) ;
    g.addEdge(5,6,9) ;
    g.addEdge(4,6,7) ;

    g.display() ;

    g.kruskal() ;

    return 0 ;
}