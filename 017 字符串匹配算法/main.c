#include <stdio.h>
#include <string.h>

// ******************** BF搜索 ********************
void bf_search(char *txt, char *pattern) {
    int txtCount = (int)strlen(txt);
    int patternCount = (int)strlen(pattern);
    
    for (int t = 0; t < txtCount - patternCount; t++) {
        int p = 0;
        for (; p < patternCount; p++) {
            if (txt[t + p] != pattern[p]) {
                break;
            }
        }
        if (p == patternCount) {
            printf("%d ", t);
        }
    }
    
    printf("\n");
}

// ******************** KPM搜索 ********************
void next(char *pattern, int *nxt) {
    int count = (int)strlen(pattern);
    
    nxt[0] = 0;
    int i = 1;
    int len = 0;
    
    while (i < count) {
        if (pattern[i] == pattern[len]) {
            nxt[i++] = ++len;
        } else if (len > 0) {
            len = nxt[len - 1];
        } else {
            nxt[i++] = 0;
        }
    }
    
    for (int j = 0; j < count; j++) {
        printf("%d ", nxt[j]);
    }
    printf("\n");
}

void kmp_search(char *txt, char *pattern) {
    int txtCount = (int)strlen(txt);
    int patternCount = (int)strlen(pattern);
    
    int nxt[patternCount];
    next(pattern, nxt);
    
    int t = 0;
    int p = 0;
    
    while (t < txtCount) {
        if (txt[t] == pattern[p]) {
            t++;
            p++;
            if (p == patternCount) {
                printf("%d ", t - p);
                p = nxt[p - 1];
            }
        } else if (p > 0) {
            p = nxt[p - 1];
        } else {
            t++;
        }
    }
    printf("\n");
}


int main() {
    
    bf_search("abcababc", "ab");
    
//    char *test = "abab";
    char *test = "abcabab";
//    int nxt[strlen(test)];
//    next(test, nxt);
    kmp_search(test, "ab");
    
    return 0;
}




