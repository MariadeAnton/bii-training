#include "glui/glui/src/include/GL/glui.h"
#include "erincatto/box2d/Box2D/Box2D.h"
#include <stdio.h>
#include <iostream>
using namespace std;

void run_game(int argc, char** argv);
void click_handler(int button_id);
void keyboard(unsigned char key, int x, int y);
void init_world();
void launch_circle(float32 x_position, float32 y_position);
static void SimulationLoop();
static void Timer(int);
b2Vec2 ConvertScreenToWorld(float32 world_width, float32 world_height,
								   float32 x, float32 y,
								   float32 x_obj_offset, float32 y_obj_offset);
void draw_circle(const b2Vec2& center, float32 radius);
