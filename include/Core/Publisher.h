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
#include <iostream>

#include <SFML/Network.hpp>

namespace Sole::Core {
    class Subscriber;

    class Publisher {
        public:
            Publisher() = default;

            ~Publisher() = default;

            Publisher(const Publisher &other);

            Publisher(Publisher &&other) noexcept;
            
            auto operator=(const Publisher &other) -> Publisher&;

            auto operator=(Publisher &&other) noexcept -> Publisher&;

            template <typename EventType, EventType Event>
            inline auto Subscribe(unsigned short int udp_port) -> void {
                auto event = std::find_if(m_events.begin(), m_events.end(), [](const auto &event) {
                    return std::any_cast<EventType>(event.first) == Event;
                });
                if (event != m_events.end()) {
                    event->second.push_back(udp_port);
                }
                else {
                    m_events.emplace_back(Event, std::initializer_list<unsigned short int>{udp_port});
                }
            }

            template <typename EventType, EventType EventData, typename EventDataType>
            inline auto Publish(EventDataType event_data) -> void {
                auto event = std::find_if(m_events.begin(), m_events.end(), [](const auto &event) {
                    return std::any_cast<EventType>(event.first) == EventData;
                });
                if (event != m_events.end()) {
                    for (const auto &subscriber_port : event->second) {
                        sf::Packet packet;
                        packet << EventData;
                        m_publisher_socket.send(packet, sf::IpAddress::LocalHost, subscriber_port);
                    }
                }
            }

            template <typename EventType, typename EventDataType>
            inline auto Publish(EventType event, EventDataType event_data) -> void {
                auto event_iter = std::find_if(m_events.begin(), m_events.end(), [c_event = event](const auto &event) {
                    return std::any_cast<EventType>(event.first) == c_event;
                });
                if (event_iter != m_events.end()) {
                    for (const auto &subscriber_port : event_iter->second) {
                        sf::Packet packet;
                        packet << event;
                        packet << event_data;
                        m_publisher_socket.send(packet, sf::IpAddress::LocalHost, subscriber_port);
                    }
                }
            }

            template <typename EventType, EventType Event>
            inline auto AddSubscribedPort(unsigned short int udp_port) -> void {
                auto event_iter = std::find_if(m_events.begin(), m_events.end(), [](const auto &event) {
                    if (event.first.type() == typeid(EventType)) {
                        return std::any_cast<EventType>(event.first) == Event;
                    }
                    return false;
                });
                if (event_iter != m_events.end()) {
                    auto subscriber_port_iter = std::find(event_iter->second.begin(), event_iter->second.end(), udp_port);
                    std::cout << "asasd" << std::endl;
                    if (subscriber_port_iter == event_iter->second.end()) {
                        event_iter->second.push_back(udp_port);
                        std::cout << "asdasd" << std::endl;
                    }
                }
                else {
                    m_events.emplace_back(std::make_any<EventType>(Event), std::initializer_list<unsigned short int>{udp_port});
                }
            }
        private:
            sf::UdpSocket m_publisher_socket;
            
            std::vector<std::pair<std::any, std::list<unsigned short int>>> m_events;
    };
} // namespace Sole::Core
