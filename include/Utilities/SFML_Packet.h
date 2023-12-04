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

#include <SFML/Network/Packet.hpp>
#include <SFML/Window/Event.hpp>

/*
 * This file aims to add the ability to put `sf::Event`'s and their specific data
 * into an `sf::Packet` for use with Event Publishe Subscribers
 */

// NOLINTBEGIN(cppcoreguidelines-pro-type-union-access)

namespace sf {
    inline auto operator<<(sf::Packet &packet, const sf::Event &event) -> sf::Packet& {
        packet << event.type;
        switch (event.type) {
            case sf::Event::EventType::Resized: {
                packet << event.size.width << event.size.height;
                break;
            }
            case sf::Event::EventType::TextEntered: {
                packet << event.text.unicode;
                break;
            }
            case sf::Event::EventType::KeyPressed:
            case sf::Event::EventType::KeyReleased: {
                packet << event.key.alt << event.key.code
                                        << event.key.system
                                        << event.key.shift
                                        << event.key.control
                                        << event.key.scancode;
                break;
            }
            case sf::Event::EventType::MouseWheelScrolled: {
                packet << event.mouseWheelScroll.x << event.mouseWheelScroll.y
                                                   << event.mouseWheelScroll.wheel
                                                   << event.mouseWheelScroll.delta;
                break;
            }
            case sf::Event::Event::MouseWheelMoved: {
                packet << event.mouseWheel.x << event.mouseWheel.y
                                             << event.mouseWheel.delta;
                break;
            }
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased: {
                packet << event.mouseButton.x << event.mouseButton.y
                                              << event.mouseButton.button;
                break;
            }
            case sf::Event::EventType::MouseMoved: {
                packet << event.mouseMove.x << event.mouseMove.y;
                break;
            }
            case sf::Event::EventType::JoystickButtonPressed:
            case sf::Event::EventType::JoystickButtonReleased: {
                packet << event.joystickButton.button << event.joystickButton.joystickId;
                break;
            }
            case sf::Event::EventType::JoystickMoved: {
                packet << event.joystickMove.position << event.joystickMove.axis
                                                      << event.joystickMove.joystickId;
                break;
            }
            case sf::Event::JoystickConnected:
            case sf::Event::JoystickDisconnected: {
                packet << event.joystickConnect.joystickId;
                break;
            }
            case sf::Event::EventType::TouchBegan:
            case sf::Event::EventType::TouchMoved:
            case sf::Event::EventType::TouchEnded: {
                packet << event.touch.x << event.touch.y
                                        << event.touch.finger;
                break;
            }
            case sf::Event::EventType::SensorChanged: {
                packet << event.sensor.x << event.sensor.y
                                         << event.sensor.z
                                         << event.sensor.type;
                break;
            }
            case sf::Event::EventType::Closed:
            case sf::Event::EventType::LostFocus:
            case sf::Event::EventType::GainedFocus:
            case sf::Event::EventType::MouseEntered:
            case sf::Event::EventType::MouseLeft:
            case sf::Event::EventType::Count:
                break;
        }
        return packet;
    }

    inline auto operator>>(sf::Packet &packet, sf::Event &event) -> sf::Packet& {
        int type_int = 0;
        packet >> type_int;
        event.type = static_cast<sf::Event::EventType>(type_int);
        return packet;

        switch (event.type) {
            case sf::Event::EventType::Resized: {
                packet >> event.size.width >> event.size.height;
                break;
            }
            case sf::Event::EventType::TextEntered:
                packet >> event.text.unicode;
                break;
            case sf::Event::EventType::KeyPressed:
            case sf::Event::EventType::KeyReleased: {
                int key_code = 0;
                int key_scancode = 0;
                packet >> event.key.alt >> key_code
                                        >> event.key.system
                                        >> event.key.shift
                                        >> event.key.control
                                        >> key_scancode;
                event.key.code = static_cast<sf::Keyboard::Key>(key_code);
                event.key.scancode = static_cast<sf::Keyboard::Scancode>(key_scancode);
                break;
            }
            case sf::Event::EventType::MouseWheelScrolled: {
                int mouse_wheel = 0;
                packet >> event.mouseWheelScroll.x >> event.mouseWheelScroll.y
                                                   >> mouse_wheel
                                                   >> event.mouseWheelScroll.delta;
                event.mouseWheelScroll.wheel = static_cast<sf::Mouse::Wheel>(mouse_wheel);
                break;
            }
            case sf::Event::Event::MouseWheelMoved: {
                packet << event.mouseWheel.x >> event.mouseWheel.y
                                             >> event.mouseWheel.delta;
                break;
            }
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased: {
                int mouse_button = 0;
                packet >> event.mouseButton.x >> event.mouseButton.y
                                              >> mouse_button;
                event.mouseButton.button = static_cast<sf::Mouse::Button>(mouse_button);
                break;
            }
            case sf::Event::EventType::MouseMoved: {
                packet >> event.mouseMove.x >> event.mouseMove.y;
                break;
            }
            case sf::Event::EventType::JoystickButtonPressed:
            case sf::Event::EventType::JoystickButtonReleased: {
                packet >> event.joystickButton.button >> event.joystickButton.joystickId;
                break;
            }
            case sf::Event::EventType::JoystickMoved: {
                int joystick_axis = 0;
                packet >> event.joystickMove.position >> joystick_axis
                                                      >> event.joystickMove.joystickId;
                event.joystickMove.axis = static_cast<sf::Joystick::Axis>(joystick_axis);
                break;
            }
            case sf::Event::JoystickConnected:
            case sf::Event::JoystickDisconnected: {
                packet >> event.joystickConnect.joystickId;
                break;
            }
            case sf::Event::EventType::TouchBegan:
            case sf::Event::EventType::TouchMoved:
            case sf::Event::EventType::TouchEnded: {
                packet >> event.touch.x >> event.touch.y
                                        >> event.touch.finger;
                break;
            }
            case sf::Event::EventType::SensorChanged: {
                int sensor_type = 0;
                packet << event.sensor.x >> event.sensor.y
                                         >> event.sensor.z
                                         >> sensor_type;
                event.sensor.type = static_cast<sf::Sensor::Type>(sensor_type);
                break;
            }
            case sf::Event::EventType::Closed:
            case sf::Event::EventType::LostFocus:
            case sf::Event::EventType::GainedFocus:
            case sf::Event::EventType::MouseEntered:
            case sf::Event::EventType::MouseLeft:
            case sf::Event::EventType::Count:
                break;
        }
    }
} // namespace sf

// NOLINTEND(cppcoreguidelines-pro-type-union-access)
