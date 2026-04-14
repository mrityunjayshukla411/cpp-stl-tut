#include <print>
#include <string>
#include <vector>

using namespace std;

void print_zig_zag(string s , int numRows)
{
    int n = s.length();
    vector<vector<char>> v(numRows, vector<char>(n, '-'));

    int i = 0, col = 0, row = 0;

    while(i < n)
    {
        // Down
        while(row < numRows && i < n)
        {
            v[row][col] = s[i++];
            row++;
        }

        row -= 2;
        col++;

        // Up diagonal
        while(row > 0 && i < n)
        {
            v[row][col] = s[i++];
            row--;
            col++;
        }
    }

    // Proper printing
    for (auto &r : v) {
        for (char c : r) {
            print("{} ", c);
        }
        println("");
    }
}

int main()
{
    print_zig_zag("PANDUROCKS", 6);
    return 0;
}