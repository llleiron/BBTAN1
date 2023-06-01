#include "UtilityFunctions.h"
#include <cmath>
#include <iostream>
#include <string>
#include <random>
#include <set>

//Check if the ball hitted the box, if hitted return box id
std::pair<int, int> CheckCollision(const Ball& ball, std::vector<std::vector<Box>>& boxes) {
    
    for (int i = 0; i < boxes.size(); ++i) {
        for (int j = 0; j < boxes[i].size(); ++j) {
            Box box = boxes[i][j];
            if (box.GetVisible() == false) continue;
            if (ball.GetX() + ball.GetRadius() > box.GetX() && ball.GetX() - ball.GetRadius() < box.GetX() + box.GetWidth() &&
                ball.GetY() + ball.GetRadius() > box.GetY() && ball.GetY() - ball.GetRadius() < box.GetY() + box.GetHeight()) {
                boxes[i][j].SetCount(boxes[i][j].GetCount() - 1);
                if (boxes[i][j].GetCount() == 0) {
                    boxes[i][j].SetVisible(false);
                }
                return { i, j };
            }
        }
    }
    return {-1, -1};
}

//if CheckCollision() returned not {-1, -1}, than collision has been occured
//and ResolveCollision() resolves it
void ResolveCollision(Ball& ball, Box& box, int BallVelocity) {
     if ((ball.GetX() - ball.GetRadius() > box.GetX()) && (ball.GetX() + ball.GetRadius() < box.GetX() + box.GetWidth())) {
        ball.SetAngle(-1 * ball.GetAngle());
        ball.SetSpeedX(BallVelocity * cos(ball.GetAngle()));
        ball.SetSpeedY(-1 * BallVelocity * sin(ball.GetAngle()));
       }
   else {
        ball.SetAngle(PI - ball.GetAngle());
        ball.SetSpeedX(BallVelocity * cos(ball.GetAngle()));
        ball.SetSpeedY(-1 * BallVelocity * sin(ball.GetAngle()));
    }
    
}

//Check if the ball is out of borders
void CheckOutOfBorders(Ball& ball, const float BallVelocity, std::vector<Ball>& balls){

    if (ball.GetX() - ball.GetRadius() < 0) {
        ball.SetX(ball.GetRadius());
        ball.SetOldX(ball.GetX());
        ball.SetAngle(PI - ball.GetAngle());
        ball.SetSpeedX(BallVelocity * cos(ball.GetAngle()));
        ball.SetSpeedY(-1 * BallVelocity * sin(ball.GetAngle()));
    }
    else if (ball.GetX() + ball.GetRadius() > GetScreenWidth()) {
        ball.SetX(GetScreenWidth() - ball.GetRadius());
        ball.SetoldX(ball.GetX());
        ball.SetAngle(PI - ball.GetAngle());
        ball.SetSpeedX(BallVelocity * cos(ball.GetAngle()));
        ball.SetSpeedY(-1 * BallVelocity * sin(ball.GetAngle()));
    }
    if (ball.GetY() - ball.GetRadius() < 0) {
        ball.SetY(ball.GetRadius());
        ball.SetOldY(ball.GetY());
        ball.SetAngle(-1 * ball.GetAngle());
        ball.SetSpeedX(BallVelocity * cos(ball.GetAngle()));
        ball.SetSpeedY(-1 * BallVelocity * sin(ball.GetAngle()));
    }
    else if (ball.GetY() + ball.GetRadius() > GetScreenHeight()) {
        ball.SetY(GetScreenHeight() - ball.GetRadius());
        ball.SetOldY(ball.GetY());
        ball.SetFlag(false);
    }
    if (ball.GetFlag()) {
        ball.SetOldX(ball.GetX());
        ball.SetOldY(ball.GetY());
        ball.SetX(ball.GetX() + ball.GetSpeedX());
        ball.SetY(ball.GetY() + ball.GetSpeedY());
    }
}

//Draw Everything at every frame
void DrawEverything(const std::vector<Ball>& balls, const std::vector<std::vector<Box>>& boxes, const std::vector<PlusSign>& plusSigns ) {
    ClearBackground(BLACK);
    BeginDrawing();


    for (const auto& ball : balls) {
        DrawCircle(ball.GetX(), ball.GetY(), ball.GetRadius(), WHITE);
        std::string temp = std::to_string(ball.GetCount());
        const char* text = temp.c_str();
        int textWidth = MeasureText(text, 15);
        float textX = ball.GetX() - textWidth / 2;
        float textY = ball.GetY() - ball.GetRadius() + 1;
        DrawText(text, textX, textY, 15, RED);
    }
    for (const auto& vec : boxes) { 
        for (const auto& box : vec) {
            if (box.GetVisible()) {
                DrawRectangle(box.GetX(), box.GetY(), box.GetWidth(), box.GetHeight(), BLACK);
                DrawRectangleLines(box.GetX(), box.GetY(), box.GetWidth(), box.GetHeight(), RED);
                std::string temp = box.GetCountText();
                const char* text = temp.c_str();
                int textWidth = MeasureText(text, 20);
                float textX = box.GetWidth() / 2 + box.GetX() - textWidth / 2;
                float textY = box.GetHeight() / 2 + box.GetY() - 10;
                DrawText(text, textX, textY, 20, RED);
            }
        }
    }
    for (const auto& plusSign : plusSigns) {
        if (plusSign.Visible()) {
            DrawCircle(plusSign.GetX(), plusSign.GetY(), plusSign.GetRadius(), RED);
            int textWidth = MeasureText(plusSign.Text, 15);
            float textX = plusSign.GetX() - textWidth / 2;
            float textY = plusSign.GetY() - plusSign.GetRadius() + 1;
            DrawText(plusSign.Text, textX, textY, 15, WHITE);
        }
    }
    EndDrawing();
}

