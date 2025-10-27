#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        vector<string> grid(10);
        for(int i = 0; i < 10; i++) {
            cin >> grid[i];
        }
        
        int total_score = 0;
        
        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                if(grid[row][col] == 'X') {
                    
                    // How far from each edge?
                    int from_top = row;
                    int from_bottom = 9 - row;
                    int from_left = col;
                    int from_right = 9 - col;
                    
                    // Which edge is CLOSEST?
                    // This determines which ring we're in
                    int min_distance = min({from_top, from_bottom,from_left, from_right});
                    
                    int points = min_distance + 1;
                    
                    total_score += points;
                }
            }
        }
        
        cout << total_score << endl;
    }
    
    return 0;
}
