#include<bits/stdc++.h>
using namespace std;

vector<string> doesCircleExist(vector<string> commands) {
    vector<string> res;
    for (const string& cmd : commands) {
        int x = 0, y = 0; 
        int dir = 0; // 0: up, 1: right, 2: down, 3: left
        
        for (char c : cmd) {
            if (c == 'G') {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else x--;
            }
            else if (c == 'L') {
                dir = (dir + 3) % 4; // left mu raha ha
            }
            else if (c == 'R') {
                dir = (dir + 1) % 4; // right mur raha ha
            }
        }
        
        
        if ((x == 0 && y == 0) || dir != 0) {
            res.push_back("YES");
        } else {
            res.push_back("NO");
        }
    }
    return res;
}

int main(){
    
    return 0;
}