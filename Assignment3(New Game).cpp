#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    srand(time(0));

    int player = 1;          // Player lane (0/1/2)
    int obsLane = rand() % 3;
    int obsY = 0;
    int score = 0;

    while (1) {
        // INPUT
        if (_kbhit()) {
            char ch = getch();
            if (ch == 75 && player > 0) player--;  // LEFT arrow
            if (ch == 77 && player < 2) player++;  // RIGHT arrow
        }

        // DRAW
        system("cls");
        printf(" CAR RACING MINI GAME\n");
        printf(" SCORE: %d\n", score);
        printf("---------------------\n");

        for (int i = 0; i < 10; i++) {
            if (i == obsY) {
                if (obsLane == 0)      printf("| ??        |\n");
                else if (obsLane == 1) printf("|     ??    |\n");
                else                   printf("|        ?? |\n");
            }
            else {
                printf("|           |\n");
            }
        }

        // Draw Player Car
        if (player == 0)      printf("| ??        |\n");
        else if (player == 1) printf("|     ??    |\n");
        else                  printf("|        ?? |\n");

        // COLLISION
        if (obsY == 10 && obsLane == player) {
            printf("\n?? CRASH! Game Over!\n");
            printf("Final Score: %d\n", score);
            break;
        }

        // Move obstacle
        Sleep(150);
        obsY++;

        // Reset obstacle after reaching bottom
        if (obsY > 10) {
            obsY = 0;
            obsLane = rand() % 3;
            score++;
        }
    }

    return 0;
}


