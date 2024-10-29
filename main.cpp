#include <raylib.h>
#include <stdint.h>
#include <math.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define f32 float
#define f64 double
#define GET_BIT(num, n) (((num) >> (n)) & 1)
#define TO_RADIANS(degrees) ((degrees) * 3.14159 / 180)

const u8 mapXsize = 8;
const u8 mapYsize = 8;	
const u8 size_tile = 64;

class Player {
public:
	u8 posX, posY, speed_linear, player_size, speed_angular;
	f32 angle;
	

Player() {
	posX = 200;
	posY = 200;
	angle = 180.0;
	speed_linear = 5;
	speed_angular = 15;
	player_size = 20;
}

void draw() {
	DrawRectangle(posX,posY, player_size, player_size, BLUE);
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

	if (IsKeyDown(KEY_A)) angle += speed_angular;
	if (IsKeyDown(KEY_D)) angle -= speed_angular;
	
	// Don't quite understand how this works yet
	if(angle >= 360) angle -= 360;
	if(angle <= 0) angle += 360;
}

private:
};


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
	EndDrawing();
	}

	CloseWindow();        

return 0;
}
