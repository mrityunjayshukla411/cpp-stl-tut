#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> get_probable_words(vector<string> words, string green, string yellow, string red)
{
    vector<string> res;

    for (auto it = words.begin(); it != words.end(); ++it)
    {
        string &word = *it;
        bool invalid = false;

        // Red: letter must NOT exist
        for (char x : red)
        {
            if (x == '-') continue;

            if (find(word.begin(), word.end(), x) != word.end())
            {
                invalid = true;
                break;
            }
        }

        if (invalid) continue;

        // Green: correct position
        for (int i = 0; i < green.size(); i++)
        {
            if (green[i] != '-' && word[i] != green[i])
            {
                invalid = true;
                break;
            }
        }

        if (invalid) continue;

        // Yellow: exists but NOT in same position
        for (int i = 0; i < yellow.size(); i++)
        {
            if (yellow[i] == '-') continue;

            if (word[i] == yellow[i] || 
                find(word.begin(), word.end(), yellow[i]) == word.end())
            {
                invalid = true;
                break;
            }
        }

        if (!invalid)
        {
            res.push_back(word);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
