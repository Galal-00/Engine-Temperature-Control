# Engine Temperature Control System 🌡️🔧

## System Description

### MCU1

#### Components
- Push Button 🔘
- Temperature Sensor 🌡️
- DC Motor (as a fan) 🌀

#### Description
1. **Initial State Check:**
   - MCU1 reads the state from EEPROM before reading temperature to act according to it as an abnormal state or not.
   
2. **Temperature Monitoring and Control:**
   - MCU1 reads temperature and stores the state as normal initially in EEPROM.
   - The fan (DC motor) is controlled with acceptable speed according to states.
   - Temperature data is sent to MCU2 using UART.

3. **Button Press Action:**
   - If the user presses the push button and the temperature is between 40°C and 50°C, MCU1 sends a code to MCU2 through UART, indicating to shut down the machine.

### MCU2

#### Components
- Servo Motor 🤖
- 3 LEDs 💡
- Potentiometer 🎛️
- DC Motor (as an engine) 🌀
- Buzzer 🔊

#### Description
1. **Receive and Act on Messages:**
   - MCU2 receives messages using UART from MCU1 and acts accordingly.

2. **Speed Control with Potentiometer:**
   - The potentiometer controls the speed of the machine (DC motor).

### States

#### 1) Normal State

- **Temperature < 20°C:**
  - MCU1 stops the fan.
  - MCU2 lights the green LED. 💚

- **20°C ≤ Temperature < 40°C:**
  - Fan in MCU1 is moved with speed increasing according to increasing temperature.
  - Maximum speed at 40°C.
  - MCU2 lights the yellow LED. 💛

- **40°C ≤ Temperature < 50°C:**
  - MCU1 moves the fan with max speed.
  - MCU2 lights the red LED and stops the machine on button press. ❤️

- **Temperature ≥ 50°C:**
  - MCU1 and MCU2 enter an emergency state.

#### 2) Emergency State

- Begin counting time.
- MCU1 moves the fan with max speed.
- MCU2 lights the red LED and activates the buzzer. 🚨

#### 3) Abnormal State

- MCU1 moves the fan with max speed.
- MCU2 lights the red LED, opens the servo with 90 degrees, stops the machine, and runs the buzzer. 🚨🚫

If the emergency state is activated for 7 seconds (using a timer with overflow mode to check temperature 14 times with a period of 500ms):

1. Write abnormal state in EEPROM.
2. MCU1 activates the watchdog timer with the smallest time to reset MCU1.
3. MCU2 follows the abnormal condition for 5 seconds.

## Implementation Details 🛠️

- **EEPROM Usage 🧠:** Internal EEPROM for storing and retrieving system states.
- **UART Communication 📡:** MCU1 sends temperature data to MCU2 using UART.
- **MCU1 Reset Control 🔄:** MCU1 resets using the Watchdog Timer.
- **Potentiometer Control 🎚️:** MCU2 adjusts the speed of the machine with the potentiometer value using ADC, GPIO and interrupt controller.
- **LEDs Control 💡:** MCU2 controls the 3 LEDs using GPIO.
- **Emergency State Timer ⏰:** A timer with overflow mode is used to check the emergency state condition every 500ms using interrupts. If the condition persists for 7 seconds, specific actions are taken.
- **Simulation 🤖**: Proteus .
- **Code Editor 👨‍💻**: Microchip Studio .
