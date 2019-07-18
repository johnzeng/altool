#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ldb;
ldb get_area(int x1,int y1,int x2,int y2,int x3,int y3)
{
    ll s1 = (ll)x1 * y2 - (ll)x2 * y1;
    ll s2 = (ll)x2 * y3 - (ll)x3 * y2;
    ll s3 = (ll)x1 * y3 - (ll)x3 * y1;
    return abs(s1 + abs(s2 - s3)) / 2.0;
}

int main(int argc, char *argv[])
{
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3>>y3;
    cout << get_area(x1,y1,x2,y2,x3,y3);
    return 0;
}

struct point {
    int x, y;
    int original_index;

    point(int _x = 0, int _y = 0) : x(_x), y(_y) {
        original_index = -1;
    }

    point& operator+=(const point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    point& operator-=(const point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    point operator+(const point &other) const {
        return point(*this) += other;
    }

    point operator-(const point &other) const {
        return point(*this) -= other;
    }

    bool operator<(const point &other) const {
        return make_pair(y, x) > make_pair(other.y, other.x);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

long long dot(const point &a, const point &b) {
    return (long long) a.x * b.x + (long long) a.y * b.y;
}

long long norm(const point &p) {
    return dot(p, p);
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b) > 0;
}

double dist(const point &a, const point &b) {
    return sqrt(norm(a - b));
}

long long triangle_area(const point &a, const point &b, const point &c) {
    return abs(cross(a, b) + cross(b, c) + cross(c, a));
}

ostream& operator<<(ostream &out, const point &p) {
    return out << '(' << p.x << ", " << p.y << ')';
}


struct segment {
    point p;
    int index1, index2;

    segment(const point &_p, int _index1, int _index2) : p(_p), index1(_index1), index2(_index2) {}

    //排序之后得到一个逆时针排列的方向向量列表
    bool operator<(const segment &other) const {
        // if ((p.y >= 0) ^ (other.p.y >= 0))
        //     return p.y >= 0;

        long long c = cross(p, other.p);

        DEBUG("c is:%lld ", c);
        if (c != 0)
            return c > 0;

        // cerr << d << ' ' << other.p << '\n';
        // assert(p.y == 0 && other.p.y == 0);
        // assert(p.x != 0 && other.p.x != 0);

        // if ((p.x > 0) ^ (other.p.x > 0))
        //     return p.x > 0;

        return norm(p) < norm(other.p);
    }
};

