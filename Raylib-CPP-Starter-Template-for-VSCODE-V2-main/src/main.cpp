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

    player_t player1 = InitPlayer(50, 250, WHITE);
    player_t player2 = InitPlayer(750, 250, WHITE);

    ball_t ball = InitBall();

    int p1Score = 0;
    int p2Score = 0;

    InitWindow(800, 800, "Poing!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(GREEN);

        drawBall(&ball);
        drawPlayer(&player1);
        drawPlayer(&player2);

        // Player movement
        if(IsKeyDown('W')) player1.rect.y -= 5;
        
        if(IsKeyDown('S')) player1.rect.y += 5;

        if (IsKeyDown(KEY_DOWN)) player2.rect.y += 5;

        if (IsKeyDown(KEY_UP)) player2.rect.y -= 5;
    
        // Borders and stuff

        if (player1.rect.y <= 0) player1.rect.y = 0;
        if (player1.rect.y + player1.rect.height > GetScreenHeight()) player1.rect.y = GetScreenHeight() - player1.rect.height;

        if (player2.rect.y <= 0) player2.rect.y = 0;
        if (player2.rect.y + player2.rect.height > GetScreenHeight()) player2.rect.y = GetScreenHeight() - player2.rect.height;

        DrawText(TextFormat("%i | %i", p1Score, p2Score), 300, 15, 100, RED);

        EndDrawing();
    }
    

    return 0;
}