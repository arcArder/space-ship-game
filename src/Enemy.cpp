#include "Enemy.h"

#include <algorithm>
#include "Player.h"

Rectangle Enemy::GetBounds() const {
    return Rectangle{
        pos.x - radius,
        pos.y - radius,
        radius * 2.0f,
        radius * 2.0f
    };
}

EnemyManager::EnemyManager() {
    Reset();
}

void EnemyManager::Reset() {
    enemies_.clear();

    Enemy firstEnemy;
    firstEnemy.kind = EnemyKind::Asteroid;
    firstEnemy.radius = 22.0f;
    firstEnemy.pos = {static_cast<float>(SCREEN_WIDTH) * 0.5f, -firstEnemy.radius};
    firstEnemy.vel = {0.0f, 130.0f};
    firstEnemy.scoreValue = 100;
    firstEnemy.active = true;
    enemies_.push_back(firstEnemy);
}

void EnemyManager::Update(float dt, float difficulty) {
    if (dt <= 0.0f) {
        return;
    }

    const float safeDt = std::min(dt, 0.05f);
    const float safeDiff = std::max(0.1f, difficulty);

    for (Enemy& enemy : enemies_) {
        if (!enemy.active) {
            continue;
        }
        enemy.pos.y += enemy.vel.y * safeDiff * safeDt;
    }
}

void EnemyManager::Draw() const {
    for (const Enemy& enemy : enemies_) {
        if (!enemy.active) {
            continue;
        }
        DrawCircleV(enemy.pos, enemy.radius, GRAY);
    }
}

int EnemyManager::CheckCollisions(Player& player) {
    (void)player;
    return 0;
}
