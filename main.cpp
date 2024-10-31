#include <raylib.h>
#include <stdint.h>
#include <math.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define f32 float
#define f64 double
#define GET_BIT(num, n) (((num) >> (n)) & 1)
#define TO_RADIANS(degrees) ((degrees) * 3.14159f / 180.0f)
#define MIDDLE_PLAYER(var) (pos##var + (player_size / 2))

const u8 mapXsize = 8;
const u8 mapYsize = 8;	
const u8 size_tile = 64;

u16 map[mapXsize][mapYsize] = {
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,1,0,0,1},
	{1,0,0,0,1,0,0,1},
	{1,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1},
};


class Player {
public:
	u8 speed_linear, player_size, speed_angular;
	f32 angle, posX, posY;
	

Player() {
	posX = 200;
	posY = 200;
	angle = 180.0;
	speed_linear = 5;
	speed_angular = 5;
	player_size = 20;
}

void simpleRaycast() {

	f32 rayX = MIDDLE_PLAYER(X);
	f32 rayY = MIDDLE_PLAYER(Y);
	f32 rayStepSize = 5.0f;  

	bool wallFound = false;	
	while (!wallFound) {
		rayX += cos(TO_RADIANS(angle)) * rayStepSize;
		rayY += sin(TO_RADIANS(angle)) * rayStepSize;

		u8 mapGridX = (u8)(rayX / size_tile);
		u8 mapGridY = (u8)(rayY / size_tile);

		if (map[mapGridY][mapGridX] == 1) wallFound = true; 
	}

	DrawLineEx({ MIDDLE_PLAYER(X), MIDDLE_PLAYER(Y) }, { rayX, rayY }, 2.0, BLUE);
}


void draw() {
	DrawRectangle(posX,posY, player_size, player_size, BLUE);

	// This is to draw a line to indicate the player direction
	Vector2 start = { MIDDLE_PLAYER(X), MIDDLE_PLAYER(Y) };	
	Vector2 end = { MIDDLE_PLAYER(X) + 30 * cos(TO_RADIANS(angle)), MIDDLE_PLAYER(Y) + 30 * sin(TO_RADIANS(angle)) };
	DrawLineEx(start,end, 5.0, RED);
}

void move() {
	if (IsKeyDown(KEY_W)) {
		posY += speed_linear * sin(TO_RADIANS(angle));
		posX += speed_linear * cos(TO_RADIANS(angle));

	}	
	if (IsKeyDown(KEY_S)) {
		posY -= speed_linear * sin(TO_RADIANS(angle));
		posX -= speed_linear * cos(TO_RADIANS(angle));
	}

	if (IsKeyDown(KEY_A)) angle -= speed_angular;
	if (IsKeyDown(KEY_D)) angle += speed_angular;
	
	// Don't quite understand how this works yet
	if(angle >= 360) angle -= 360;
	if(angle <= 0) angle += 360;
}

private:
};

void map_draw() {
	for (int i = 0; i < mapXsize; i++) {
		for (int j = 0; j < mapYsize; j++) {
			 Color color = (map[j][i] == 1) ? BLACK : WHITE;		
			 DrawRectangle(i * size_tile, j * size_tile, size_tile - 1, size_tile - 1, color);   	
      		}
	}
}

int main(void)
{

	const u16 screenWidth = 1024;
	const u16 screenHeight = 512;

	InitWindow(screenWidth, screenHeight, "The Window");

	SetTargetFPS(60);               

	Player player;
	
	while (!WindowShouldClose())   
	{

	BeginDrawing();

	ClearBackground(RAYWHITE);
	player.move();

	map_draw();
	player.draw();
	player.simpleRaycast();
	EndDrawing();
	}

	CloseWindow();        

return 0;
}
