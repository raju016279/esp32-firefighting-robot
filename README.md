# 🔥 ESP32 Firefighting Robot

An ESP32-based autonomous firefighting robot designed to detect the
direction of a fire and move toward it using three flame sensors.
A water pump is activated when the robot reaches a close distance
from the detected fire.

## 🚀 Features

- 🔥 Fire detection using three flame sensors
- ↔️ Fire direction detection (Left / Center / Right)
- 🤖 Autonomous robot movement
- 🚗 Two DC motor control using L298N
- 💧 Automatic water pump activation
- 📡 Serial Monitor for real-time sensor readings

## 🛠️ Technologies Used

- ESP32
- Embedded C/C++
- Arduino IDE
- Analog Sensors
- Motor Control
- L298N Motor Driver

## 🔧 Hardware Components

- ESP32
- 3 × Flame Sensors
- L298N Motor Driver
- 2 × DC Motors
- Water Pump
- Relay Module
- Robot Chassis
- Power Supply

## 📌 Pin Configuration

### Flame Sensors

| Sensor | ESP32 GPIO |
|---|---:|
| Left | GPIO 34 |
| Center | GPIO 35 |
| Right | GPIO 32 |

### L298N Motor Driver

| Function | ESP32 GPIO |
|---|---:|
| IN1 | GPIO 25 |
| IN2 | GPIO 26 |
| IN3 | GPIO 27 |
| IN4 | GPIO 14 |

### Water Pump

| Component | ESP32 GPIO |
|---|---:|
| Pump / Relay | GPIO 13 |

## ⚙️ Working Principle

1. The three flame sensors continuously measure the fire intensity.
2. The ESP32 reads the analog values from the sensors.
3. The controller determines whether the fire is on the left, center,
   or right side.
4. The robot turns toward the detected fire.
5. When the fire is detected directly in front, the robot moves forward.
6. When the fire is sufficiently close, the water pump is activated.
7. The pump operates for a fixed duration and then switches off.
8. Sensor readings and robot status are displayed through the Serial Monitor.

## 🔥 Fire Detection Logic

The program uses a configurable fire threshold:

`FIRE_THRESHOLD = 500`

A lower sensor value is treated as a stronger fire indication.

The close-fire condition is:

`centerValue < 250`

These values may need to be adjusted depending on the flame sensors
and their operating conditions.

## 💻 Software

- Arduino IDE
- ESP32 Board Package
- Embedded C/C++

## 📂 Project Files

```text
esp32-firefighting-robot/
│
├── README.md
└── firefighting_robot.ino
