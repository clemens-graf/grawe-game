#include <iostream>
#include <raylib.h>

using namespace std;

int main () {
    cout << "Starting the game" << endl;
    InitWindow(800,400,"GRAWE Pong");
    SetTargetFPS(60);

    while(WindowShouldClose()==false){
        BeginDrawing();
        DrawCircle(100,100,20,WHITE);
        //Rectangle left
        
        //Rectangle right

        EndDrawing();
    }

    CloseWindow();

    return 0;
}