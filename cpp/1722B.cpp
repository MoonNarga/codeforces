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
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool flag = true;
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i] || s1[i] == 'G' && s2[i] == 'B' ||
                s1[i] == 'B' && s2[i] == 'G') {
                continue;
            }
            flag = false;
            break;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}