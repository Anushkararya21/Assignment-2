#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    while (1) {   // For Restart

        srand(time(0));

        int x = 1;                  // player position (0-2)
        int step = 0;               // obstacle vertical movement
        int obstaclePos = rand() % 3;
        int speed = 120;            // start speed
        int score = 0;

        // -------- NEW MODIFICATION: COUNTDOWN --------
        printf("Get Ready!\n");
        for (int i = 3; i > 0; i--) {
            printf("%d...\n", i);
            Sleep(800);
        }
        system("cls");

        // -------- GAME STARTS --------
        while (1) {
            if (_kbhit()) {
                char ch = getch();

                if (ch == 75 && x > 0)        // LEFT arrow
                    x--;

                if (ch == 77 && x < 2)        // RIGHT arrow
                    x++;
            }

            // ---- DRAW ----
            system("cls");
            printf(" SCORE: %d\n", score);
            printf("|-----------|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {

                    if (obstaclePos == 0)
                        printf("| %c        |\n", 1);
                    else if (obstaclePos == 1)
                        printf("|     %c    |\n", 1);
                    else if (obstaclePos == 2)
                        printf("|        %c |\n", 1);

                } else {
                    printf("|           |\n");
                }
            }

            // ---- PLAYER ----
            if (x == 0)
                printf("| %c        |\n", 6);
            else if (x == 1)
                printf("|     %c    |\n", 6);
            else if (x == 2)
                printf("|        %c |\n", 6);

            // ---- COLLISION ----
            if (step == 10 && x == obstaclePos) {
                printf("\nGAME OVER! Your Final Score: %d\n\n", score);
                break;
            }

            Sleep(speed);

            // Move obstacle down
            step++;

            // Reset when reaches bottom
            if (step > 10) {
                step = 0;
                obstaclePos = rand() % 3; // new lane
                score++;                  // +1 score

                // Increase speed (difficulty)
                if (speed > 40)
                    speed -= 5;
            }
        }

        // -------- GAME OVER MENU --------
        int choice;
        printf("1. Restart\n");
        printf("2. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("\nExiting...\n");
            break;
        }
    }

    return 0;
}


