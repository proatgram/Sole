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

#include "Core/Subscriber.h"

namespace Sole::Core {
    auto Subscriber::operator==(const Subscriber &other) const -> bool {
        return m_id == other.m_id;
    }

    auto Subscriber::operator!=(const Subscriber &other) const -> bool {
        return !operator==(other);
    }

    auto Subscriber::GetId() const -> int {
        return m_id;
    }

    auto Subscriber::GetName() const -> const std::string& {
        return m_subscriber_name;
    }

    auto Subscriber::GetSubscribedEvents() const -> const std::list<std::any>& {
        return m_subscribed_events;
    }
} // namespace Sole::Core
