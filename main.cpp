#include <raylib.h>
#include <stdint.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define f32 float
#define f64 double
#define GET_BIT(num, n) (((num) >> (n)) & 1)

const u8 mapXsize = 8;
const u8 mapYsize = 8;	
const u8 size_tile = 64;

typedef struct {
	u8 bitbang;
} State;

typedef enum {
	state_1,
	state_2,
	state_3,
	state_4,
	
} States;

State state {
	.bitbang = 0x01
};

u16 map[mapXsize][mapYsize] = {
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
};

void map_draw() {
	for (int i = 0; i < mapXsize; i++) {
		for (int y = 0; y < mapYsize; y++) {
			 Color color = 		
			 DrawRectangle(l, int posY, size_tile, size_tile, color);   	
      		}
	}
}

void state_manage(u8 state) {
	for (int n = 0; n < 7; n++) {
		switch (GET_BIT(state,n)):
			case(0):
				switch (n):
					case:
		
			case(1):
			
	}
{

int main(void)
{

    const u16 screenWidth = 1024;
    const u16 screenHeight = 512;

    InitWindow(screenWidth, screenHeight, "The Window");

    SetTargetFPS(60);               

    while (!WindowShouldClose())   
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();        

    return 0;
}
