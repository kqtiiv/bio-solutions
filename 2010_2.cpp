#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef long long ll;

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void roll(unordered_map<string, int>& dice, char heading) {
    unordered_map<string, int> temp = dice;
    if (heading=='N') {
        dice["top"] = temp["down"];
        dice["down"] = temp["bottom"];
        dice["bottom"] = temp["up"];
        dice["up"] = temp["top"];
    } else if (heading=='E') {
        dice["top"] = temp["left"];
        dice["left"] = temp["bottom"];
        dice["bottom"] = temp["right"];
        dice["right"] = temp["top"];
    } else if (heading == 'S') {
        dice["top"] = temp["up"];
        dice["down"] = temp["top"];
        dice["bottom"] = temp["down"];
        dice["up"] = temp["bottom"];
    } else {
        dice["top"] = temp["right"];
        dice["right"] = temp["bottom"];
        dice["bottom"] = temp["left"];
        dice["left"] = temp["top"];
    }
}
void movePos(char heading, int& x, int& y) {
    if (heading=='N') {
        if (y>0)y--;
        else y=10;
    } else if (heading=='E') {
        if (x<10)x++;
        else x=0;
    } else if (heading=='S') {
        if (y<10)y++;
        else y=0;
    } else {
        if (x>0)x--;
        else x=10;
    }
}

void solve()
{
    vector<vector<int>> grid(11, vector<int>(11, 1));
    for (int i=4; i<=6; i++) {
        for (int j=4; j<=6; j++) {
            cin >> grid[i][j];
        }
    }
    unordered_map<string, int> dice = {
        {"top", 1},
        {"bottom", 6},
        {"left", 3},
        {"right", 4},
        {"up", 2},
        {"down", 5}
    };
    int n;
    cin >> n;
    int x = 5, y=5;
    char heading = 'N';
    unordered_map<char, int> directions = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    vector<char> d = {'N', 'E', 'S', 'W'};

    while (n!=0) {
        if (n>=1&&n<=100) {
            for (int i=0; i<n; i++) {
                int new_val = ((grid[y][x]+dice["top"]-1)%6)+1;
                grid[y][x] = new_val;
                if (new_val==2) {
                    heading = d[((directions[heading]+1)%4)];
                } else if(new_val==3||new_val==4) {
                    heading = d[((directions[heading]+2)%4)];
                } else if (new_val==5) {
                    heading = d[((directions[heading]+3)%4)];
                }
                roll(dice, heading);
                movePos(heading, x, y);
            }
        }
        for (int i=-1; i<2; i++) {
            string row = "";
            for (int j=-1; j<2; j++) {
                if (x+j<0||x+j>=11||y+i<0||y+i>=11) {
                    row+='X';
                } else {
                    row+=to_string(grid[y+i][x+j]);
                }
            }
            cout << row << endl;
        }
        cin >> n;
    }
}


int main()
{
    fastIO();
    solve();
    return 0;
}
