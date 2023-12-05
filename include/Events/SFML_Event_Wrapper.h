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

#include <SFML/Window/Event.hpp>

#include "Core/Event.h"

namespace Sole::Events {
    class SFMLEventWrapper final : public Sole::Core::Event {
        public:
            SFMLEventWrapper() = delete;

            ~SFMLEventWrapper() final = default;

            SFMLEventWrapper(const SFMLEventWrapper &other) = default;

            SFMLEventWrapper(SFMLEventWrapper &&other) noexcept = default;

            auto operator=(const SFMLEventWrapper &other) -> SFMLEventWrapper& = default;

            auto operator=(SFMLEventWrapper &&other) noexcept -> SFMLEventWrapper& = default;

            auto operator<(const Event &other) const -> bool final;

            auto operator==(const Event &other) const -> bool final;

            auto operator!=(const Event &other) const -> bool final;

            auto Compare(const Event &other) const -> bool final;

            auto Compare(const std::any &type) const -> bool final;

            auto Get() const -> std::any final;
        private:
            sf::Event::EventType m_event;
    };
} // namespace Sole::Events
