#pragma once
#include "raylib.h"
#include <string>

class Box final{
	public:
		Box();
		Box(const float X, const float Y, const float Width, const float Height, const int count, const bool visible);
		void SetX(const float X);
		void SetY(const float Y);
		void SetWidth(const float Width);
		void SetHeight(const float Height);
		float GetX() const;
		float GetY() const;
		float GetWidth() const;
		float GetHeight() const;
		int GetCount() const;
		void SetCount(const int Count);
		bool GetVisible() const;
		void SetVisible(const bool visible);
		std::string GetCountText() const;
	private:
		float X_;
		float Y_;
		float Width_;
		float Height_;
		int Count_;
		bool Visible_;
};