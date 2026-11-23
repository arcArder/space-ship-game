#pragma once

#include <vector>
#include "raylib.h"

class Player;

enum class EnemyKind {
    Asteroid,
    Ship
};

struct Enemy {
    Vector2 pos{0.0f, 0.0f};
    Vector2 vel{0.0f, 130.0f};
    float radius = 20.0f;
    int scoreValue = 100;
    bool active = true;
    EnemyKind kind = EnemyKind::Asteroid;

    Rectangle GetBounds() const;
};

class EnemyManager {
public:
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 600;

    EnemyManager();
    ~EnemyManager() = default;

    void Update(float dt, float difficulty);
    void Draw() const;
    int CheckCollisions(Player& player);
    void Reset();

private:
    std::vector<Enemy> enemies_;
};
