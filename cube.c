#include <stdio.h>
#include <string.h>

#define NB_COLS 206
#define NB_ROWS 49

char screen[NB_ROWS][NB_COLS];
char buffer[3 + NB_ROWS * (NB_COLS + 1)];

void display_screen(FILE *out_stream) {
    for (int i = 0; i < NB_ROWS; i++) {
        int offset = 3 + i * (NB_COLS + 1);
        memcpy(&buffer[offset], screen[i], NB_COLS);
        buffer[offset + NB_COLS] = '\n';
    }
    fwrite(buffer, sizeof(char), sizeof(buffer), out_stream);
}

int main(void) {
    memset(screen, ' ', sizeof(screen));
    fputs("\x1B[2J\x1B[?25l", stdout);
    fflush(stdout);

    buffer[0] = '\x1B';
    buffer[1] = '[';
    buffer[2] = 'H';

    while (1) {
        
        display_screen(stdout);
    }

    return 0;
}