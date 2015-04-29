#include "save.h"
#include "game.h"


//GLUI CONF
int width = 800;
int height = 800;
int framePeriod = 16;
float settingsHz = 60.0;
int mainWindow;
const int BUTTON_APPLY = 0;
const int BUTTON_SAVE = 1;


//BOX 2 conf
b2World* world;
float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 8;
int32 positionIterations = 1;
float32 circle_radius = 1; //meters
int32 world_height = 20; // meters
int32 world_width = 20; // meters
float32 world_gravity = 10;

//Draw polygon
void draw_circle(const b2Vec2& center, float32 radius)
{
		radius = (radius / world_width * 2.0);
		const float32 k_segments = 16.0f;
		const float32 k_increment = 2.0f * b2_pi / k_segments;
		float32 theta = 0.0f;
		glEnable(GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.5f * 0, 0.5f * 0x33, 0.5f * 0xff, 0.5f);
		glBegin(GL_TRIANGLE_FAN);
		for (int32 i = 0; i < k_segments; ++i)
		{
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
			glVertex2f(v.x, v.y);
			theta += k_increment;
		}
		glEnd();
		glDisable(GL_BLEND);

		theta = 0.0f;
		glColor4f(0,0,0,1);
		glBegin(GL_LINE_LOOP);
		for (int32 i = 0; i < k_segments; ++i)
		{
			b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
			glVertex2f(v.x, v.y);
			theta += k_increment;
		}
		glEnd();

		b2Vec2 p = center;
		glBegin(GL_LINES);
		glVertex2f(center.x, center.y);
		glVertex2f(p.x, p.y);
		glEnd();
}


b2Vec2 ConvertScreenToWorld(float32 world_width, float32 world_height,
								   float32 x, float32 y,
								   float32 x_obj_offset, float32 y_obj_offset){
	b2Vec2 p;
	//cout << y << endl;
	p.x = (x / world_width * 2.0) + (x_obj_offset / world_width * 2.0);
	p.y = (y / world_height * 2.0) + (y_obj_offset / world_height * 2.0) ;
	return p;
}

// This is used to control the frame rate (60Hz).
static void Timer(int)
{
	glutSetWindow(mainWindow);
	glutPostRedisplay();
	glutTimerFunc(framePeriod, Timer, 0);
}

static void SimulationLoop()
{

	glClearColor(255.0f, 255.0f, 255.0f, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//test->Step(&settings);

	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	world->Step(timeStep, velocityIterations, positionIterations);

	// Now print the position and angle of the body.
	int i=0;
	for (b2Body* item = world->GetBodyList(); item; item = item->GetNext()) {
		b2Vec2 position = item->GetPosition();
		//Get the fixture radius
		b2Fixture* fixture = (b2Fixture*) item->GetFixtureList();
		b2Shape::Type shapeType = fixture->GetType();
		if (shapeType == b2Shape::e_circle ){
			b2CircleShape* shape = (b2CircleShape*) fixture->GetShape();
			//cout << "Radio: " << shape->m_radius << endl;
			//float32 angle = item->GetAngle();
			b2Vec2 position_world = ConvertScreenToWorld(world_width, world_height, position.x, position.y, shape->m_radius, shape->m_radius);
			draw_circle(position_world, shape->m_radius);
			//cout << "X = " << position_world.x << " Y = " << position_world.y << endl;
		}
	}

	std::flush(std::cout);
	glutSwapBuffers();
}

void launch_circle(float32 x_position, float32 y_position){

	//**************************************************//
	//            Creating a Circle Shape               //
	//**************************************************//
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	//Ball position
	BodyDef.position = b2Vec2(x_position, y_position);
	b2Body* new_element;
	new_element = world->CreateBody(&BodyDef);

	b2CircleShape circle;
	circle.m_radius = circle_radius;

	b2FixtureDef fixtureDef;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.2f;
	fixtureDef.restitution = 0.7f;

	fixtureDef.shape = &circle;

	new_element->CreateFixture(&fixtureDef);

	b2Vec2 gravity(0.0f,-1 * world_gravity);
	world->SetGravity(gravity);
}

void init_world(){

	//**************************************************//
	//                 Creating a World                 //
	//**************************************************//

	// Define the gravity vector.
	b2Vec2 gravity(0.0f,-1 * world_gravity);

	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(gravity);

	//**************************************************//
	//                 Creating a Ground Box            //
	//**************************************************//

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -1*(world_height));

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world->CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(world_width/2, world_height/2);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
}

void keyboard(unsigned char key, int x, int y){
	if(key <= '8' && key >= '0'){
		int value = (key - '1') * 2 - 10;
		launch_circle(value, (world_height)/2);
	}
}

void click_handler(int button_id){
	if(button_id==BUTTON_APPLY){
		b2Vec2 gravity(0.0f,-1 * world_gravity);
		world->SetGravity(gravity);
	}
	else if(button_id==BUTTON_SAVE){
		game_parameters parameters;
		parameters.gravity = world_gravity;
		parameters.radius = circle_radius;
		save(parameters);
	}
}

void run_game(int argc, char** argv){
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(width, height);

	// Init Box2D World
	init_world();

	// Init database to load and save parameters
	init_database();

	// Load saved parameters
	game_parameters params = load();
	world_gravity = params.gravity;
	circle_radius = params.radius;

	mainWindow = glutCreateWindow("Biicode example: BOX2D + GLUT + SQLITE");
	//glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	GLUI *glui = GLUI_Master.create_glui_subwindow(mainWindow, GLUI_SUBWINDOW_RIGHT );

	glui->add_statictext("Press 1 to 8 to throw balls");
	glui->add_separator();

	GLUI_Spinner* radiusSpinner = glui->add_spinner("Ball Radius", GLUI_SPINNER_FLOAT, &circle_radius);
	radiusSpinner->set_float_limits(0.1, 3);
	glui->add_separator();

	GLUI_Spinner* gravitySpinner = glui->add_spinner("Gravity", GLUI_SPINNER_FLOAT, &world_gravity);
	gravitySpinner->set_float_limits(0.1, 100);
	glui->add_button("Apply", BUTTON_APPLY, (GLUI_Update_CB) click_handler);
	glui->add_separator();

	glui->add_button("Save", BUTTON_SAVE, (GLUI_Update_CB) click_handler);

	glutDisplayFunc(SimulationLoop);
	glutTimerFunc(framePeriod, Timer, 0);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}

