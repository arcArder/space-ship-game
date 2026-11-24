#include "Player.h"

// ЗАГЛУШКА: настоящую реализацию пишет участник 2.

Rectangle Bullet::GetBounds() const {
    return Rectangle{pos.x, pos.y, 4.0f, 10.0f};
}

Player::Player() : lives(3), energy(100.0f), pos_{400.0f, 520.0f} {}

void Player::Update(float /*dt*/) {}

void Player::Draw() const {}

Rectangle Player::GetBounds() const {
    return Rectangle{pos_.x, pos_.y, 40.0f, 40.0f};
}

std::vector<Bullet>& Player::GetBullets() {
    return bullets_;
}

void Player::Reset() {
    lives = 3;
    energy = 100.0f;
    pos_ = Vector2{400.0f, 520.0f};
    bullets_.clear();
}