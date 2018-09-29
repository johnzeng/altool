#include <string>
using namespace std;

#define N 1000
int next_step[N];
void GetNext(string p)
{
	int pLen = p.size();
	next_step[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k]) 
		{
			++k;
			++j;
			next_step[j] = k;
		}
		else 
		{
			k = next_step[k];
		}
	}
}

int KmpSearch(string s, string p)
{
	int i = 0;
	int j = 0;
	int sLen = s.size();
	int pLen = p.size();
	while (i < sLen && j < pLen)
	{
		//如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next_step[j]    
			//next_step[j]即为j所对应的next_step值      
			j = next_step[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main(int argc, char *argv[])
{
    return 0;
}
