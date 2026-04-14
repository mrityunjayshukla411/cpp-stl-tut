#include<print>
#include<vector>
#include<string>

using namespace std;

vector<int> vis(20,0);
vector<vector<string>> dp[20];

void getPalindromeMatrix(string s,vector<vector<int>> &pa)
{
    int n = s.length();
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if ((s[i] == s[j]) && (j-i <=2 || pa[i+1][j-1]))
            {
                pa[i][j] = 1;
            }
        }
        
    }
    
}

vector<vector<string>> solve(int idx, string s, vector<vector<int>> &pa)
{
    int n = s.length();
    if (idx == n)
    {
        return {{}};
    }
    if (vis[idx])
    {
        return dp[idx];
    }
    vis[idx] = 1;

    vector<vector<string>> res;
    for (int i = idx; i < n; i++)
    {
        if (pa[idx][i])
        {
            string curr = s.substr(idx, i-idx+1);
            print("[IDX={},i={}]\tCurrent substr: {}\t Calling for substr: {}\n",idx,i,curr,s.substr(i+1,n-i));
            vector<vector<string>> temp = solve(i+1,s,pa);

            for (auto &&vec : temp)
            {
                vector<string> newVec;
                newVec.push_back(curr);
                newVec.insert(newVec.end(),vec.begin(),vec.end());
                res.push_back(newVec);
            }
            
        }
        
    }
    return dp[idx] = res;
}

vector<vector<string>> palindrome_substring_top_down(string s, vector<vector<int>> &pa)
{
    return solve(0,s,pa);
}

vector<vector<string>> palindrome_substring_bottom_up(string s, vector<vector<int>> &pa)
{
    int n = s.length();
    vector<vector<string>> dp[n+1];
    dp[n] = {{}};

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (pa[i][j])
            {
                string curr = s.substr(i,j-i+1);

                for (auto &&vec : dp[j+1])
                {
                    vector<string> temp;
                    temp.push_back(curr);
                    temp.insert(temp.end(),vec.begin(),vec.end());
                    dp[i].push_back(temp);
                }
                
            }
            
        }
        
    }
    return dp[0];
    
}

int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        println("Usage:- ./palindrome_substring <word>");
    }
    string s = argv[1];

    int n = s.length();
    vector<vector<int>> pa(n,vector<int>(n,0));
    getPalindromeMatrix(s,pa);
    vector<vector<string>> res = palindrome_substring_top_down(s,pa);
    vector<vector<string>> pes = palindrome_substring_bottom_up(s,pa);

    println("Top down");
    for (auto &&vec : res)
    {
        print("{}\n",vec);
    }
    
    println("Bottom up");
    for (auto &&vec :pes)
    {
        print("{}\n",vec);
    }

    return 0;
}
