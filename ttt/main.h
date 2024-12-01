#ifndef MY_GAME_H
#define MY_GAME_H

//------includes
#include <raylib.h>
#include <stddef.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdio.h>

//------defines
#define DEFAULT_POSITION ((Vector2){ 1200.0f, 740.0f })
#define MAX_SOUNDS 5
#define MAX_TEXTURES 10
#define MAX_CHAR 500
#define MAX_COLORS 5
#define TARGET_FPS 60
#define LOGO_POSX 10
#define LOGO_POSY 10
#define LOGO_SIZE 30
#define BOARD_POSX 420
#define BOARD_POSY 180
#define BOARD_HEIGHT 440
#define BOARD_WIDTH 440
#define BLOCK_HEIGHT 140
#define BLOCK_WIDTH 140
#define GAME_X 240
#define GAME_Y 100
#define GAME_HEIGHT 600
#define GAME_WIDTH 800
#define SET_FLAG(flags, flag) ((flags).all_flags |= (flag))
#define CLEAR_FLAG(flags, flag) ((flags).all_flags &= ~(flag))
#define CHECK_FLAG(flags, flag) ((flags).all_flags & (flag))
#define TOGGLE_FLAG(flags, flag) ((flags) ^= (flag))
//------structs


enum Gamestate
{
	SPLASH,
	GAME_PLAYING,
	GAME_OVER,
	SCORE_BOARD,
	END
};

enum Turn
{
	TURN_X,
	TURN_O
};
enum Directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct Flags
{
	unsigned int all_flags;

	enum
	{
		FLAG_ONE   = 1 << 0,
		FLAG_TWO   = 1 << 1,
		FLAG_THREE = 1 << 2,
		FLAG_FOUR  = 1 << 3
	};
} Flags;

enum color_list
{
	BACKGROUND,
	FOREGROUND,
	BACKGROUND_TEXT,
	FOREGROUND_TEXT,
	WINDOW_BACKGROUND,
	WINDOW_TEXT
};



//------funcs

void init_game(int, char**, Gamestate *, Color *, Texture2D *);
void splash(Gamestate *, Color *, Texture2D *, double);
void game_playing(Gamestate *, Color *, Texture2D *, double);
void game_over(Gamestate *, Color *, Texture2D *, double);
void scoreBoard(Gamestate *, Color *, Texture2D *, double);

void display_mouse_coords(Vector2, int, Color);
double getFrames(void);
int timer(int, double, int);
int countDownTimer(int, double, int);
int formatTimer(int, char *);
int drawCurtains(int, int, int, int, Color, int);
int fadeToBlack(int);
int fadeFromBlack(int);

//------util funcs

std::string GetFullPath(const std::string& filename, const std::string& basePath);
Texture2D LoadTextureFromPath(const std::string& filename, const std::string& basePath);
Sound LoadSoundFromPath(const std::string& filename, const std::string& basePath);
#endif
