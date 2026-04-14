#include<print>
#include<vector>
#include<list>
#include<map>

using namespace std;

map<int,list<int>> buildGraph(vector<vector<int>> v)
{
	map<int,list<int>> g;

	for(auto &vec : v)
	{
		g[vec[0]].push_back(vec[1]);
		g[vec[1]].push_back(vec[0]);
	}
	return g;
}
