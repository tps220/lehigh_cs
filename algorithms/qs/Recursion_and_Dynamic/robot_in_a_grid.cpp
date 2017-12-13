#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct point {
    int row;
    int col;
    block(r, c) : row(r), col(c) {}
}

bool compareBlock(block &block1, block &block2) {
    return block1.row == block2.row && block1.col == block2.col;
}

vector<block> findPath(vector<vector<point>> board) {
    if (board == NULL || board.size() == 0) {
        return NULL;
    }
    unodred_set<int> cahce;
    vector<Point> path;
    return findPath(board, 0, 0, cache, path);
}

boolean findPath(vector<vector<point>> board, int r, int c, unordered_set<point> &cache, vector<int> &path) {
    if (notAValidPoint(r, c)) {
        return false;
    }
    Point p = new point(r, c);
    if (cache.find(p) != cahch.end()) {
        return false;
    }
    if (atEnd(r, c) || findPath(board, r + 1, c, cache, path) || findPath(board, r, c + 1, cache, path) {
        path.add(p);
        return true;
    }
    cache.insert(p);
    return false;
}
