#include<iostream>
#include<queue>
using namespace std;
int scr[1000000] = {1};
int cli[1000000];
int cnt[1000000] = {1}; //초기값만 0으로 초기화되는 듯
int idx = 1;
int bfs(int n){
    queue<pair<char,int> > q; //두번째인자는 인댁스
    q.push(make_pair('c',1)); 
    cli[idx] = 1;
    scr[idx] = 1;
    cnt[idx] = 1;
    while(!q.empty()){
        char wh = q.front().first; int pi = q.front().second; // past index
        q.pop();
        if(wh == 'c'){
            //c추가할때
            cnt[++idx] = cnt[pi] + 1;
            cli[idx] =  scr[pi];
            scr[idx] = scr[pi]; // 이렇게 옮겨주지 않으면 0인 값이 유지됨
            q.push(make_pair('c',idx));
            //p추가
            cnt[++idx] = cnt[pi] + 1;
            scr[idx] = cli[pi] + scr[pi];
            cli[idx] = cli[pi];
            // cout << scr[idx] << endl;
            if(scr[idx] == n) return cnt[idx];
            q.push(make_pair('p',idx));
            
            if(scr[pi] != 0){
                cnt[++idx] = cnt[pi] + 1;
                scr[idx] = --scr[pi];
                cli[idx] = cli[pi];
            if(scr[idx] == n) return cnt[idx];
                q.push(make_pair('d',idx));
            //d추가
            }
        }
        else if(wh == 'p'){
            //c추가할때
            cnt[++idx] = cnt[pi] + 1;
            cli[idx] =  scr[pi];
            scr[idx] = scr[pi];
            q.push(make_pair('c',idx));
            
            if(scr[pi] != 0){
                cnt[++idx] = cnt[pi] + 1;
                scr[idx] = --scr[pi];
                cli[idx] = cli[pi];
            if(scr[idx] == n) return cnt[idx];
                q.push(make_pair('d',idx));
            //d추가
            }
        }
        else if(wh == 'd'){
            if(cli[pi] != 0){
                cnt[++idx] = cnt[pi] + 1;
                scr[idx] = cli[pi] + scr[pi];
                cli[idx] = cli[pi];
            if(scr[idx] == n) return cnt[idx];
                q.push(make_pair('p',idx));
            } //p추가

            cnt[++idx] = cnt[pi] + 1;
            cli[idx] = scr[pi];
            scr[idx] = scr[pi]; // 이렇게 옮겨주지 않으면 0인 값이 유지됨
            q.push(make_pair('c',idx));//c추가

            if(scr[pi] != 0){
                cnt[++idx] = cnt[pi] + 1;
                scr[idx] = --scr[pi];
                cli[idx] = cli[pi];
            if(scr[idx] == n) return cnt[idx];             
                q.push(make_pair('d',idx));
            //d추가
            }
            
        }

        

    }
    return 0;

}
int main(void){
    int n;
    cin >> n;
    cout << bfs(n);
}

#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int d[1001][1001];
int main() {
    int n;
    cin >> n;
    memset(d,-1,sizeof(d));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    d[1][0] = 0;
    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s,s));
        }
        if (s+c <= n && d[s+c][c] == -1) {
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c, c));
        }
        if (s-1 >= 0 && d[s-1][c] == -1) {
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
    int ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}