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

namespace Sole::Core {
    class Game final : public State {
        public:
            explicit Game(sf::RenderWindow &render_window);

            ~Game() final = default;

            Game(const Game &other) = default;

            Game(Game &&other) noexcept = default;

            auto operator=(const Game &other) -> Game& = default;

            auto operator=(Game &&other) noexcept -> Game& = default;

            auto Update(float delta_time) -> void final;

            auto Render(sf::RenderTarget &render_target) -> void final;

            auto Render() -> void final;

            auto EndState() -> void final;

        private:

    };
} // namespace Sole::Core
