#include "Ball.h"


Ball::Ball() {
	X_ = 0.0;
	Y_ = 0.0;
	SpeedY_ = 0.0;
	SpeedX_ = 0.0;
	Radius_ = 0.0;
	Angle_ = 0.0;
}

Ball::Ball(const float X, const float Y, const float SpeedX, const float SpeedY, const float Radius, const float Angle) {
	X_ = X;
	Y_ = Y;
	SpeedX_ = SpeedX;
	SpeedY_ = SpeedY;
	Radius_ = Radius;
	Angle_ = Angle;
}

void Ball::SetX(const float X) {
	X_ = X;
}

void Ball::SetY(const float Y){
	Y_ = Y;
}

void Ball::SetRadius(const float Radius) {
	Radius_ = Radius;
}

void Ball::SetSpeedX(const float SpeedX) {
	SpeedX_ = SpeedX;
}

void Ball::SetSpeedY(const float SpeedY) {
	SpeedY_ = SpeedY;
}

float Ball::GetSpeedX() const {
	return SpeedX_;
}

float Ball::GetSpeedY() const {
	return SpeedY_;
}

float Ball::GetX() const {
	return X_;
}

float Ball::GetY() const {
	return Y_;
}

float Ball::GetRadius() const {
	return Radius_;
}

void Ball::SetAngle(const float Angle) {
	Angle_ = Angle;
}

float Ball::GetAngle() const {
	return Angle_;
}

float Ball::CalculateAngle(const Vector2& MousePos) const {
	float Hypotenuse = sqrt(pow(MousePos.x - _X, 2) + pow(MousePos.y - _Y, 2));
	float Edge = (GetScreenHeight() - MousePos.y);
	return asin(Edge / Hypotenuse);
}

void Ball::SetOldX(const float OldX) {
	OldX_ = OldX;
}

void Ball::SetOldY(const float OldY) {
	OldY_ = OldY;
}

float Ball::GetOldX() const {
	return OldX_;
}

float Ball::GetOldY() const {
	return OldY_;
}

void Ball::SetCount(const int Count) {
	Count_ = Count;
}

int Ball::GetCount() const {
	return Count_;
}

void Ball::SetFlag(const bool Flag) {
	Flag_ = Flag;
}

bool Ball::GetFlag() const {
	return Flag_;
}