#include <stdio.h>
#include <stdlib.h>


void cursor_pos(int x, int y) {
    printf("\033[%d;%df", y, x);
}


void write_at(int x, int y) {
    char ch;
    cursor_pos(x, y);

    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case '\n':
                cursor_pos(x, ++y);
                break;
            case '\r':
                cursor_pos(x, y);
                break;
            default:
                fputc(ch, stdout);
                break;
        }
    }

    cursor_pos(1, y + 1);
    fflush(stdout);
}


void print_usage(void) {
    puts("usage: writeat <x> <y>");
}


int main(int argc, char** argv) {
    int x, y;

    if (argc < 3) {
        print_usage();
        return 1;
    }

    /* I don't care if this fails, don't have stupid inputs. */
    x = atoi(argv[1]);
    y = atoi(argv[2]);

    write_at(x, y);
    return 0;
}
