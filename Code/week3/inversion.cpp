#include<bits/stdc++.h>

using namespace std;
int n;
int a[1000005] = {};
int b[1000005] = {};
int res = 0;
const int module = 1e9+7;

void connect(int l, int mi, int r) {
    int i = l;
    int j = mi + 1;
    int k = l;
    while(i<=mi && j <= r) {
        if(a[i] > a[j]) {
            b[k] = a[j];
            res = (res + mi - i + 1) % module;
            j++;
        } else {
            b[k] = a[i];
            i++;
        }
        k++;
    }

    while(i<=mi) {
        b[k] = a[i];
        i++;
        k++;
    }

    while(j<=r) {
        b[k] = a[j];
        j++;
        k++;
    }

    for(int i = 1;i<=r;i++) {
        a[i] = b[i];
    }
}

void merge_sort(int l, int r) {
    if(l==r) return;
    int mi = (l+r) >> 1;
    merge_sort(l,mi); //sort trai
    merge_sort(mi+1,r); //sort phai
    connect(l,mi,r); //noi 2 doan

    return;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) {
        cin >> a[i];
    }
    merge_sort(1,n);
    cout << res;
    return 0;
}