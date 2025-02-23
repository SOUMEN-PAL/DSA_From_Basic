#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


/*
You are given a table of n rows and m columns. Initially, the cell at the i-th row and the j-th column has color ai,j

.

Let's say that two cells are strangers if they don't share a side. Strangers are allowed to touch with corners.

Let's say that the set of cells is a set of strangers if all pairs of cells in the set are strangers. Sets with no more than one cell are sets of strangers by definition.

In one step, you can choose any set of strangers such that all cells in it have the same color and paint all of them in some other color. You can choose the resulting color.

What is the minimum number of steps you need to make the whole table the same color?
Input

The first line contains a single integer t
(1≤t≤104) — the number of test cases. Next, t

cases follow.

The first line of each test case contains two integers n
and m (1≤n≤m≤700

) — the number of rows and columns in the table.

The next n
lines contain the colors of cells in the corresponding row ai,1,…,ai,m (1≤ai,j≤nm

).

It's guaranteed that the total sum of nm
doesn't exceed 5⋅105

over all test cases.
Output

For each test case, print one integer — the minimum number of steps to paint all cells of the table the same color.*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n , m;
        cin>>n>>m;

        vector<vector<int>> mat(n ,vector<int>(m));
        vector<int> mp((m*n) + 1 , 0);

        int x = 0 , y = 0;
        int maxColor = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                cin>>mat[i][j];

                mp[mat[i][j]]++;

                if(mp[mat[i][j]] > maxColor){
                    maxColor = mp[mat[i][j]];
                    x = i;
                    y = j;
                }

            }
        }



        queue<pair<int , int>> q;
        q.push({x , y});

        int dirX[] = {0 , 1 , 0 , -1};
        int dirY[] = {1 , 0 , -1 , 0};

        int res = 0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for(int i = 0 ; i<4 ; i++){
                int nx = x + dirX[i];
                int ny = y + dirY[i];

                if(nx >= 0 && nx < n && ny >=0  && ny <m && mat[nx][ny] != mat[x][y]){
                    q.push({nx , ny});
                    mat[nx][ny] = mat[x][y];
                    res++;
                }
            }

        }
        
        cout<<res<<endl;


    }

    
    return 0;
}