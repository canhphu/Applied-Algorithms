#include<bits/stdc++.h>
using namespace std;

int m,n,r,c;
typedef pair<int, int> ii;
const int maxN = 999 + 100;
const int oo = 1e9+7;
int a[maxN][maxN];
int d[maxN][maxN];
// a[MaxN][MaxN] đánh dấu một ô được xét hay chưa
// d[MaxN][MaxN] lưu độ dài đường đi từ ô xuất phát
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

queue <ii> qe; //luư các ô lân cận sẽ được xét

int solve() {
    qe.push(ii(r,c)); d[r][c]=0; a[r][c] = 1;
    while(!qe.empty()) {
        ii u = qe.front(); qe.pop(); // lấy ô đầu tiên ra khỏi hàng đợi
        for(int i = 0; i<4;i++) {
            int x = dx[i] + u.first; // tọa độ x của ô lân cận
            int y = dy[i] + u.second; // tọa độ y của ô lân cận
            if(x<1 || x>m || y<1 || y > n) return d[u.first][u.second] + 1; // nếu ô lân cận nằm ngoài ma trận thì trả về độ dài đường đi
            if(a[x][y] != 1) {
                d[x][y] = d[u.first][u.second] + 1; // cập nhật độ dài đường đi
                qe.push(ii(x,y)); // thêm ô lân cận vào hàng đợi
                a[x][y] = 1; // đánh dấu ô lân cận đã được xét
            }
        }
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> m >> n >> r >> c;
    for(int i =1;i<=m;i++) {
        for(int j = 1; j<=n;j++) {
            cin >> a[i][j]; 
        }
    }
    int ans = solve();
    cout << ans;
    return 0;
}
