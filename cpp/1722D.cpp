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

int main() {
    int t, n, k;
    cin >> t;
    string line;
    while (t--) {
        priority_queue<int, vector<int>, less<int>> turn;
        cin >> n;
        cin >> line;
        long long cnt = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 'L') {
                cnt += i;
                turn.push(n - i - 1 - i);
            } else {
                cnt += n - i - 1;
                turn.push(i - (n - i - 1));
            }
        }
        if (turn.top() > 0) {
            cnt += turn.top();
            turn.pop();
        }
        cout << cnt;
        int i;
        for (i = 1; i < n && turn.top() > 0; i++) {
            cnt += turn.top();
            turn.pop();
            cout << " " << cnt;
        }
        for (; i < n; i++) {
            cout << " " << cnt;
        }
        cout << endl;
        turn = {};
    }
    return 0;
}