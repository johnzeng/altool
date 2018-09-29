#define MOD 998244353
int tC[1005][1005]; //tC 表示 table of C

inline int C(int n, int k)
{
    DEBUG("n:%d,k:%d", n,k);
    if(n<0||k<0)return 1;
    if(k > n) return 0;
    return tC[n][k];
}

void calcC(int n)
{
    for(int i = 0; i < n; i++)
    {
        tC[i][0] = 1;
        for(int j = 1; j < i; j++)
        {
            tC[i][j] = (C(i - 1, j - 1) + C(i - 1, j)) % MOD;
            DEBUG("C[%d][%d]:%d", i,j,tC[i][j]);
        }
        tC[i][i] = 1;
    }
}

