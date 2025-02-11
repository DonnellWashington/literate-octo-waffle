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
    
    b.pos.x = GetScreenWidth() / 2;
    b.pos.y = GetScreenHeight() / 2;

    b.radius = 10;
    b.color = RED;

    int xDir = GetRandomValue(0,1) == 0 ? -1 : 1;
    int yDir = GetRandomValue(0,1) == 0 ? -1 : 1;

    b.speed.x = 5.0f * xDir;
    b.speed.y = 5.0f * yDir;

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

void checkWin(int &p1Score, int &p2Score){

    int goal = 5;

    if (p1Score == goal){
        DrawText("Player1 Wins!", 200, 200, 100, RED);
        p1Score = 0;
        p2Score = 0;
        WaitTime(3);
    }

    else if (p2Score == goal) {
        DrawText("Player2 Wins!", 200, 200, 100, RED);
        p1Score = 0;
        p2Score = 0;
        WaitTime(5);
    }

    

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

    InitWindow(800, 800, "Poing!");
    SetTargetFPS(60);

    Color green = {20, 160, 133, 255};

    player_t player1 = InitPlayer(50, 250, WHITE);
    player_t player2 = InitPlayer(750, 250, WHITE);

    ball_t ball = InitBall();

    int p1Score = 0;
    int p2Score = 0;

    while (WindowShouldClose() == false){
        
        ball.pos.x += ball.speed.x;
        ball.pos.y += ball.speed.y;

        if (ball.pos.x - ball.radius <= 0 || ball.pos.x + ball.radius >= GetScreenHeight()){
            ball.speed.y *= -1;
        }

        if (ball.pos.y - ball.radius <= 0 || ball.pos.y + ball.radius >= GetScreenHeight())
        {
            ball.speed.y *= -1;
        }
        

        if (ball.pos.x - ball.radius <= 0){
            p2Score++;
            ball = InitBall();
        }
        if (ball.pos.x + ball.radius >= GetScreenWidth()){
            p1Score++;
            ball = InitBall();
        }

        checkCollide(&ball, &player1);
        checkCollide(&ball, &player2);

        // Player movement
        if(IsKeyDown('W')) player1.rect.y -= 5;
        
        if(IsKeyDown('S')) player1.rect.y += 5;

        // if (IsKeyDown(KEY_DOWN)) player2.rect.y += 5;

        // if (IsKeyDown(KEY_UP)) player2.rect.y -= 5;

        // Player borders y cosas otras
        if (player1.rect.y <= 0) player1.rect.y = 0;
        if (player1.rect.y + player1.rect.height > GetScreenHeight()) player1.rect.y = GetScreenHeight() - player1.rect.height;

        if (player2.rect.y <= 0) player2.rect.y = 0;
        if (player2.rect.y + player2.rect.height > GetScreenHeight()) player2.rect.y = GetScreenHeight() - player2.rect.height;

        if (ball.pos.y < player2.rect.y +player2.rect.height / 2) player2.rect.y -= 5;

        else if (ball.pos.y > player2.rect.y + player2.rect.height / 2) player2.rect.y += 5;
        
        

        BeginDrawing();
        ClearBackground(green);
        drawBall(&ball);
        drawPlayer(&player1);
        drawPlayer(&player2);
        DrawText(TextFormat("%i | %i", p1Score, p2Score), 300, 15, 100, RED);
        checkWin(p1Score, p2Score);
        EndDrawing();
    }

    return 0;
}