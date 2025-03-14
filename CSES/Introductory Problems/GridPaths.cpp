#include <iostream>
using namespace std;
 
const int DIR_LEN = 4;
int dr[DIR_LEN] = {-1, 0, 1, 0};
int dc[DIR_LEN] = {0, 1, 0, -1};

const int PATH_LEN = 48;  // Length of all possible paths
int p[PATH_LEN];
const int GRID_SIZE = 9;

// Added border to all four sides so a 7x7 becomes a 9x9
bool onPath[GRID_SIZE][GRID_SIZE];
 
int tryPath(int pathIdx, int curR, int curC) {
    // Optimization 1
    // If we can only move left or right we'll divide the grid into two
    // different sections and one of them will never be visited
	if ((onPath[curR][curC - 1] && onPath[curR][curC + 1]) &&
	    (!onPath[curR - 1][curC] && !onPath[curR + 1][curC])) {
		return 0;
    }

    // The same happens if we can only move up or down
	if ((onPath[curR - 1][curC] && onPath[curR + 1][curC]) &&
	    (!onPath[curR][curC - 1] && !onPath[curR][curC + 1])) {
		return 0;
    }

    // Optimizaition 2
    // If we have reached the endpoint without using all the steps
    // it is an invalid path
	if (curR == 7 && curC == 1) {  
		if (pathIdx == PATH_LEN) return 1;
        // if we used all it's valid
		return 0;
	}

    // Optimization 3
    // If all steps have been used and we have not reached the end
    // it is an invalid path
    if (pathIdx == PATH_LEN) return 0;
 
	int ret = 0;
	onPath[curR][curC] = true;
 
	// If a turn is already determined, take it
	if (p[pathIdx] < 4) {
		int nxtR = curR + dr[p[pathIdx]];
		int nxtC = curC + dc[p[pathIdx]];
		if (!onPath[nxtR][nxtC]) ret += tryPath(pathIdx + 1, nxtR, nxtC);
	}

	else {  // Iterate through all possible turns
		for (int i = 0; i < DIR_LEN; i++) {
			int nxtR = curR + dr[i];
			int nxtC = curC + dc[i];
			if (onPath[nxtR][nxtC]) continue;
			ret += tryPath(pathIdx + 1, nxtR, nxtC);
		}
	}

	// Reset and return
	onPath[curR][curC] = false;
	return ret;
}
 
int main() {
	string line;
	getline(cin, line);
 
	// Convert path to ints
	for (int i = 0; i < PATH_LEN; i++) {
		char cur = line[i];
 
		if (cur == 'U') p[i] = 0;
		else if (cur == 'R') p[i] = 1;
		else if (cur == 'D') p[i] = 2;
		else if (cur == 'L') p[i] = 3;
		else p[i] = 4;  // cur == '?'
	}
 
	// Set borders of grid
	for (int i = 0; i < GRID_SIZE; i++) {
		onPath[0][i] = true;
		onPath[8][i] = true;
		onPath[i][0] = true;
		onPath[i][8] = true;
	}

	// Initialize the grid to be empty
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) { onPath[i][j] = false; }
	}
 
	int startIdx = 0;
	int startR = 1;
	int startC = 1;  // Always start path at (1, 1)
	int ans = tryPath(startIdx, startR, startC);
	cout << ans << endl;
}