//When Left Click is pressed, this function is called to make the balls move
void MouseButtonPressed(const Vector2& MousePos, std::vector<Ball>& balls, const float Ball_Velocity) {
    
    for (auto& ball_ : balls) {
        ball_.SetAngle(ball_.CalculateAngle(MousePos));
        ball_.SetSpeedX(Ball_Velocity * cos(ball_.GetAngle()));
        ball_.SetSpeedY(Ball_Velocity * sin(ball_.GetAngle()) * -1);
        if (ball_.GetX() > MousePos.x) {
            ball_.SetSpeedX(-1 * ball_.GetSpeedX());
        }
    }
}

//Function for generating random number in range
int generate_random_number(int lhs, int rhs) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(lhs, rhs);
    return distribution(generator);
}

//Check if any box needs to be destroyed
void CheckBoxes(std::vector<std::vector<Box>>& boxes) {
    for (auto& vec : boxes) {
        for (auto& box : vec) {
            if (box.GetCount() == 0) box.SetVisible(false);
        }
    }
}

//Generate first line of boxes
void GenerateFirstLine(std::vector<std::vector<Box>>& boxes, int count, std::vector<PlusSign>& plusSigns) {
    int box_count = generate_random_number(2, 7);
    int is_here;
    int PlusSignSize = plusSigns.size();

    Box first(40, 10, 80, 80, count, true);
    std::vector<Box> current_line = { first };

    for (int i = 1; i < 8; ++i) {
        Box last = current_line[current_line.size() - 1];
        is_here = generate_random_number(0, 1);
        current_line.push_back(
            Box(last.GetX() + 90, last.GetY(), last.GetWidth(), last.GetHeight(),
                last.GetCount(), is_here)
        );
        if (is_here == 0) {
            if (plusSigns.size() - 1 == PlusSignSize) continue;
            PlusSign plusSign(last.GetX() + 80 + (last.GetWidth() / 2), last.GetY() + (last.GetHeight() / 2) - 10, 10);
            plusSigns.push_back(plusSign);
        }
    }
    boxes.push_back(current_line);
}

//Generate other lines of boxes
void GenerateBoxes(std::vector<std::vector<Box>>& boxes,int count, std::vector<PlusSign>& plusSigns) {
 
    for (auto& vec: boxes) {
        for (auto& box : vec) {
            box.SetY(box.GetY() + box.GetHeight() + 10);
        }
    }
    for (auto& plusSign : plusSigns) {
        plusSign.SetY(plusSign.GetY() + boxes[0][0].GetHeight() + 10);
    }
    GenerateFirstLine(boxes, count, plusSigns);
    
}

//When game is ended
bool GameOver(const std::vector<std::vector<Box>>& boxes) {
    for (const auto& vec: boxes) {
        for (const auto& box : vec) {
            if ((box.GetVisible()) &&
                 box.GetHeight() + box.GetY() + 1 > GetScreenHeight()) {
                return true;
            }
        }
    }
    return false;
}

//Calculateing the count of the balls that are at the same position
void CalculateCurrentBallsCount(const std::vector<Ball>& balls, Ball& ball) {
    int count = 0;

    for (auto& ball_ : balls) {
        if (ball_.GetX() == ball.GetX() && ball_.GetY() == ball.GetY()) {
            ++count;
        }
    }
    ball.SetCount(count);
}

//When every ball is at the bottom of the screen, collect them at the one place
void CheckBallsPosition(std::vector<Ball>& balls) {
    if (balls[0].GetY() + balls[0].GetRadius() >= GetScreenHeight()) {
        for (auto& ball : balls) {
            if (ball.GetY() + ball.GetRadius() >= GetScreenHeight()) {
                ball.SetX(balls[0].GetX());
            }
        }
    }
}

//When any ball touches the bottom of the screen, it's id is returned
int GetBallIndexIfTouched(std::vector<Ball>& balls) {
    for (int i = 0; i < balls.size(); ++i) {
        if (balls[i].GetY() + balls[i].GetRadius() >= GetScreenHeight()) {
            return i;
        }
    }
    return -1;
}

//Checking if the plus sign is collised with ant ball
int CheckPlusSignCollected(const std::vector<Ball>& balls, std::vector<PlusSign>& plusSigns) {
    for (const auto& ball : balls) {
        for (int i = 0; i < plusSigns.size(); ++i) {
            if (plusSigns[i].Visible()) {
                float distanceX = plusSigns[i].GetX() - ball.GetX();
                float distanceY = plusSigns[i].GetY() - ball.GetY();
                float sumRadii = plusSigns[i].GetRadius() + ball.GetRadius();
                float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

                if (distanceSquared <= (sumRadii * sumRadii)) {
                    return i;
                }
            }
        }
    }

    return -1;
}

//if CheckPlusSignCollected(), then the plus sign needs to be destroyed
void ResolvePlusSignCollected(std::vector<PlusSign>& plusSigns, int index) {
    plusSigns[index].SetVisibility(false);
}
