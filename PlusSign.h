#pragma once
#include <raylib.h>

class PlusSign final {
	public:
		PlusSign();
		PlusSign(const float X, const float Y, const float Radius);
		float GetX() const;
		float GetY() const;
		float GetRadius() const;
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
	
	public:
		const char* Text = "+";
};