#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
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
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow && !WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
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
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            exitWindow = GuiWindowBox((Rectangle){ 0, 0, screenWidth, screenHeight }, "#196# PORTABLE WINDOW");
            
            DrawText(TextFormat("Mouse Position: [ %.0f, %.0f ]", mousePosition.x, mousePosition.y), 10, 40, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
