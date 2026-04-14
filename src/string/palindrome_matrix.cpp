#include<print>
#include<string>
#include<vector>

using namespace std;

vector<vector<int>> computePalindromeMatrix(string s)
{
	int n = s.length();
	vector<vector<int>> p(n,vector<int>(n,0));
	for(int i = n-1 ; i >= 0 ; i--)
	{
		for(int j = i ; j < n ; j++)
		{
			if(s[i] == s[j] && (j-i <= 2 || p[i+1][j-1]))
			{
				p[i][j] = 1;
			}
		}
	}
	return p;

}

int main(int argc, char*argv[])
{
	if(argc !=2) return 1;
	string s = argv[1];
	vector<vector<int>> p = computePalindromeMatrix(s);
	size_t n = s.length();

	for(size_t i = 0 ; i < n ; i++)
	{
		print("{}",i);
	}
	print("\n{:_^20}\n","");
	for(size_t i = 0 ; i < n ; i++)
	{
		print("{}",s[i]);
	}
	print("\n{:_^20}\n","");
	
	for(size_t  i = 0 ; i < n ; i++)
	{

		for(size_t  j = 0 ; j < n ; j++)
		{
			print("i={}\tj={}\tpalindrome={}; ",i,j,p[i][j]);
		}
		println();
	}

	return 0;
}

