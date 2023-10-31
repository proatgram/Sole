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

#include <SFML/Graphics.hpp>

namespace Sole::Core {
    class State {
        public:
            explicit State(sf::RenderWindow &render_window);

            virtual ~State() = default;

            State(const State &other) = default;

            State(State &&other) noexcept = default;

            auto operator=(const State &other) -> State& = default;

            auto operator=(State &&other) -> State& = default;

            virtual auto Update(float delta_time) -> void = 0;

            virtual auto Render(sf::RenderTarget &target) -> void = 0;

            virtual auto Render() -> void = 0;

            virtual auto IsFinished() -> bool;

            virtual auto EndState() -> void = 0;

        protected:
            bool m_state_finished;
            // We do not own this pointer, the resource that passes it in does.
            // Therefor, the resource that created this object must destroy it.
            sf::RenderWindow *m_sfml_window;

            std::vector<sf::Texture> m_sfml_textures;

    };
} // namespace Sole::Core
