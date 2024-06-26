#include<bits/stdc++.h>


using namespace std;

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else 
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    int v=0;
    for(int i = 0; i < n; i++){
        cin >> words[i];
        add_string(words[i]);
    } 

    // how to iterate over the trie
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < K; j++) {
            if (t[i].next[j] != -1) {
                cout << i << " -> " << t[i].next[j] << " " << (char)('a' + j) << "\n";
            }
        }
    }

    return 0;
}