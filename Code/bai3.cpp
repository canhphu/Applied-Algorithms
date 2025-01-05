#include<bits/stdc++.h>

using namespace std;

int n,L;
int a[1025];
int dp[1025];
stack<int> st;

int main() {
    cin >> n >> L;
    for(int i = 0;i<n;i++) {
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 0;i<n;i++) {
        if(dp[i]!=-1) {
            if(i%2==0) {
                dp[i] = dp[i] + dp[(i-2)/2];
            } else dp[i] = dp[i] + dp[(i-1)/2];
        }
    }
    for(int i = 0;i<n;i++) {
        if(dp[i] <= L && dp[i] != -1) {
            if(dp[2*i+1] == -1 && dp[2*i+2] == -1 || dp[2*i+1] == 0 && dp[2*i+2] == 0) {
                cout << dp[i] << " ";
                int vitri = i;
                while(vitri >= 0) {
                    st.push(vitri);
                    if(vitri % 2 == 0) {
                        vitri = (vitri-2)/2;
                    } else vitri = (vitri-1)/2;
                }
                while(!st.empty()) {
                    cout << st.top() << " ";
                    st.pop();
                }
                cout << endl;
            }
        }
    }
}
