#include<raylib.h>

int main(){

    Color green = {20, 160, 133, 255};

    int playerOneX = 15;
    int playerOneY = 400;

    int playerTwoX = 750;
    int playerTwoY = 400;

    int ballX = 400;
    int ballY = 400;
    InitWindow(800, 800, "Poing!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(green);

        if (IsKeyDown('W')){
            playerOneY -= 3;   
        }
        else if (IsKeyDown('S')){
            playerOneY += 3;
        }
        else if (IsKeyDown(KEY_UP)){
            playerTwoY -= 3;
        }
        else if (IsKeyDown(KEY_DOWN)){
            playerTwoY += 3;
        }
        
        DrawRectangle(playerOneX, playerOneY, 25, 75, WHITE);
        DrawRectangle(playerTwoX, playerTwoY, 25, 75, WHITE);

        DrawCircle(ballX, ballY, 20, WHITE);
        ballX += 5;
        ballY -= 5;
            // TOP RIGHT
            if (ballX >= playerTwoX){
                
            }
            
        
        EndDrawing();
    }
    

    return 0;
}