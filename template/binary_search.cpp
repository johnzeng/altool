#define n 200005
typedef long long int ll;
ll sum[n];

//assume that sum is sorted from little to large
//find first number not less then;
int find_first_less_to_k(int i, int k)
{
    int end = n;
    //find bottom
    int l = i - 1, r = n;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        ll curSum = sum[mid];
        if(curSum > k)
        {
            r = mid - 1;
        }
        else if(curSum == k)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return (l + r) /2;
}

