struct Pair {
    int first;
    int second;
};

struct Pair createPair(int x, int y) {
    struct Pair p;
    p.first = x;
    p.second = y;
    return p;
}

bool isPairEqual(struct Pair a, struct Pair b) {
    return (a.first == b.first) && (a.second == b.second);
}

bool isPathCrossing(const char *path) {
    int x = 0, y = 0;
    struct Pair initial = createPair(0, 0);
    struct Pair current;
    struct Pair positions[10000];
    int posIndex = 0;
    positions[posIndex++] = initial;

    for (int i = 0; path[i] != '\0'; ++i) {
        char p = path[i];
        if (p == 'N') y++;
        else if (p == 'S') y--;
        else if (p == 'E') x++;
        else x--;

        current = createPair(x, y);
        bool found = false;
        for (int j = 0; j < posIndex; ++j) {
            if (isPairEqual(current, positions[j])) {
                found = true;
                break;
            }
        }
        if (found) return true;
        else positions[posIndex++] = current;
    }
    return false;
}