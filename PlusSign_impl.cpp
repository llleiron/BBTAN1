#include "PlusSign.h"

PlusSign::PlusSign() {
	X_ = 0;
	Y_ = 0;
	Radius_ = 0;
	Visibility_ = true;
}

PlusSign::PlusSign(const float X, const float Y, const float Radius) {
	X_ = X;
	Y_ = Y;
	Radius_ = Radius;
	Visibility_ = true;
}

float PlusSign::GetX() const {
	return X_;
}

float PlusSign::GetY() const {
	return Y_;
}

float PlusSign::GetRadius() const {
	return Radius_;
}

bool PlusSign::Visible() const {
	return Visibility_;
}

void PlusSign::SetX(const float X) {
	X_ = X;
}

void PlusSign::SetY(const float Y) {
	Y_ = Y;
}

void PlusSign::SetRadius(const float Radius) {
	Radius_ = Radius;
}

void PlusSign::SetVisibility(const bool Visibility) {
	Visibility_ = Visibility;
}