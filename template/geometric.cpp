#include<bits/stdc++.h>
using namespace std;
#define N 1005
typedef struct _point
{
    long x;
    long y;
}point;

struct seg{
    int x1, y1, x2, y2;
    seg(){};
    bool is_up(int x,int y)
    {
        int left = y * (x1 - x2);
        int right = (y1 - y2) * x + (y2*x1 - y1 * x2);
        if(x1 > x2)
        {
            return left >= right;
        }
        else
        {
            return left <= right;
        }
    }
    bool is_down(int x,int y)
    {
        int left = y * (x1 - x2);
        int right = (y1 - y2) * x + (y2*x1 - y1 * x2);
        if(x1 > x2)
        {
            return left <= right;
        }
        else
        {
            return left >= right;
        }
    }

};

struct line{
    long long A, B, C;
    line(){};
    line(seg a){
        A = a.y1 - a.y2;
        B = a.x2 - a.x1;
        C = -A * a.x1 - B * a.y1;
    };
};

long long det(long long a, long long b, long long c, long long d){
    return a * d - b * c;
}


//求两个线是否有交集
bool inter_for_line(seg a, seg b, int& x, int& y){
    line l1(a), l2(b);
    long long dx = det(l1.C, l1.B, l2.C, l2.B);
    long long dy = det(l1.A, l1.C, l2.A, l2.C);
    long long d = det(l1.A, l1.B, l2.A, l2.B);
    if (d == 0)
        return false;
    if (dx % d != 0 || dy % d != 0)
        return false;
    x = -dx / d;
    y = -dy / d;
    return true;
}

bool in_seg(int x, int l, int r){
    if (l > r) swap(l, r);
    return (l <= x && x <= r);
}

//求两个线段是否有交集
bool inter_for_seg(seg a, seg b, int& x, int& y)
{
    if(inter_for_line(a,b,x,y))
    {
        if (!in_seg(x, a.x1, a.x2) || !in_seg(y, a.y1, a.y2))
            return false;
        if (!in_seg(x, b.x1, b.x2) || !in_seg(y, b.y1, b.y2))
            return false;
        return true;
    }
    return false;
}

//求线段内的整数坐标数
int get_int_coordinate_num(seg a){
    int dx = a.x1 - a.x2;
    int dy = a.y1 - a.y2;
    if(dx == 0)
    {
        return abs(dy) + 1;
    }
    else if(dy == 0)
    {
        return abs(dx) + 1;
    }
    return __gcd(abs(dx), abs(dy)) + 1;
}

int main(int argc, char *argv[])
{
    int n = 0;
    int x1,y1,x2,y2;
    vector<seg> a;
    seg tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d %d %d %d", &x1,&y1, &x2,&y2);
        tmp.x1 = x1;
        tmp.x2 = x2;
        tmp.y1 = y1;
        tmp.y2 = y2;
        a.push_back(tmp);
    }
    long long cnt = 0;
    for (int i = 0; i < n; ++i) 
    {
        set<pair<int, int> > pts;
        cnt += get_int_coordinate_num(a[i]);
        for(int j = 0; j < i; j++)
        {
            if(inter_for_seg(a[i], a[j], x1,y1))
            {
                pts.insert(pair<int, int>(x1,y1)); 
            }
        }
        cnt -= pts.size();
    }
    cout << cnt << endl;
    return 0;
}
