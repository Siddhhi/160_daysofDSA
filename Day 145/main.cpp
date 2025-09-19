#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>>& edges) {
    vector<vector<int>> res(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        res[u].push_back(v);
        res[v].push_back(u);
    }
    return res;
}


in(), res.end());
    return res;

}

