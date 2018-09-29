#include <set>
#include <vector>
using namespace std;

const int N = 300 * 1000 + 9;
const int LOGN = 19;
const int M = 21;
const long long INF64 = 1e18;

int n, m, q;
vector <pair<int, int> > g[N];
//p[i][j] the root tin in range [j, j+2^i)
int p[LOGN][N];
//tin[i]:the in number of node i
//tout[i]:the out number of node i
//T:current index
int tin[N], tout[N], T;
//u[i] node i is visited or not
bool u[N];

void dfs(int v, int pr){
	tin[v] = T++;
	p[0][v] = pr;
	u[v] = true;
    // actually you don't need to search to LOGN, you can just search to log(i)
    //but it might come out that it's costing almost same time to calculate log(i) and to loop throug LOGN
	for(int i = 1; i < LOGN; ++i)
		p[i][v] = p[i - 1][ p[i - 1][v] ];
		
	for(auto e : g[v]){
		int to = e.first;
		if(!u[to]){
			dfs(to, v);
		}
	}	
		
	tout[v] = T;
}

bool isAncestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getLCA(int a, int b){
	if(isAncestor(a, b)) return a;
	if(isAncestor(b, a)) return b;
	
	for(int i = LOGN - 1; i >= 0; --i)
		if(!isAncestor(p[i][a], b))
			a = p[i][a];
	
	return p[0][a];
}
