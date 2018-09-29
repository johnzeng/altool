//从顶点from指向顶点to的权值为cost的边
struct edge{
    int from,to,cost;
};
#define MAX_V 1000
#define INF 0x3f3f3f3f
edge es[MAX_V];//边

int d[MAX_V];  //最短距离
int V,E;       //V是顶点数,E是边数

//求解从顶点s出发到所有点的最短距离
void shortest_path(int s)
{
    for(int i=0; i<V; i++)  
        d[i] = INF;  //0x3f3f3f3f 
    d[s]=0;
    while(true){
        bool update=false;
        for(int i=0; i<E; i++){
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to] >d[e.from]+e.cost){
                update=true;
                d[e.to] = d[e.from] + e.cost;
            }
        }
        if(!update)
            break;
    }     
}
