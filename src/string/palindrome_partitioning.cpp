#include<print>
#include<vector>
#include<string>


using namespace std;

    vector<vector<int>> isPalindrome(string s)
    {
        int n = s.length();
        vector<vector<int>> pa(n,vector<int>(n,0));
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = i ; j < n ; j++)
            {
                if(s[i] == s[j] && (j-i <=2 || pa[i+1][j-1]))
                {
                    pa[i][j] = 1;
                }
            }
        }

        return pa;
    }

    int minCut(string s) {
        int n = s.length();
        vector<vector<string>> dp[n+1];
        vector<vector<int>> pa = isPalindrome(s);
        dp[n] = {{}};
        for(int i = n -1; i >= 0 ;i--)
        {
            for(int j = i;j < n; j++)
            {
                if(pa[i][j])
                {
                    string curr = s.substr(i,j-i+1);
                    for(auto &vec : dp[j+1])
                    {
                        vector<string> temp;
                        temp.push_back(curr);
                        temp.insert(temp.end(),vec.begin(),vec.end());
                        dp[i].push_back(temp);
                    }
                }
            }
        }

        int min_val = n+1;
        for(auto &vec: dp[0])
        {
            int sz = vec.size();
            min_val = min(min_val,sz);
	    println("Partition: {}\tsize: {}\tmin_val: {}",vec,sz,min_val);
        }
        return min_val > 0 ? min_val -1 : 0;
    }

int main(int argc , char *argv[])
{
	if(argc != 2)
	{
		println("Usage: ./bin string");
	}
	string s = argv[1];
	println("minCut: {}",minCut(s));
	return 0;
}
