#include <bits/stdc++.h>

using namespace std;

vector<string> cy;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string cypher;
    while (getline(cin, cypher)) {
        if (cypher == "END") break;
        cy.push_back(cypher);
    }
    for (int i = 0; i < cy.size(); i++) {
        reverse(cy[i].begin(), cy[i].end());
        cout << cy[i] << '\n';
    }
    return 0;
}