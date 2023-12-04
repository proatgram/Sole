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
#include <map>
#include <string>
#include <thread>
#include <atomic>
#include <mutex>
#include <functional>

#include <iostream>

#include "Core/Publisher.h"
#include "Core/Event.h"

namespace Sole::Core {
    class Subscriber {
        public:
            Subscriber();

            ~Subscriber();

            Subscriber(const Subscriber &other) = delete;

            Subscriber(Subscriber &&other) noexcept;
            
            auto operator=(const Subscriber &other) -> Subscriber& = delete;

            auto operator=(Subscriber &&other) noexcept -> Subscriber&;

            auto operator==(const Subscriber &other) const -> bool;

            auto operator!=(const Subscriber &other) const -> bool;

            auto GetId() const -> int;

            auto GetName() const -> const std::string&;

            auto GetSubscribedEvents() const -> const std::list<std::any>&;

            template <typename EventType, EventType Event>
            inline auto Susbcribe(Publisher &publisher) -> void {
                auto event_iter = std::find_if(m_subscribed_events.begin(), m_subscribed_events.end(), [](const std::any &event) {
                    if (event.type() == typeid(Event)) {
                        return std::any_cast<EventType>(event) == Event;
                    }
                    return false;
                });
                if (event_iter == m_subscribed_events.end()) {
                    m_subscribed_events.push_back(std::make_any<EventType>(Event));
                    publisher.template AddSubscribedPort<EventType, Event>(m_subscriber_socket.getLocalPort());
                }
            }

            template <typename EventType, EventType Event>
            inline auto AddEventCallback(const std::function<void(std::any)> &callback) -> void {
                m_event_callbacks.insert_or_assign(Event, callback);
            }

            auto GetListeningPort() const -> unsigned short int;
        private:
            auto UpdateEvents() -> void;

            int m_id{};
            std::string m_subscriber_name;

            std::atomic_bool m_running{true};

            sf::UdpSocket m_subscriber_socket;
            std::thread m_worker_thread;

            std::list<std::any> m_subscribed_events;
            std::map<std::any, std::function<void(std::any)>> m_event_callbacks;
    };
} // namespace Sole::Core
