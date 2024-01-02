/*
 *  An adventure game set in a Sci-Fi world where you have to fight to survive.
 *  Copyright (C) 2023  Timothy Hutchins
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "Entity/Character.h"

namespace Sole::Entity {
    class Player final : public Sole::Entity::Character {
        public:
            Player(double position_x, double position_y, const std::string &name, int player_id);

            ~Player() final = default;

            Player(const Player &other) = default;

            Player(Player &&other) noexcept = default;

            auto operator=(const Player &other) -> Player& = default;

            auto operator=(Player &&other) noexcept -> Player& = default;

            auto GetExperiencePoints() const -> int;

            auto UpdatePosition(double position_x, double position_y) -> void;

            auto Update() -> void final;

        private:
            int m_experience_points;
    };
} // namespace Sole::Entity
