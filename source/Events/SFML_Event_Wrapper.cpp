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

#include "Events/SFML_Event_Wrapper.h"

namespace Sole::Events {
    auto SFMLEventWrapper::Compare(const Event &other) const -> bool {
        // If the type in the other `Event` and this aren't the same type
        // Then we know for a fact the values are not equal.
        if (!TypeCheck(other)) {
            return false;
        }

        // Simple comparison for simple enum
        return m_event == std::any_cast<decltype(m_event)>(other.Get());
    }

    auto SFMLEventWrapper::Compare(const std::any &type) const -> bool {
        if (!TypeCheck(type)) {
            return false;
        }
        
        return m_event == std::any_cast<decltype(m_event)>(type);
    }

    auto SFMLEventWrapper::operator<(const Event &other) const -> bool {
        if(!TypeCheck(other)) {
            return false;
        }

        return static_cast<int>(m_event) < static_cast<int>(std::any_cast<decltype(m_event)>(other.Get()));
    }

    auto SFMLEventWrapper::operator==(const Event &other) const -> bool {
        return Compare(other.Get());
    }

    auto SFMLEventWrapper::operator!=(const Event &other) const -> bool {
        return !Compare(other.Get());
    }

    auto SFMLEventWrapper::Get() const -> std::any {
        return m_event;
    }
} // namespace Sole::Events
