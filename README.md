# Soil Moisture Sensor & Smart Irrigation System

A complete IoT project for monitoring soil moisture and automating irrigation.

## Components

- **Arduino** (Mega/Uno)
- **Soil Moisture Sensor** (Analog)
- **Water Flow Sensor** (YF-S201)
- **Relay Module** (for motor control)
- **DC Motor/Water Pump**

## Hardware Setup

| Pin | Component |
|-----|-----------|
| A0  | Soil Moisture Sensor |
| 2   | Flow Sensor (Interrupt) |
| 3   | Motor/Relay |

## Files

- `soil-moisture-sensor.ino` - Arduino sketch
- `soil-moisture-monitor.py` - Python receiver (logs to Excel)

## Arduino Code

```cpp
#define MOISTURE_SENSOR_PIN A0
#define FLOW_SENSOR_PIN 2
#define MOTOR_PIN 3
#define MOISTURE_THRESHOLD 30
```

## Python Requirements

```bash
pip install pyserial openpyxl
```

## Usage

1. Upload `soil-moisture-sensor.ino` to Arduino
2. Run `soil-moisture-monitor.py` on PC
3. Connect Arduino via USB (COM3)
4. Data is logged to `SoilMoistureLog.xlsx`

## Output Format

```
Moisture:75, FlowRate:0.0, Motor:OFF
Moisture:25, FlowRate:45.5, Motor:ON
```
