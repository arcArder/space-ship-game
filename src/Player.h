#pragma once
#include <vector>
#include "raylib.h"

// ДОГОВОР ИНТЕРФЕЙСОВ: названия методов и полей менять нельзя.
// Файл ведёт участник 2 (игрок), внутри можно дописывать всё что нужно.

struct Bullet {
    Vector2 pos{0, 0};
    Vector2 vel{0, 0};
    bool active = false;
    Rectangle GetBounds() const;
};

class Player {
public:
    Player();
    void Update(float dt);
    void Draw() const;
    Rectangle GetBounds() const;
    std::vector<Bullet>& GetBullets();
    void Reset();

    int lives;
    float energy;

private:
    Vector2 pos_;
    std::vector<Bullet> bullets_;
};