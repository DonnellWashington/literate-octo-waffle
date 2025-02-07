#include<raylib.h>

typedef struct Player{

    float x;
    float y;

    int width;
    int height;

    float speed;

    Rectangle rec;

} player_t;

typedef struct Ball{

    int radius;


} ball_t;


int main(){

    Vector2 center = {20.00, 10.0};

    Color green = {20, 160, 133, 255};

    int playerOneX = 15;
    int playerOneY = 400;

    int playerTwoX = 750;
    int playerTwoY = 400;

    int ballX = 400;
    int ballY = 400;

    int p1Score = 0;
    int p2Score = 0;

    InitWindow(800, 800, "Poing!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(green);

        DrawRectangle(playerOneX, playerOneY, 25, 75, WHITE);
        DrawRectangle(playerTwoX, playerTwoY, 25, 75, WHITE);

        DrawCircle(ballX, ballY, 20, WHITE);


        // Player movement
        if (IsKeyDown('W')){
            playerOneY -= 5;   
        }
        else if (IsKeyDown('S')){
            playerOneY += 5;
        }
        else if (IsKeyDown(KEY_UP)){
            playerTwoY -= 5;
        }
        else if (IsKeyDown(KEY_DOWN)){
            playerTwoY += 5;
        }
    
        // Borders and stuff
        if (ballX >= 775 && ballY >= 0){
            ballX = 400;
            ballY = 400;
            p1Score++;
        }
        else if (ballX <= 0 && ballY <= 0){
            ballX = 400;
            ballY = 400;
            p2Score++;
        }
        else if (ballX <= 25 && ballY <= 775){
            ballX = 400;
            ballY = 400;
            p2Score++;
        }
        else if (ballX >= 775 && ballY <= 775){
            ballX = 400;
            ballY = 400;
            p1Score++;
        }
        else if (ballY <= 25){
            ballX = 400;
            ballY = 400;
        }
        else if (ballY >= 775){
            ballX = 400;
            ballY = 400;
        }
        
        DrawText(TextFormat("%i | %i", p1Score, p2Score), 300, 15, 100, RED);
        
//        if(CheckCollisionCircleRec(center, radius, ))

        EndDrawing();
    }
    

    return 0;
}