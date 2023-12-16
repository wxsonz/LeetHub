#define MAX_CHARS 26

/*bool isAnagram(char* s, char* t) {
    
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    if (s_len != t_len) return 0;
    
    int s_count[MAX_CHARS] = {0};
    int t_count[MAX_CHARS] = {0};

    for (int i = 0; i < s_len; i++) {
        s_count[s[i] - 'a']++;
    }

    for (int i = 0; i < t_len; i++) {
        t_count[t[i] - 'a']++;
    }

    for (int i = 0; i < MAX_CHARS; i++) {
        if (s_count[i] != t_count[i]) {
            return 0;
        }
    }

    return 1;
}*/


bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len != t_len) return 0;

    int count[MAX_CHARS] = {0};

    for (int i = 0; i < s_len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < t_len; i++) {
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}