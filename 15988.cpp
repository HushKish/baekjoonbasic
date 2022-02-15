#include<iostream>
#include<vector>
using namespace std;
long long memo[1000001];
long long mod = 1000000009ll;
// int cnt = 0;
int go(int n){
    if( memo[n] > 0) return memo[n];
    if( n == 0 || n == 1) return 1;
    if( n == 2 ) return 2;
    
    memo[n] = go(n-3) % mod + go(n-2) % mod + go(n-1) % mod; 
    /* go들은 모두 초기값들로 이 과정을 거쳐 memo에 저장된 값들 고로 모두 mod보다 작다고 할 수 있음 
    합이 int를 넘을 순 있으니 long long을 사용하는데 여기서 굳이 %mod를 다해줄 필욘없을듯*/
    memo[n] %= mod;
    
    // cout  << ++cnt << "\n";
    return memo[n];
}

int main(void){
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cout << go(v[i]) << "\n";
}