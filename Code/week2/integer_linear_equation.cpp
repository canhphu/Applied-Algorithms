#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[10005],x[10005],t[10005];
int f=0,cnt = 0;

void Try(int k) {
    for(int v = 1; v<= m-f-(t[n]-t[k])/a[k];v++) {
        x[k] = v;
        f = f + a[k] * x[k]; //Tong f cua cac phan tu da duoc chon
        if(k==n) {
            if(f==m) {
                cnt += 1;
            }
        } else {
            Try(k+1);
        }
        f = f - a[k]*x[k]; //Bo chon phan tu k
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
    Try(1);
    cout << cnt;
    return 0;
}