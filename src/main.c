#include "raylib.h"
#include "raymath.h"

#define W_WIDTH 800
#define W_HEIGHT 600
#define W_TITLE "3D Demo"

// Colors
#define C_BG (Color) {0x10, 0x10, 0x10, 0xFF}

int main(void) {
  float camera_angle = 0;

  Camera3D cam = {0};
  cam.position = (Vector3){2.5f, 0.0f, 2.5f};
  cam.target = (Vector3){0.0f, 0.0f, 0.0f};
  cam.up = (Vector3){0.0f, 1.0f, 0.0f};
  cam.fovy = 45.0f;
  cam.projection = CAMERA_PERSPECTIVE;

  InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);

  while(!WindowShouldClose()) {
    BeginDrawing();

    camera_angle += 30 * GetFrameTime();

    if(camera_angle > 360*2)
      camera_angle = 0;

    cam.position.z = 2.5 * cos((camera_angle * PI)/360);
    cam.position.x = 2.5 * sin((camera_angle * PI)/360);

    ClearBackground(C_BG);

    BeginMode3D(cam);

    DrawLine3D(
      (Vector3){-0.5, -0.5, 0.5},
      (Vector3){-0.5, 0.5, 0.5},
      RED
    );
    DrawLine3D(
      (Vector3){0.5, -0.5, 0.5},
      (Vector3){0.5, 0.5, 0.5},
      RED
    );
    DrawLine3D(
      (Vector3){0.5, -0.5, 0.5},
      (Vector3){-0.5, -0.5, 0.5},
      RED
    );
    DrawLine3D(
      (Vector3){0.5, 0.5, 0.5},
      (Vector3){-0.5, 0.5, 0.5},
      RED
    );

    DrawLine3D(
      (Vector3){-0.5, 0.5, 0.5},
      (Vector3){-0.5, 0.5, -0.5},
      GREEN
    );
    DrawLine3D(
      (Vector3){0.5, 0.5, 0.5},
      (Vector3){0.5, 0.5, -0.5},
      GREEN
    );
    DrawLine3D(
      (Vector3){0.5, -0.5, 0.5},
      (Vector3){0.5, -0.5, -0.5},
      GREEN
    );
    DrawLine3D(
      (Vector3){-0.5, -0.5, 0.5},
      (Vector3){-0.5, -0.5, -0.5},
      GREEN
    );

    DrawLine3D(
      (Vector3){-0.5, -0.5, -0.5},
      (Vector3){-0.5, 0.5, -0.5},
      BLUE
    );
    DrawLine3D(
      (Vector3){0.5, -0.5, -0.5},
      (Vector3){0.5, 0.5, -0.5},
      BLUE
    );
    DrawLine3D(
      (Vector3){0.5, -0.5, -0.5},
      (Vector3){-0.5, -0.5, -0.5},
      BLUE
    );
    DrawLine3D(
      (Vector3){0.5, 0.5, -0.5},
      (Vector3){-0.5, 0.5, -0.5},
      BLUE
    );

    EndMode3D();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}