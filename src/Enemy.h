#pragma once
#include "raylib.h"
#include "Player.h"

// ДОГОВОР ИНТЕРФЕЙСОВ: названия методов менять нельзя.
// Файл ведёт участник 3 (враги), внутри можно дописывать всё что нужно.

class EnemyManager {
public:
    EnemyManager();
    void Update(float dt, float difficulty);
    void Draw() const;
    // Возвращает очки за сбитых врагов, при столкновении с кораблём отнимает жизнь
    int CheckCollisions(Player& player);
    void Reset();
};