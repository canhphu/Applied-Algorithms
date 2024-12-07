#include<bits/stdc++.h>

using namespace std;
int t,n,c;
int a[10000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i<=t; i++) {
        cin >> n >> c;
        for(int j = 1;j<=n;j++) {
            cin >> a[j];
        }
        sort(a+1,a+n+1);
        int l = 0, r = a[n]-a[1], res = 0;
        while(l<=r) {
            int mid = (l+r)/2;
            int cnt = 1, last = a[1];
            for(int i = 2;i<=n;i++) {
                if(a[i] - last >= mid) {
                    cnt++;
                    last = a[i];
                }
            }
            if(cnt >= c) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << res << endl;
    }
}