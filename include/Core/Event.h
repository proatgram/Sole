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

#include <any>

namespace Sole::Core {
    class Event {
        public:
            Event() = default;

            virtual ~Event() = default;

            Event(const Event& other) = default;

            Event(Event &&other) noexcept = default;

            auto operator=(const Event& other) -> Event& = default;

            auto operator=(Event &&other) noexcept -> Event& = default;

            virtual auto operator<(const Event &other) const -> bool = 0;

            virtual auto operator==(const Event &other) const -> bool = 0;

            virtual auto operator!=(const Event &other) const -> bool = 0;

            virtual auto Compare(const Event &other) const -> bool = 0;

            virtual auto Compare(const std::any &type) const -> bool = 0;

            virtual auto Get() const -> std::any = 0;
        protected:
            inline auto TypeCheck(const Event &other) const -> bool {
                return Get().type() == other.Get().type();
            }

            inline auto TypeCheck(const std::any &type) const -> bool {
                return Get().type() == type.type();
            }
    };
} // namespace Sole::Core
