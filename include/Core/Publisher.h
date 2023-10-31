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
#include <list>
#include <tuple>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>

namespace Sole::Core {
    class Subscriber;

    class Publisher {
        public:
            Publisher() = default;

            ~Publisher() = default;

            Publisher(const Publisher &other) = default;

            Publisher(Publisher &&other) noexcept = default;
            
            auto operator=(const Publisher &other) -> Publisher& = default;

            auto operator=(Publisher &&other) -> Publisher& = default;

            template <typename EventType, EventType Event>
            inline auto Subscribe(Subscriber &subscriber) -> void {
                auto event = std::find_if(m_events.begin(), m_events.end(), [](const auto &event) {
                    return std::any_cast<EventType>(event.first) == Event;
                });
                if (event != m_events.end()) {
                    event->second.push_back(&subscriber);
                }
                else {
                    m_events.emplace_back(Event, std::initializer_list<Subscriber*>{&subscriber});
                }
            }

            template<typename EventType>
            inline auto UnsubscribeEvent(Subscriber &subscriber) -> void {
                auto event = std::find(m_events.begin(), m_events.end(), typeid(EventType));
                if (event != m_events.end()) {
                    auto sub = std::find(event->second.begin(), event->second.end(), subscriber);
                    if (sub != event->second.end()) {
                        event->second.remove(*sub);
                    }
                }
            }

            auto Unsubscribe(Subscriber &subscriber) -> void;

            template <typename EventType, EventType EventData, typename EventDataType>
            inline auto Publish(EventDataType event_data) -> void {
                auto event = std::find_if(m_events.begin(), m_events.end(), [](const auto &event) {
                    return std::any_cast<EventType>(event.first) == EventData;
                });
                if (event != m_events.end()) {
                    for (const auto &subscriber : event->second) {
                        subscriber->template Notify<EventType>(EventData, event_data);
                    }
                }
            }

            template <typename EventType, typename EventDataType>
            inline auto Publish(EventType event, EventDataType event_data) -> void {
                auto event_iter = std::find_if(m_events.begin(), m_events.end(), [c_event = event](const auto &event) {
                    return std::any_cast<EventType>(event.first) == c_event;
                });
                if (event_iter != m_events.end()) {
                    for (const auto &subscriber : event_iter->second) {
                        subscriber->template Notify<EventType>(event, event_data);
                    }
                }
            }
        private:
            
            std::vector<std::pair<std::any, std::list<Subscriber*>>> m_events;
    };
} // namespace Sole::Core
