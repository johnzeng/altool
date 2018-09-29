#include <vector>
#include <string>
using namespace std;

vector <int> z_function(string s){
	int n = s.size();
	vector <int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
	return z;
}

//s[pos..] ? t
/*由于已经计算过zfunction了，所以针对字符串型的数字，可以有比较：

如果pos的长度小于字符串，肯定小
z数组长度一致，相同
z数组长度不一致，但是截取的长度跟t一致，比较第一个不同的位置即可。
*/
string s;
char cmp(vector <int> &zf, string &t, int pos){
	int len = t.size();
//	assert(pos + len + 1 < zf.size());

    //如果这个pos截出来的长度小于len，肯定小
	if(s.size() - pos < len) return '<';
	
	int x = zf[len + 1 + pos];
    //如果zfunction出来的长度相同，那就是相同的
	if(x == len) return '=';
    //如果同前缀的情况下，截出来的长度相同，看第一个不同的，如果小，就小于
	if(s[pos + x] < t[x]) return '<';
    //否则其他情况都是大于（更长，最后一个长，等等
	return '>';
}

