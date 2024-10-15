#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

typedef struct {
  int width;
  int height;
} ScreenInfo;

ScreenInfo scrInfo;

typedef struct {
  Vector2 pos;
  Vector2 dir;
  float planeX;
  float planeY;
} Player;

int asd[10] = {1, 2, 3, 1, 3, 2, 1, 2, 1, 2};

void initWindow() {
  int monitor = GetCurrentMonitor();
  scrInfo.width = GetMonitorWidth(monitor);
  scrInfo.height = GetMonitorHeight(monitor);

  InitWindow(scrInfo.width, scrInfo.height, "raycaster");

  ToggleBorderlessWindowed();

  SetTargetFPS(30);
}

int main(void) {
  initWindow();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < (int)(sizeof(asd) / sizeof(int)); i++) {
      Color color;
      switch (asd[i]) {
      case 1:
        color = RED;
        break;
      case 2:
        color = GREEN;
        break;
      case 3:
        color = YELLOW;
        break;
      default:
        color = PURPLE;
        break;
      }

      DrawRectangle(30 * i, 0, 30, GetScreenHeight(), color);
    }

    EndDrawing();
  }
  CloseWindow();

  return 0;
}
