struct Node {
    char key;
    int count;
    struct Node *next;
};

struct HashMap {
    struct Node **array;
    int size;
};

struct HashMap* createHashMap(int size) {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->size = size;
    map->array = (struct Node**)malloc(size * sizeof(struct Node*));
    
    for (int i = 0; i < size; i++) {
        map->array[i] = NULL;
    }
    
    return map;
}

int hashCode(struct HashMap* map, char key) {
    return key % map->size;
}

struct Node* createNode(char key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(struct HashMap* map, char key) {
    int index = hashCode(map, key);
    
    if (map->array[index] == NULL) {
        map->array[index] = createNode(key);
    } else {
        struct Node* curr = map->array[index];
        while (curr->next != NULL && curr->key != key) {
            curr = curr->next;
        }
        if (curr->key == key) {
            curr->count++;
        } else {
            curr->next = createNode(key);
        }
    }
}

bool makeEqual(char** words, int wordsSize) {
    struct HashMap* counts = createHashMap(26); // Assuming only lowercase English letters
    
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            insert(counts, words[i][j]);
        }
    }
    
    for (int i = 0; i < counts->size; i++) {
        struct Node* current = counts->array[i];
        while (current != NULL) {
            if (current->count % wordsSize != 0) {
                return false;
            }
            current = current->next;
        }
    }
    
    return true;
}