#include<iostream>
using namespace std;
int main(void){
    const int mod = 9901;
    int n;
    cin >> n;
    int d[n+1][3];
    
    d[1][0] = d[1][1] = d[1][2] = 1;
    
    for(int i = 2; i <= n; i++){
        d[i][0]=d[i-1][0]%mod+d[i-1][1]%mod+d[i-1][2]%mod;
        d[i][1]=d[i-1][0]%mod+d[i-1][2]%mod;
        d[i][2]=d[i-1][0]%mod+d[i-1][1]%mod; 
    }
    cout << (d[n][0]+d[n][1]+d[n][2])%mod;
}