#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
char v[101][102];
bool ck[101][101] = {true}; // true로 초기화가 안되나봐
int cnt[101][101];

int bfs(int n, int m){
    queue< pair<int,int> > q;
    q.push(make_pair(1,1));
    
    while(!q.empty()){
        ck[1][1] = true;
        int x = q.front().first,y = q.front().second;
        q.pop();
        cnt[1][1] = 1;
        

        if(y+1 <= m){
            if(v[x][y+1] == '1' && !ck[x][y+1]){
                cnt[x][y+1] = cnt[x][y] + 1;
                if(x == n && y+1 == m) return cnt[x][y+1];//x+y가 cnt와 같음
                q.push(make_pair(x,y+1));
                ck[x][y+1] = true;
            }
        }
        if(x+1 <= n){
            if(v[x+1][y] == '1'&& !ck[x+1][y]){
                cnt[x+1][y] = cnt[x][y] + 1;
                if(x+1 == n && y == m) return cnt[x+1][y];
                q.push(make_pair(x+1,y));
                ck[x+1][y] = true;
            }
        }
        if(x-1 >= 1){
            if(v[x-1][y] == '1'&& !ck[x-1][y]){
                cnt[x-1][y] = cnt[x][y] + 1;
                q.push(make_pair(x-1,y));
                ck[x-1][y] = true;
            }
        }
        if(y-1 >= 1){
            if(v[x][y-1] == '1'&& !ck[x][y-1]){
                cnt[x][y-1] = cnt[x][y] + 1;
                q.push(make_pair(x,y-1));
                ck[x][y-1] = true;
            }
        }




        
        
    }
    return 100;
    

}
int main(void){
    int n,m;
    cin >> n >> m;
    // vector<char> v[n+1]; stl활용을 좀더 공부해볼 필요가 있겠음 사용이 필요할 때
    for(int i = 1; i <= n; i++){
        cin >> &v[i][1];
    }
    

    cout << bfs(n,m);
}
