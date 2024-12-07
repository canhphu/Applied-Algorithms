#include<bits/stdc++.h>

using namespace std;
int n;
pair<int,int> last;
vector<pair<int,int>> vv;
int cnt = 0;
int kt = -1;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i<=n;i++) {
        int u,v;
        cin >> u >> v;
        vv.emplace_back(u,v);
    }
    sort(vv.begin(), vv.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second != b.second) {
            return a.second < b.second; // So sánh điểm kết thúc 
        } return a.first < b.first;
        
    });
    for(const auto& v : vv) {
        if(v.first > kt) {
            cnt++;
            kt = v.second;
        }        
    }
    cout << cnt;
}
