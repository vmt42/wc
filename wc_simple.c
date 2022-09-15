#include <stdio.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;

#define is_space(c) ((c == ' ' || c == '\t' || c == '\n' || c == '\r') ? TRUE : FALSE)

int main (int argc, char** argv) {
    int  c = 0;
    Bool in_word = FALSE;
    int  count_c = 0,
         count_w = 0,
         count_l = 0;

    count_c = 0;
    count_w = 0;
    count_l = 0;
    in_word = FALSE;
    while((c = getchar()) != EOF) {
        if (is_space(c)) {
            in_word = FALSE;
        } else {
            if (!in_word) {
                in_word = TRUE;
                count_w++;
            }
        }
        if (c == '\n')
            count_l++;
        count_c++;
    }

    printf("%d %d %d\n", count_c, count_w, count_l);
}
