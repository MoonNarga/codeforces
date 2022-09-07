#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int N = 100100;

vector<int> edges[N];
vector<long long> values;
vector<bool> visit;

long long *dfs(int no) {
    long long modify = 0;
    visit[no] = true;
    long long maxSub = 0, minSub = 0;
    for (auto &i : edges[no]) {
        if (visit[i]) {
            continue;
        }
        long long *t = dfs(i);
        maxSub = max(maxSub, t[0]);
        minSub = min(minSub, t[1]);
        delete t;
    }
    values[no] += maxSub + minSub;
    if (values[no] > 0) {
        minSub -= values[no];
    } else {
        maxSub -= values[no];
    }
    long long *t = new long long[2];
    t[0] = maxSub, t[1] = minSub;
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    values = vector<long long>(n + 1);
    visit = vector<bool>(n + 1);
    int from, to;
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    for (int i = 1; i < n; i++) {
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    long long *t = dfs(1);
    cout << t[0] - t[1] << endl;
    delete t;
    return 0;
}