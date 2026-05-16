#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;
    if (!(cin >> t >> p)) return 0;

    string s = p + "#" + t;
    int n = s.length();
    int p_len = p.length();

    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = p_len + 1; i < n; i++) {
        if (z[i] == p_len) {
            cout << i - (p_len + 1) << "\n";
        }
    }

    return 0;
}