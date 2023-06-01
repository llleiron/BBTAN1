#pragma once
#include <raylib.h>

class LineSign final {
	public:
		LineSign();
		LineSign(const float X, const float Y, const float Radius);
		float GetX() const;
		float GetY() const;
		bool Visible() const;
		void SetX(const float X);
		void SetY(const float Y);
		void SetRadius(const float Radius);
		void SetVisibility(const bool Visibility);

	private:
		float X_;
		float Y_;
		float Radius_;
		bool Visibility_ = true;
};