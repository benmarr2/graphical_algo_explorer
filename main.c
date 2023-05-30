#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define ARRAY_SIZE 50

int main()
{
    int array[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        array[i] = GetRandomValue(10, 450);  
    }

    const int screenWidth = 800;
    const int screenHeight = 600;
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "raygui - portable window");

    // General variables
    Vector2 mousePosition = { 0 };
    Vector2 windowPosition = { 500, 200 };
    Vector2 panOffset = mousePosition;
    bool dragWindow = false;
    
    SetWindowPosition(windowPosition.x, windowPosition.y);
    
    bool exitWindow = false;
    
    SetTargetFPS(60);

    while (!exitWindow && !WindowShouldClose())    // Detect window close button or ESC key
    {
        mousePosition = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !dragWindow)
        {
            if (CheckCollisionPointRec(mousePosition, (Rectangle){ 0, 0, screenWidth, 20 }))
            {
                dragWindow = true;
                panOffset = mousePosition;
            }
        }

        if (dragWindow)
        {            
            windowPosition.x += (mousePosition.x - panOffset.x);
            windowPosition.y += (mousePosition.y - panOffset.y);

            SetWindowPosition((int)windowPosition.x, (int)windowPosition.y);
            
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) dragWindow = false;
        }

        for (int i = 0; i < ARRAY_SIZE - 1; i++) {    
            for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {  
                if (array[j] > array[j+1]) { 
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;

                    BeginDrawing();
                    ClearBackground(RAYWHITE);

                    for (int i = 0; i < ARRAY_SIZE; i++) {
                        DrawRectangle(i * (GetScreenWidth()/ARRAY_SIZE), GetScreenHeight() - array[i], GetScreenWidth()/ARRAY_SIZE, array[i], BLUE);
                    }

                    EndDrawing();

                } 
            }
        }
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
