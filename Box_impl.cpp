#include "Box.h"
#include <iostream>

Box::Box() {
	X_ = 0.0;
	Y_ = 0.0;
	Width_ = 0.0;
	Height_ = 0.0;
}

Box::Box(const float X, const float Y, const float Width, const float Height, const int count, const bool visible) {
	X_ = X;
	Y_ = Y;
	Width_ = Width;
	Height_ = Height;
	Count_ = count;
	Visible_ = visible;
}

void Box::SetX(const float X) {
	X_ = X;
}

void Box::SetY(const float Y) {
	Y_ = Y;
}

void Box::SetHeight(const float Height) {
	Height_ = Height;
}

void Box::SetWidth(const float Width) {
	Width_ = Width;
}

float Box::GetX() const {
	return X_;
}

float Box::GetY() const {
	return Y_;
}

float Box::GetHeight() const {
	return Height_;
}

float Box::GetWidth() const {
	return Width_;
}


int Box::GetCount() const {
	return Count_;
}

void Box::SetCount(const int count) {
	Count_ = count;
}

std::string Box::GetCountText() const {
	return std::to_string(Count_);
}

bool Box::GetVisible() const {
	return Visible_;
}

void Box::SetVisible(const bool visible) {
	Visible_ = visible;
}

