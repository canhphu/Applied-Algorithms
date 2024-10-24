#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
int a[MAX],n;
int b[30][MAX];

void preprocess() {
    for(int j = 0; (1<<j) <= n; j++) {
        for(int i = 0; i<n;i++) {
            b[j][i] = -1; // Khởi tạo toàn bộ giá trị bằng -1 
        }
    }
    for(int i = 0;i<n;i++) {
        b[0][i] = i; // Gán giá trị cho hàng 0
    }
    for(int j = 1 ; (1<<j) <=n ;j++) {
        for(int i =0;i+(1<<j)-1<n;i++) {
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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
        ans += a[rmq(x,y)];
    }
    cout << ans;
    return 0;
}