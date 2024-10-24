#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int a[MAX],n;
vector<vector<int>> b;

void preprocess() {
    int log_n = log2(n) + 1;
    b.resize(log_n, vector<int>(n, -1));
    for(int j = 0; (1<<j) <= n; j++) {
        for(int i = 0; i<n;i++) {
            b[j][i] = -1; // Khởi tạo toàn bộ giá trị bằng -1 
        }
    }
    for(int i = 0;i<n;i++) {
        b[0][i] = a[i]; // Gán giá trị của mảng a vào mảng b
    }
    for(int j = 0 ; (1<<j) <=n ;j++) {
        for(int i =0;i<i+(1<<j);i++) {
            if(a[b[j-1][i]] <= a[b[j-1][i+(1<<(j-1))]]) { 
                b[j][i] = b[j-1][i];
            }
            else {
                b[j][i] = b[j-1][i+(1<<(j-1))];
            }
        }
    }
}

int rmq(int i, int j) {
    int k = log2(j-i+1);
    int p2k = (1<<k);
    if(a[b[k][i]] <= a[b[k][j-p2k+1]]) {
        return b[k][i];
    }
    else {
        return b[k][j-p2k+1];
    }
}

int main () {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    preprocess();
    int ans=0;
    int m;
    scanf("%d",&m);
    for(int i =0;i<m;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        ans += rmq(x,y);
    }
    cout << ans;
    return 0;
}