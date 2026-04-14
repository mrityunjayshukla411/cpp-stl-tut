#include<print>
#include<string>
#include<vector>

using namespace std;

bool isMatch(string s, string p) {

    size_t p_size = p.length();
    size_t pos = 0;
    for (size_t i = 0; i < p_size; i++)
    {
        if (p[i] != s[pos] && p[i] != '.' && p[i] != '*')
        {
            return false;
        }
        if(p[i] == '*' && i>=1)
        {
            if(p[i-1] == '.') return true;
            while (s[pos] == p[i-1])
            {
                pos++;
            }
            continue;
            
        }
        pos++;
    }

    
    
    return pos != s.length() ? false : true;    
}

int main()
{
    string pattern = "ab..ce*d";
    string s = "abcfceeed";
    print("isMatch={}",isMatch(s,pattern));
    return 0;
}
