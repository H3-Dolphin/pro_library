#include <iostream>
using namespace std;
int par[100010];

int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
}

bool same(int x,int y){
    return par[x] == par[y];
}

void unite(int x,int y){
    x = root(x),y = root(y);
    if(x == y) return;
    par[x] = y;
}

int main(void){
    int n,q,p,a,b;
    cin >> n >> q;
    for(int i = 0;i < n;i++) par[i] = i;
    for(int i = 0;i < q;i++){
        cin >> p >> a >> b;
        if(p == 0) unite(a,b);
        else{
            root(a);
            root(b);
            if(same(a,b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
