#include <set>
#include <vector>
using namespace std;
#define MAXN 1035
#define INF64 1e18

vector <pair<int, int> > g[MAXN];
int n;
unsigned long long d[MAXN];
void dij(int st){
	set<pair<long long, int> > q;
    memset(d, 0xff, sizeof(d));
	d[st] = 0;
	q.insert(make_pair(d[st], st));
	
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		
		for(auto e : g[v]){
            //get to idx and len
			int to = e.first, len = e.second;

			if(d[to] > d[v] + len){
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}
}
