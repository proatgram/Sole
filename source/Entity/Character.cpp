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

#include "Entity/Character.h"

namespace Sole::Entity {
    Character::Character(double position_x, double position_y, const std::string &name, int character_id) :
        m_position_x(position_x),
        m_position_y(position_y),
        m_speed(),
        m_character_id(character_id),
        m_name(name)
    {

    }

    Character::Character(const std::string &name, int character_id) :
        m_position_x(),
        m_position_y(),
        m_speed(),
        m_character_id(character_id),
        m_name(name)
    {

    }

    auto Character::GetPosition() const -> std::pair<double, double> {
        return {m_position_x, m_position_y};
    }
} // namespace Sole::Entity
