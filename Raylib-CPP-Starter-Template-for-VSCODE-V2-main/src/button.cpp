#include"button.hpp"

Button::Button(const char *imagePath, Vector2 imagePos){
    texture = LoadTexture(imagePath);
    pos = imagePos;
}


Button::~Button(){
    UnloadTexture(texture);
}

void Button::Draw(){
    DrawTextureV(texture,pos,WHITE);
}