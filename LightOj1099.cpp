#include<bits/stdc++.h>
using namespace std;

#define mx 5005
#define INT_MAX 2000000000

struct hello
{
	int N;
	int cost;
	hello(){}
	hello(int nn, int costt) {N = nn; cost = costt;}
	bool operator < (const hello &node) const {return cost > node.cost;}
};

int n,sum;
vector < hello > v[mx];
bitset <mx> color, Back;
int dis[mx], dis2[mx], minWeight[mx];

int node,edge;

int dijkstra(int src)
{
    color.reset();
    Back.reset();
    memset(dis, -1, sizeof dis);
    memset(dis2, -1, sizeof dis2);

    for(int i = 1; i <= node; i++)
	{
		minWeight[i] = INT_MAX;
		for(auto it : v[i])
			minWeight[i] = min(minWeight[i], 2*it.cost);
	}

    priority_queue < hello > q;
    q.push({src,0});
    dis[src]=0;

    while(!q.empty()){
        hello tmp = q.top();
        q.pop();
        int Node = tmp.N;
        int weight = tmp.cost;

            if(dis[Node]<weight && (dis2[Node]>weight || dis2[Node] == -1))
                dis2[Node]=weight;

        color[Node]=1;

        for(auto it : v[Node]){
            int tot = it.cost+weight;
            int child = it.N;

            if(dis[child] == -1 || dis[child]>tot){
                dis2[child]=dis[child];
                dis[child]=tot;
                q.push({child,tot});
            }
            else if((dis2[child] == -1 || dis2[child]>tot) && dis[child]<tot)
                q.push({child,tot});

        }
        if(!Back[Node])
            Back[Node]=1, q.push({Node,minWeight[Node]+dis[Node]});
    }

    return dis2[node];

}

void clr()
{
    for(int i=1; i<=node; i++){
        v[i].clear();
    }
}

int main()
{
    //freopen("text.txt", "r", stdin);

    int t,kk=0;
    scanf("%d", &t);

    while(t--){
        int pum=0,k=1;
        scanf("%d %d", &node, &edge);

        for(int i=0; i<edge; i++){

            int a1,a2,w;
            scanf("%d %d %d", &a1, &a2, &w);

            v[a1].push_back(hello(a2,w));
            v[a2].push_back(hello(a1,w));

        }

        printf("Case %d: %d\n", ++kk, dijkstra(1));
        clr();
    }

    return 0;
}
//took help from 
// https://github.com/rafi-kamal/ACM-Solutions/blob/master/LightOj/Graph%20Theory/1099%20-%20Not%20the%20Best.cpp
