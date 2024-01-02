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

#include "Sole.h"

namespace Sole {
    Sole::Sole() :
        m_delta_time(),
        m_sfml_event()
    {
    }

    auto Sole::UpdateDeltaTime() -> void {
        m_delta_time = m_sfml_clock.restart().asSeconds();
    }

    auto Sole::Update() -> void {
        // SFML Events
        while (m_sfml_window.pollEvent(m_sfml_event)) {
            if (m_sfml_event.type == sf::Event::Closed) {
                m_sfml_window.close();
            }
        }

        if (!m_state_stack.empty()) {
            if (m_state_stack.top().IsFinished()) {
                m_state_stack.top().EndState();
                m_state_stack.pop();
            }
        }
        
        if (!m_state_stack.empty()) {
            m_state_stack.top().Update(m_delta_time);
        }
    }

    auto Sole::Render() -> void {
        m_sfml_window.clear();

        if (!m_state_stack.empty()) {
            m_state_stack.top().Render(m_sfml_window);
        }

        m_sfml_window.display();
    }

    auto Sole::Run() -> void {
        m_sfml_window.create(sf::VideoMode(800, 600), "Sole: Survive");
        while (m_sfml_window.isOpen()) {
            Update();
        }
    }
} // namespace Sole
