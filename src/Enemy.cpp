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
    spawnTimer_ = 0.5f;
}

void EnemyManager::SpawnEnemy() {
    Enemy enemy;
    enemy.kind = (GetRandomValue(0, 1) == 0) ? EnemyKind::Asteroid : EnemyKind::Ship;
    enemy.radius = (enemy.kind == EnemyKind::Asteroid) ? 22.0f : 18.0f;

    const int minX = static_cast<int>(enemy.radius) + 8;
    const int maxX = SCREEN_WIDTH - static_cast<int>(enemy.radius) - 8;
    const float spawnX = static_cast<float>(GetRandomValue(minX, std::max(minX, maxX)));

    enemy.pos = {spawnX, -enemy.radius};
    enemy.vel = {0.0f, (enemy.kind == EnemyKind::Asteroid) ? 130.0f : 165.0f};
    enemy.scoreValue = (enemy.kind == EnemyKind::Asteroid) ? 100 : 150;
    enemy.active = true;

    enemies_.push_back(enemy);
}

void EnemyManager::Update(float dt, float difficulty) {
    if (dt <= 0.0f) {
        return;
    }

    const float safeDt = std::min(dt, 0.05f);
    const float safeDiff = std::max(0.1f, difficulty);

    spawnTimer_ -= safeDt;
    if (spawnTimer_ <= 0.0f) {
        SpawnEnemy();
        spawnTimer_ = 1.0f;
    }

    for (Enemy& enemy : enemies_) {
        if (!enemy.active) {
            continue;
        }
        enemy.pos.y += enemy.vel.y * safeDiff * safeDt;
        enemy.pos.x = std::clamp(
            enemy.pos.x,
            enemy.radius,
            static_cast<float>(SCREEN_WIDTH) - enemy.radius
        );

        if (enemy.pos.y - enemy.radius > static_cast<float>(SCREEN_HEIGHT)) {
            enemy.active = false;
        }
    }

    enemies_.erase(
        std::remove_if(enemies_.begin(), enemies_.end(), [](const Enemy& e) {
            return !e.active;
        }),
        enemies_.end()
    );
}

void EnemyManager::Draw() const {
    for (const Enemy& enemy : enemies_) {
        if (!enemy.active) {
            continue;
        }

        if (enemy.kind == EnemyKind::Asteroid) {
            DrawPoly(enemy.pos, 7, enemy.radius, 0.0f, GRAY);
            DrawPolyLines(enemy.pos, 7, enemy.radius, 0.0f, LIGHTGRAY);
        } else {
            Vector2 nose{enemy.pos.x, enemy.pos.y + enemy.radius};
            Vector2 leftWing{enemy.pos.x - enemy.radius, enemy.pos.y - enemy.radius};
            Vector2 rightWing{enemy.pos.x + enemy.radius, enemy.pos.y - enemy.radius};
            DrawTriangle(nose, leftWing, rightWing, MAROON);
        }
    }
}

int EnemyManager::CheckCollisions(Player& player) {
    (void)player;
    return 0;
}
