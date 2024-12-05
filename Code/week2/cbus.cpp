#include<bits/stdc++.h>
using namespace std;

int n,K;
int c[50][50];
int x[50];
int visited[50];
int load = 0;
int sum =0 ;
int Cmin = 1000000;
int res = 1e9;

bool check( int v){

    if( visited[v] ) return false; //kiem tra xem v da duoc chon chua
    if( v <= n && load == K) return false; // kiem tra xem load da vuot qua K chua
    if( v > n && visited[v - n] == 0 ) return false; // kiem tra xem co xe nao chua duoc chon chua

    return true;
}

void Try( int k){
    for( int v = 1; v <= 2*n ;v++){
        if( check(v)){
            x[k] = v;

            visited[ v ] = true;
            if( v <= n)load ++;
            else load--;
            sum += c[ x[k-1] ][ x[k] ];

            if( k == 2*n){
                res= min( res , sum + c[ x[k] ][0]);
            }
            else{
                if( sum + (2*n -k +1)*Cmin < res )
                    Try(k+1);
            }

            visited[ v ] = false;
            if( v <= n)load --;
            else load++;
            sum -= c[ x[k-1] ][ x[k] ];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> K;
    for( int i =0 ; i<= 2*n ; i++){
        for( int j = 0 ; j<= 2*n; j++){
            cin>>c[i][j];
            if( !c[i][j] ) Cmin =min( Cmin, c[i][j]);
        }
    }
    Try(1);
    cout<< res;
    return 0;
}