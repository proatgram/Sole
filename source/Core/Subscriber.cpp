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
    Subscriber::Subscriber() :
        m_worker_thread([this]() {UpdateEvents();})
    {
        m_subscriber_socket.bind(sf::Socket::AnyPort, sf::IpAddress::LocalHost);
    }

    Subscriber::~Subscriber() {
        m_running.store(false);
        m_worker_thread.join();
    }

    Subscriber::Subscriber(Subscriber &&other) noexcept :
        m_id(other.m_id),
        m_subscriber_name(std::move(other.m_subscriber_name)),
        m_worker_thread([this]() {UpdateEvents();}),
        m_subscribed_events(std::move(other.m_subscribed_events))
    {

    }

    auto Subscriber::operator=(Subscriber &&other) noexcept -> Subscriber& {
        m_id = other.m_id;
        m_subscriber_name = std::move(other.m_subscriber_name);
        m_worker_thread = std::thread([this]() {UpdateEvents();});
        m_subscribed_events = std::move(other.m_subscribed_events);

        return *this;
    }

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

    auto Subscriber::UpdateEvents() -> void {
        sf::Packet packet;
        sf::IpAddress ip_address;
        unsigned short int port;
        while(m_running.load()) {
            if (m_subscriber_socket.receive(packet, ip_address, port) == sf::Socket::Done) {
                std::any event;
                
                auto callback_iter = std::find_if(m_event_callbacks.begin(), m_event_callbacks.end(), [&event](const auto &container) -> bool {
                    return container.first->Compare(event);
                });

                if (callback_iter == m_event_callbacks.end()) {
                    break;
                }

                callback_iter->second(callback_iter->first->Get());
            }
        }
    }
} // namespace Sole::Core
