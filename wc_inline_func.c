#include <stdio.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;

#define is_space(c) ((c == ' ' || c == '\t' || c == '\n' || c == '\r') ? TRUE : FALSE)

static inline void f_count_c(int* count_cp, char c) {
    (*count_cp)++;
}

static inline void f_count_w(int* count_wp, Bool* in_wordp, char c) {
    if (is_space(c)) {
        *in_wordp = FALSE;
    } else {
        if (!(*in_wordp)) {
            (*in_wordp) = TRUE;
            (*count_wp)++;
        }
    }
}

static inline void f_count_l(int* count_lp, char c) {
    if (c == '\n')
        (*count_lp)++;
}

int main (int argc, char** argv) {
    int  c = 0;
    int  count_c = 0,
         count_w = 0,
         count_l = 0;
    Bool in_word = FALSE;

    while((c = getchar()) != EOF) {
        f_count_c(&count_c, c);
        f_count_w(&count_w, &in_word, c);
        f_count_l(&count_l, c);
    }

    printf("%d %d %d\n", count_c, count_w, count_l);
}
