#pragma once

#include <cmath>
#include <string>
#include <vector>
#include "raylib.h"
#include "Box.h"

class Ball final {
	public:
		Ball();
		Ball(const float X, const float Y, const float SpeedX, const float SpeedY, const float Radius, const float Angle);
		void SetX(const float X);
		void SetY(const float Y);
		void SetOldX(const float OldX);
		void SetOldY(const float OldY);
		void SetSpeedX(const float SpeedX);
		void SetSpeedY(const float SpeedY);
		void SetRadius(const float Radius);
		void SetAngle(const float Angle);
		void SetCount(const int Count);
		void SetFlag(const bool Flag);
		int GetCount() const;
		bool GetFlag() const;
		float GetX() const;
		float GetY() const;
		float GetOldX() const;
		float GetOldY() const;
		float GetRadius() const;
		float GetSpeedX() const;
		float GetSpeedY() const;
		float GetAngle() const;
		float CalculateAngle(const Vector2& MousePos) const;
	private:
		float X_;
		float Y_;
		float OldX_;
		float OldY_;
		float SpeedX_;
		float SpeedY_;
		float Radius_;
		float Angle_;
		int Count_ = 1;
		bool Flag_ = false;
};