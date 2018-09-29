#include "bits/stdc++.h"
using namespace std;

bool reachable[21][1000005];
// use an array will be much faster then map
std::vector<int> g[1000005];

void dfs(int source)
{
    reachable[source] = true;
    for(auto x:g[source])
    {
        if(reachable[x] == false)
        {
            dfs(x);
        }
    }
}

int main(int argc, char *argv[])
{
    int n,m;
    int from, to;
    scanf("%d %d", &n, &m);
    memset(reachable, 0 , sizeof(reachable));
    for (int i = 0; i < m; ++i) {
        //scanf is faster than cin!
        scanf("%d %d", &from, &to);
        g[from].push_back(to);
    }
    return 0;
}
