#include <iostream>
using namespace std;
int h,w;
char c[510][510];
bool reach[510][510];

void dfs(int x,int y){
    if(x < 0 || x >= h || y < 0 || y >= w) return;
    if(reach[x][y]) return;
    if(c[x][y] == '#') return;
    reach[x][y] = true;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main(void){
    cin >> h >> w;
    int sx,sy,gx,gy;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> c[i][j];
            if(c[i][j] == 's'){
                sx = i,sy = j;
            }else if(c[i][j] == 'g'){
                gx = i,gy = j;
            }
        }
    }
    dfs(sx,sy);
    if(reach[gx][gy]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
