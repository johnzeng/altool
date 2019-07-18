#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define MAXN 200005  //2e5

#define TESTINGx

#ifdef TESTING
#define DEBUG(S, args...) {printf(S, args);printf("\n");}
#else
#define DEBUG(S, args...) 
#endif

int pri(char x)
{
    switch(x)
    {
        case '!':
            return 0;
        case '&':
            return 1;
        case '|':
            return 2;
        case '(':
            return 3;
        case ')':
            return 4;
        case '#':
        default:
            return 5;
    }
}

class Mark{
    public:
    bool value;
    int count;
    Mark(){
        value = true;
        count = 0;
    }
    Mark(bool m)
    {
        if(m)
        {
            this->value = true;
            this->count = 0;
        }
        else
        {
            this->value = false;
            this->count = 1;
        }
    }
};
Mark operator !(const Mark &m){
    Mark ret;
    ret.value = !m.value;
    if(ret.value)ret.count = 0;
    else ret.count = 1;
    DEBUG("cal !%d:%d, %d", m.value, ret.value, ret.count);
    return ret;
}
Mark operator |(const Mark &n, const Mark& m){
    Mark ret;
    ret.value = n.value || m.value;
    if(ret.value)ret.count = 0;
    else ret.count = min(2,min(n.count, m.count));
    DEBUG("cal %d | %d:%d, %d", n.value, m.value, ret.value, ret.count);
    return ret;
}
Mark operator &(const Mark& n,const Mark& m){
    Mark ret;
    ret.value = n.value && m.value;
    if(ret.value)ret.count = 0;
    else ret.count = min(2, n.count + m.count);
    DEBUG("cal %d & %d:%d, %d", m.value, n.value, ret.value, ret.count);
    return ret;
}

void pushMark(stack<char> &op, stack<Mark> &mark, Mark m)
{
    while(!op.empty() && op.top() == '!')
    {
        op.pop();
        m = !m;
        DEBUG("after ! op, ret %d %d", m.value, m.count);
    }
    DEBUG("push mark %d %d", m.value, m.count);
    mark.push(m);
}

void pushOp(stack<char> &op, stack<Mark> &mark, char o)
{
    if('!' == o || '(' == o)
    {
        op.push(o);
        return;
    }
    while(!op.empty() && pri(op.top()) < pri(o))
    {
        char curOp = op.top();
        op.pop();
        Mark right = mark.top();
        mark.pop();
        switch(curOp)
        {
            case '!':
                pushMark(op, mark, !right);
                break;
            case '(':
                DEBUG("fix （， push %d %d", right.value, min(right.count, 1));
                right.count = min(right.count, 1);
                pushMark(op, mark, right);
                return;
            default:
                Mark left = mark.top();
                mark.pop();
                if(curOp == '&')
                {
                    pushMark(op, mark, left& right);
                }
                else
                {
                    pushMark(op, mark, left| right);
                }
        }
    }
    if(o != ')')
    {
        op.push(o);
    }
}

Mark cal(string s)
{
    stack<char> op;
    stack<Mark> mark;
    for(int j = 0; j < s.size(); j++)
    {
        if('T' == s[j] || 'F' == s[j])
        {
            pushMark(op, mark, 'T' == s[j]);
        }
        else
        {
            DEBUG("push op %c", s[j]);
            pushOp(op, mark, s[j]);
        }
    }
    return mark.top();
}

int main()
{
    int q = 0;
    cin >> q;
    for(int i = 0 ;i < q; i++)
    {
        string s;
        cin >> s;
        cout << cal(s+"#").count << endl;
    }
    return 0;
}

