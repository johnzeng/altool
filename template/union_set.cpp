struct unionNode
{
    int childNum;
    int father;
};

unionNode nodes[MAXN];

void init(int n)
{
    for(int i = 0 ; i <= n ; ++i)
    {
        nodes[i].childNum = 1;
        nodes[i].father = i;
    }
}

int getRoot(int x)
{
    if(nodes[x].father != x)
    {
        //very important to update its father
        return nodes[x].father = getRoot(nodes[x].father);
    }
    return x;
}
void unionSet(int x,int y)
{
    int yRoot = getRoot(y);
    int xRoot = getRoot(x);
    if(xRoot == yRoot)
    {
        return;
    }
    else
    {
        nodes[xRoot].childNum += nodes[yRoot].childNum ;
        nodes[y].childNum = 0;
        nodes[y].father = xRoot;
        nodes[yRoot].father = xRoot;
        nodes[yRoot].childNum= 0;
    }
}

