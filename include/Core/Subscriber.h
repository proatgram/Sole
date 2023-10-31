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
#include <string>

#include <iostream>

namespace Sole::Core {
    class Subscriber {
        public:
            Subscriber() = default;

            ~Subscriber() = default;

            Subscriber(const Subscriber &other) = default;

            Subscriber(Subscriber &&other) noexcept = default;
            
            auto operator=(const Subscriber &other) -> Subscriber& = default;

            auto operator=(Subscriber &&other) -> Subscriber& = default;

            auto operator==(const Subscriber &other) const -> bool;

            auto operator!=(const Subscriber &other) const -> bool;

            auto GetId() const -> int;

            auto GetName() const -> const std::string&;

            auto GetSubscribedEvents() const -> const std::list<std::any>&;

            template <typename EventType, typename EventTypeData>
            inline auto Notify(EventType event, EventTypeData event_data) -> void {
                std::cout << typeid(event).name() << std::endl;
            }
        private:
            int m_id{};
            std::string m_subscriber_name;

            std::list<std::any> m_subscribed_events;
    };
} // namespace Sole::Core