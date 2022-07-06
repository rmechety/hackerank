#include <climits>
#include <cmath>
#include <float.h>
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

typedef vector<vector<int> > matrix;
typedef vector<vector<string> > matrix_moves;
typedef vector<string > t_board;
typedef vector<pair<int, int> > matrix_pos;
enum move_value{
    UP,
    DOWN,
    RIGHT,
    LEFT
}
