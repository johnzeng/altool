#include <set>
#include <vector>
using namespace std;
#define N 1035
#define INF64 1e18

vector <pair<int, int> > g[N];
int n;
void dij(int st, long long d[N]){
	set<pair<long long, int> > q;
	for(int i = 0; i < n; ++i) d[i] = INF64;
	d[st] = 0;
	q.insert(make_pair(d[st], st));
	
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		
		for(auto e : g[v]){
			int to = e.first, len = e.second;
			if(d[to] > d[v] + len){
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}
}
