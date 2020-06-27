#include<bits/stdc++.h>
using namespace std;
 
int n,sum;
vector < pair<int,int> > v[102];
vector <int> color(102,0);
map <string,int> mp1;
unordered_map <int,int> dis;
 
int node,edge;
 
void dijkstra(int src)
{
   for(int i=1; i<=node; i++) dis[i] = INT_MAX;
 
    dis[src] = 0;
 
    set < pair<int,int> > s;
    s.insert({0,src});
 
    //Edge[src] = {src,src};
 
    while(!s.empty()){
 
        auto it = s.begin();
        int Node = it->second;
        s.erase(it);
 
        color[Node]=1;
        //cout << "(" << Edge[Node].first << "," << Edge[Node].second<< "," << dis[Edge[Node].second] << ") ";
        //sum+=dis[Node];
 
        for(int i=0; i<v[Node].size(); i++){
            int n1 = v[Node][i].first;
            int cost = v[Node][i].second+dis[Node];
 
            if(cost<dis[n1] && !color[n1]){
                auto f = s.find({dis[n1],n1});
 
 
                if(f!=s.end()){
                    s.erase(f);
 
                }
 
                dis[n1] = cost;
                s.insert({dis[n1],n1});
                //Edge[n1] = {Node,n1};
 
                //p.insert({})
            }
 
        }
 
 
 
    }
 
 
 
}
 
void Clear()
{
    for(int i=1; i<=node; i++){
        v[i].clear();
        color[i] = 0;
    }
    dis.clear();
    mp1.clear();
}
 
int main()
{
    //freopen("text.txt", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    int t,kk=0;
    cin >> t;
 
    while(t--){
        int pum=0,k=1;
        cin >> node >> edge;
 
        for(int i=0; i<edge; i++){
 
            int a1,a2,w;
            cin >> a1 >> a2 >> w;
 
            v[a1].push_back({a2,w});
            v[a2].push_back({a1,w});
 
        }
 
        dijkstra(1);
        int j;
        cout << "Case " << ++kk << ": ";
 
        if(!color[node]){
            cout << "Impossible\n";
        }
        else{
            cout << dis[node] << '\n';
        }
 
 
 
        Clear();
 
    }
 
 
    return 0;
}
