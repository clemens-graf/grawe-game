#include <iostream>
#include <raylib.h>

using namespace std;

const int screenWidth = 1280;
const int screenHeight = 800;
int player_score = 0;
int cpu_score = 0;
   
class Ball{
    public:
        float x, y;
        int speed_x, speed_y;
        int radius;
    
        Ball(int x_cons, int y_cons, int speedx, int speedy, int rad) {x = x_cons; y = y_cons; speed_x = speedx; speed_y = speedy; radius = rad;};
    
    void Draw(){
        DrawCircle(x,y,radius,WHITE);
    }

    void Update(){
        
        x += speed_x;
        y += speed_y;
        if(y + radius > GetScreenHeight() || y-radius<=0){
            speed_y*=-1;
        }
        if(x + radius > GetScreenWidth()){
            cpu_score++;
            ResetBall();
        }
        if(x-radius<=0){
            player_score++;
            ResetBall();
        }
        
    }

    void ResetBall(){
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];
    }
};

class Paddle{
    protected:
        float x, y;
        float width, height;
        int speed = 5;

        void LimitMovement(){
            if(y <= 0)
                y = 0;
            if(y >= GetScreenHeight() - get_height())
                y = GetScreenHeight() - get_height();
        }
    public:
        Paddle(float x_, float y_, float width_, float height_) {x = x_; y = y_; width = width_; height = height_;}
        float get_x(){
            return x;
        }
        float get_y(){
            return y;
        }
        void set_x(int val1){
            x = val1;
        }
        void set_y(int val1){
            y = val1;
        }
        float get_width(){
            return width;
        }
        float get_height(){
            return height;
        }
        void set_width(int val1){
            width = val1;
        }
        void set_height(int val1){
            height = val1;
        }

        void Draw(){
            // 10, screenHeight/2 - 50,20,100,WHITE
            DrawRectangle(x,y,width,height, WHITE);
        }

        void Update() {
            
                if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
                    set_y(y-speed);
                }
            
                if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
                set_y(y+speed);
                }

                LimitMovement();
            }
};

class CPUpaddle : public Paddle{
    public:
    using Paddle::Paddle;

        void Update(int ball_y){
            if(y + height/2.0f > ball_y){
                y -= speed;
            }
            else if(y + height/2 <= ball_y){
                y += speed;
            }
            LimitMovement();
        }
};

Ball b(600, 200, 6, 6, 10);
Paddle player(10.0, screenHeight/2 - 50.0,20.0,100.0);
CPUpaddle cpu(screenWidth - 30.0f, screenHeight/2.0f - 50.0f,20.0f,100.0f);

int main () {
    cout << "Starting the game" << endl;
    InitWindow(screenWidth,screenHeight,"GRAWE Pong");
    SetTargetFPS(60);

    while(WindowShouldClose()==false){
        BeginDrawing();
        
        
        //test comment
        //Rectangle right

        if(CheckCollisionCircleRec(Vector2{b.x, b.y}, b.radius, Rectangle{player.get_x(), player.get_y(), player.get_width(), player.get_height()})){
            b.speed_x *= (-1);
        }

        if(CheckCollisionCircleRec(Vector2{b.x, b.y}, b.radius, Rectangle{cpu.get_x(), cpu.get_y(), cpu.get_width(), cpu.get_height()})){
            b.speed_x *= (-1);
        }

        ClearBackground(BLACK);
        //Drawing
        //Rectangle left
        //DrawRectangle(screenWidth-30, screenHeight/2 - 50,20,100,WHITE);
        
        player.Update();
        player.Draw();
        
        b.Update();
        b.Draw();

        cpu.Update(b.y);
        cpu.Draw();

        //Drawing line which separates fields
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);

        DrawText(TextFormat("%i", cpu_score), screenWidth/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screenWidth/4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}