#include <iostream>
#include "Ball.h"
#include "Box.h"
#include "PlusSign.h"
#include "raylib.h"
#include "UtilityFunctions.h"
#include <set>

int main() {
	const float ballVelocity = 15.0f;
	const float radius = 2.0f;
	const float speedX = 7.0f;
	const float speedY = 7.0f;
	const int windowHeight = 800;
	const int windowLength = 600;
	const char* title = "BBTAN";
	float angle = PI * 2.0f;
	int count = 1;


	int getCount = 1;
	int boxCount = 0;
	int index = -1;
	int plusSignCollected = -1;
	std::pair<int, int> collision = {-1, -1};
	std::vector<std::vector<Box>> boxes;
	std::vector<Ball> balls;
	std::vector<PlusSign> plusSigns;

	InitWindow(WindowHeight, WindowLength, title);
	SetTargetFPS(60);
	Ball ball(radius, windowHeight - radius, speedX, speedY, radius, angle);
	ball.SetOldX(ball.GetX());
	ball.SetOldY(ball.GetY());
	balls.push_back(ball);
	
	


	DrawEverything(balls, boxes, plusSigns);

	bool flag = false;
	bool generated = false;
	while (!WindowShouldClose()) {
		plusSignCollected = CheckPlusSignCollected(balls, plusSigns);
		if (plusSignCollected != -1) {
			ResolvePlusSignCollected(plusSigns, plusSignCollected);
			Ball ball(balls[balls.size() - 1]);
			balls.push_back(ball);
			for (auto& ball_ : balls) {
				ball_.SetFlag(true);
			}
		}
			
		if (GameOver(boxes)) {
			break;
		}
		if (balls[balls.size() - 1].GetY() + balls[balls.size() - 1].GetRadius() == GetScreenHeight() && !generated) {
			++box_count;
			generated = true;
			GenerateBoxes(boxes, box_count, plusSigns);
		}
		
		if (balls[balls.size() - 1].GetY() + balls[balls.size() - 1].GetRadius() != GetScreenHeight()) generated = false;
		CheckBoxes(boxes);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			MouseButtonPressed(GetMousePosition(), balls, ballVelocity);
			for (auto& ball_ : balls) {
				ball_.SetFlag(true);
			}
		}


		for (auto& ball_ : balls) {
			CalculateCurrentBallsCount(balls, ball_);
			CheckOutOfBorders(ball_, ballVelocity, balls);
			collision = CheckCollision(ball_, boxes);
			if (collision != std::make_pair(-1, -1)) {
				ResolveCollision(ball_, boxes[collision.first][collision.second], Ball_Velocity);
			}
		}
		index = GetBallIndexIfTouched(balls);
		if (index != -1) {
			CheckBallsPosition(balls);
		}
		DrawEverything(balls, boxes, plusSigns);
	}
}