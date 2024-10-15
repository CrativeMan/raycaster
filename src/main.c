#include "stdlib.h"
#include <raylib.h>
#include <raymath.h>

void initWindow() {
  int monitor = GetCurrentMonitor();
  int width = GetMonitorWidth(monitor);
  int height = GetMonitorHeight(monitor);

  InitWindow(width, height, "raycaster");

  ToggleBorderlessWindowed();

  SetTargetFPS(30);
}

int main(void) {
  initWindow();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < 10; i++) {
      Color color = {arc4random_uniform(100), arc4random_uniform(100), 100,
                     100};
      DrawRectangle(5 * i, 10, 5, 70, color);
    }

    EndDrawing();
  }
  CloseWindow();

  return 0;
}
