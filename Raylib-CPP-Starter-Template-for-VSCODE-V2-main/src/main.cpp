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

        // if (IsKeyDown('W')){
        //     playerOneY -= 5;   
        // }
        // else if (IsKeyDown('S')){
        //     playerOneY += 5;
        // }
        // else if (IsKeyDown(KEY_UP)){
        //     playerTwoY -= 5;
        // }
        // else if (IsKeyDown(KEY_DOWN)){
        //     playerTwoY += 5;
        // }
        
        DrawRectangle(playerOneX, playerOneY, 25, 75, WHITE);
        DrawRectangle(playerTwoX, playerTwoY, 25, 75, WHITE);

        DrawCircle(ballX, ballY, 20, WHITE);

        if (IsKeyDown('W')){
            ballY -= 5;   
        }
        else if (IsKeyDown('S')){
            ballY += 5;
        }
        else if (IsKeyDown('A')){
            ballX -= 5;
        }
        else if (IsKeyDown('D')){
            ballX += 5;
        }
        
        if (ballX >= 775 && ballY >= 0){
            ballX = 400;
            ballY = 400;
            
        }
        else if (ballX <= 0 && ballY <= 0)
        {
            ballX = 400;
            ballY = 400;
        }
        else if (ballX <= 25 && ballY <= 775)
        {
            ballX = 400;
            ballY = 400;


        }
        else if (ballX >= 775 && ballY <= 775)
        {
            ballX = 400;
            ballY = 400;
        }
        else if (ballY <= 25)
        {
            ballX = 400;
            ballY = 400;
        }
        else if (ballY >= 775){
            ballX = 400;
            ballY = 400;
        }
        
        
        
        
        
        
        EndDrawing();
    }
    

    return 0;
}