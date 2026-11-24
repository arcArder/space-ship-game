#include "Enemy.h"

// ЗАГЛУШКА: настоящую реализацию пишет участник 3.

EnemyManager::EnemyManager() {}

void EnemyManager::Update(float /*dt*/, float /*difficulty*/) {}

void EnemyManager::Draw() const {}

int EnemyManager::CheckCollisions(Player& /*player*/) {
    return 0;
}

void EnemyManager::Reset() {}