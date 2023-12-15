#define MAX_PATHS 100
#define MAX_NAME_LENGTH 20

struct Path {
    char start[MAX_NAME_LENGTH];
    char end[MAX_NAME_LENGTH];
};

char* destCity(char*** paths, int pathsSize, int* pathsColSize) {
    
    struct Path allPaths[MAX_PATHS];

    for (int i = 0; i < MAX_PATHS; ++i) {
        strcpy(allPaths[i].start, "");
        strcpy(allPaths[i].end, "");
    }

    for (int i = 0; i < pathsSize; ++i) {
        char* from = paths[i][0];
        char* to = paths[i][1];

        int found = 0;
        for (int j = 0; j < MAX_PATHS; ++j) {
            if (strcmp(allPaths[j].start, from) == 0) {
                found = 1;
                break;
            }
            if (strlen(allPaths[j].start) == 0) {
                strcpy(allPaths[j].start, from);
                break;
            }
        }

        if (!found) {
            for (int j = 0; j < MAX_PATHS; ++j) {
                if (strcmp(allPaths[j].end, to) == 0) {
                    found = 1;
                    break;
                }
                if (strlen(allPaths[j].end) == 0) {
                    strcpy(allPaths[j].end, to);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < MAX_PATHS; ++i) {
        if (strlen(allPaths[i].end) > 0) {
            int found = 0;
            for (int j = 0; j < MAX_PATHS; ++j) {
                if (strcmp(allPaths[i].end, allPaths[j].start) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                return strdup(allPaths[i].end);
            }
        }
    }

    return NULL;
}