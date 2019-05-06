#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(void){
    int h,w;
    cin >> h >> w;

    vector<vector<int>> dist(h,vector<int>(w,-1));
    queue<pair<int,int>> q;
    for(int i = 0;i < h;i++){
        string s;
        cin >> s;
        for(int j = 0;j < w;j++){
            if(s[j] == '#'){
                dist[i][j] = 0;
                q.push(pair<int,int>(i,j));
            }
        }
    }
    int cnt = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for(int k = 0;k < 4;k++){
            int x = p.first + dx[k],y = p.second + dy[k];
            if(x < 0 || x >= h || y < 0 || y >= w) continue;
            if(dist[x][y] == -1){
                dist[x][y] = dist[p.first][p.second] + 1;
                cnt = max(cnt,dist[x][y]);
                q.push(pair<int,int>(x,y));
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
