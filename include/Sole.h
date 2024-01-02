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

#include "Core/State.h"

#include <vector>
#include <stack>

#include <SFML/Window.hpp>

namespace Sole {
    class Sole {
        public:
            Sole();
            
            ~Sole() = default;

            Sole(const Sole &other) = delete;

            Sole(Sole &&other) = delete;

            auto operator=(const Sole& other) -> Sole& = delete;

            auto operator=(Sole &&other) -> Sole& = delete;

            auto UpdateDeltaTime() -> void;

            auto Run() -> void;

            auto Update() -> void;

            auto Render() -> void;
            
        private:
            float m_delta_time;

            sf::RenderWindow m_sfml_window;
            sf::Event m_sfml_event;
            sf::Clock m_sfml_clock;

            std::stack<Core::State> m_state_stack;
    };
} // namespace Sole
