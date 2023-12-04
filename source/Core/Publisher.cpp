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

#include "Core/Publisher.h"

namespace Sole::Core {
    Publisher::Publisher(const Publisher &other) :
        m_events(other.m_events)
    {

    }

    Publisher::Publisher(Publisher &&other) noexcept :
        m_events(std::move(other.m_events))
    {

    }

    auto Publisher::operator=(const Publisher &other) -> Publisher& {
        if (&other == this) {
            return *this;
        }

        m_events = other.m_events;
        return *this;
    }

    auto Publisher::operator=(Publisher &&other) noexcept -> Publisher& {
        m_events = std::move(other.m_events);
        return *this;
    }
} // namespace Sole::Core
