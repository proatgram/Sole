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
#include "Core/Subscriber.h"

namespace Sole::Core {
    auto Publisher::Unsubscribe(Subscriber &subscriber) -> void {
        for (const auto &subed_event : subscriber.GetSubscribedEvents()) {
            auto event_iter = std::find_if(m_events.begin(), m_events.end(), [s_event = subed_event](const auto &event) {
                return s_event.type() == event.first.type();
            });
            if (event_iter != m_events.end()) {
                event_iter->second.erase(std::remove_if(event_iter->second.begin(), event_iter->second.end(), [c_subscriber = subscriber](const Subscriber *subscriber) {
                    return c_subscriber == *subscriber;
                }), event_iter->second.end());
            }
        }
    }
} // namespace Sole::Core
