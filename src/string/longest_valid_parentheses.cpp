#include<print>

using namespace std;

bool isValid(string s)
{
	int cnt = 0;
	for(auto x: s)
	{
	    if(x == '(')
	    {
		cnt++;
	    }
	    else
	    {
		if(cnt>0)
		{
			cnt--;
		}
		else
		{
			return false;
		}
	    }
	}
	println("Substr: {} is valid: {}",s,cnt==0);
	return cnt == 0;
}

int longestValidParentheses(string s) {
int n = s.length();
int max_val = 0;
for(int i = 0 ; i < n; i++)
{
    for(int j = i; j < n; j++)
    {
	if(isValid(s.substr(i,j-i+1)))
	{
	    max_val = max(max_val,j-i+1);
	}
    }
}
return max_val;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		println("Usage: ./bin <string>");
	}
	string s = argv[1];
	print("Size of longest valid parentheses:{}\n",longestValidParentheses(s));

	return 0;
}
