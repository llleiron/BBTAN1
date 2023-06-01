#pragma once
#include "Ball.h"
#include "Box.h"
#include "raylib.h"
#include "PlusSign.h"
#include <ctime>

void ResolveCollision(Ball& ball, Box& box, int BallVelocity);
void CheckOutOfBorders(Ball& ball, const float BallVelocity, std::vector<Ball>& balls);
void DrawEverything(const std::vector<Ball>& balls, const std::vector<std::vector<Box>>& boxes, const std::vector<PlusSign>& plusSigns);
void MouseButtonPressed(const Vector2& MousePos, std::vector<Ball>& balls, const float Ball_Velocity);
void CheckBoxes(std::vector<std::vector<Box>>& boxes);
void GenerateBoxes(std::vector<std::vector<Box>>& boxes, int count, std::vector<PlusSign>& plusSigns);
void GenerateFirstLine(std::vector<std::vector<Box>>& boxes, int count, std::vector<PlusSign>& plusSigns);
void CalculateCurrentBallsCount(const std::vector<Ball>& balls, Ball& ball);
void CheckBallsPosition(std::vector<Ball>& balls);
int generate_random_number(int lhs, int rhs);
int GetBallIndexIfTouched(std::vector<Ball>& balls);
int CheckPlusSignCollected(const std::vector<Ball>& balls, std::vector<PlusSign>& plusSigns);
void ResolvePlusSignCollected(std::vector<PlusSign>& plusSigns, int index);
bool GameOver(const std::vector<std::vector<Box>>& boxes);
std::pair<int, int> CheckCollision(const Ball& ball, std::vector<std::vector<Box>>& boxes);