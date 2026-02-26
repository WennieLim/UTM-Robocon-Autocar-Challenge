# STM32-Based Autonomous Car Control System  
# Autocar Mentorship Program – Robocon UTM

# Project Overview
This project is developed as part of the **Autocar Mentorship Program under Robocon UTM**, focusing on embedded system training for autonomous robotic vehicle control.

The system demonstrates real-time motor control, UART command handling, and sensor-based navigation using an STM32 microcontroller.

It serves as a fundamental platform for:

- Autonomous robot movement
- Motor speed and direction control
- Embedded communication
- Real-time interrupt-based control

---

# Project Objectives
- To develop a reliable DC motor control system using PWM
- To implement UART interrupt-based motion command control
- To understand real-time embedded system architecture
- To build a foundation for autonomous robotic vehicle development

---

##  System Functionalities

###  Motor Motion Control (PWM-Based)

Two hardware timers are used for independent wheel control:

- **TIM2 → Right motor**
- **TIM3 → Left motor**

This enables:

- Forward / Backward motion
- Left / Right turning
- Sharp turning
- Smooth speed control

---

### UART Remote Control (Interrupt Mode)

Real-time control via serial commands:

| Command | Action |
|---------|--------|
| F | Forward |
| G | Backward |
| L | Turn Right |
| R | Turn Left |
| S | Stop |
| P | Big Left Turn |
| Q | Big Right Turn |

UART operates in **interrupt mode**, ensuring:

- Non-blocking execution
- Immediate response to commands
- Real-time control behaviour

---

### Start Trigger
A push button input is used to start the autonomous motion sequence.

---

## 🔌 Pin Configuration

| Peripheral | Function |
|------------|----------|
| TIM2 CH1 | Right Motor PWM |
| TIM3 CH1 | Left Motor PWM |
| PA1, PA2, PA4, PA5 | Motor direction control |
| PB0 | Start trigger |
| USART1 | UART communication |
| PB7 – PB9, PC13 | Status LEDs |

---

## 🗂️ Software Architecture

### 🔧 Development Environment
- STM32CubeIDE
- Embedded C
- STM32 HAL Driver

### 🔄 Program Flow

1. System initialization
2. GPIO, PWM timers, UART setup
3. Start PWM generation
4. Wait for UART command (interrupt-based)
5. Execute corresponding motion function
6. Sensor monitoring

---

## 📷 Demonstration
*(Insert training session photos / testing video / robot platform here)*

---

## 👩‍💻 Developer

**Wennie Lim**  
Autocar Trainee – Robocon UTM  
Electronic Engineering Student  
Universiti Teknologi Malaysia

---

## 🤝 Acknowledgement
Special thanks to **Robocon UTM** for providing the mentorship platform and technical guidance throughout the development of this project.
