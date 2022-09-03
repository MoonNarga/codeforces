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

unordered_map<string, int> wordCnt;

string words[3][1010];

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        wordCnt.clear();
        cin >> n;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> words[i][j];
                ++wordCnt[words[i][j]];
            }
        }
        for (int i = 0; i < 3; ++i) {
            int score = 0;
            for (int j = 0; j < n; ++j) {
                switch (wordCnt[words[i][j]]) {
                    case 1: {
                        score += 3;
                        break;
                    }
                    case 2: {
                        score += 1;
                        break;
                    }
                }
            }
            cout << score;
            if (i < 2) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}