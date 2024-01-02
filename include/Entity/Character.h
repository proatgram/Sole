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

#include "Entity/Entity.h"

#include <tuple>

namespace Sole::Entity {
    class Character : public Entity {
        public:
            Character(double position_x, double position_y, const std::string &name, int character_id);

            Character(const std::string &name, int character_id);

            ~Character() override = default;

            Character(const Character &other) = default;

            Character(Character &&other) noexcept = default;

            auto operator=(const Character &other) -> Character& = default;

            auto operator=(Character &&other) noexcept -> Character& = default;

            auto GetPosition() const -> std::pair<double, double>;

            auto MoveUp() -> void;

            auto MoveDown() -> void;

            auto MoveLeft() -> void;

            auto MoveRight() -> void;

        protected:
            double m_position_x;
            double m_position_y;
            double m_speed;

            int m_character_id;

            std::string m_name;
    };
} // namespace Sole::Entity
