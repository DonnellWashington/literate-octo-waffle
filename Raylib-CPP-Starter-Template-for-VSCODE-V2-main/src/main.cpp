#include<raylib.h>

// Basic player properties
typedef struct {
    Rectangle rect;
    Color color;
    Vector2 speed;
} player_t;

// Basic ball properties
typedef struct {
    Vector2 pos;
    Vector2 speed;

    float radius;
    Color color;
}ball_t;

// Initialzation of the ball
ball_t InitBall(){
    ball_t b;
    b.pos.x = 400;
    b.pos.y = 400;
    b.speed.x = 4;
    b.speed.y = -4;
    b.radius = 10;
    b.color = RED;

    return b;
}


//Draw the ball to the screen using the vector version of ball draw
void drawBall(ball_t *ball){ DrawCircleV(ball->pos, ball->radius, ball->color);}

// Check collisions between the ball and the players and reflect in other direction
void checkCollide(ball_t *ball, player_t *player){
    if (CheckCollisionCircleRec(ball->pos, ball->radius, player->rect)) ball->speed.x *= -1;
}

void drawPlayer(player_t *player){
    DrawRectangleRec(player->rect, player->color);
}

player_t InitPlayer(float x, float y, Color color){
    player_t p;
    p.rect.x = x;
    p.rect.y = y;
    p.rect.width = 10;
    p.rect.height = 100;
    p.color = color;

    p.speed.x = 0;
    p.speed.y = 5;

    return p;
}

int main(){

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
        


        EndDrawing();
    }
    

    return 0;
}