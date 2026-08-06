#  ServoGate ESP32

## Smart Wireless Gate System Using ESP32

A standalone smart gate system controlled wirelessly through a web page hosted directly on the ESP32.

The ESP32 works as a WiFi Access Point, allowing users to control the gate without a router, internet connection, or external server.

---

##  Project Overview

### Hardware Image
<img width="174" height="296" alt="meProject" src="https://github.com/user-attachments/assets/22aa4db8-ddfa-4800-801e-09347a92f178" />


The system consists of an ESP32, SG90 servo motor, and two status LEDs to indicate the gate state.

---

##  Web Interface

### Web UI Screenshot
<img width="957" height="452" alt="wep" src="https://github.com/user-attachments/assets/8f6e80ef-cb1b-4095-a52c-c0b7f3d483a3" />


The web interface provides two simple control buttons:

- **Open** → Opens the gate and activates the green LED
- **Close** → Closes the gate and activates the yellow LED

The interface runs directly from the ESP32 web server.

---

#  Wiring Diagram

### Wiring Image
<img width="171" height="308" alt="Wiring Diagram" src="https://github.com/user-attachments/assets/2adec6e0-36ea-4e71-bc72-8a69e2ceb745" />


## Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Servo Signal | GPIO 5 |
| Green LED | GPIO 21 |
| Yellow LED | GPIO 17 |

---

# Features

- Simple web interface accessible from any browser
- ESP32 standalone WiFi Access Point mode
- No router or internet connection required
- Wireless control from smartphones and computers
- Accurate servo motor open/close control
- Green and yellow LED status indicators
- Lightweight embedded web server
- Tested and verified using Wokwi simulation before hardware implementation

---

#  Components

| Component | Quantity |
|-----------|----------|
| ESP32 Dev Board | 1 |
| SG90 Servo Motor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| 220Ω Resistor | 2 |
| Breadboard | 1 |
| Jumper Wires | As needed |

---

#  System Operation

##  Open Gate

When the **Open** button is pressed:

- Servo moves to the open position
- Green LED turns ON
- Yellow LED turns OFF
- Web interface displays the open status

---

##  Close Gate

When the **Close** button is pressed:

- Servo moves to the closed position
- Yellow LED turns ON
- Green LED turns OFF
- Web interface displays the closed status

---

#  Simulation (Wokwi)

The project was simulated and tested using Wokwi before the physical implementation.

### Simulation Image

<img width="956" height="506" alt="Simulation Image" src="https://github.com/user-attachments/assets/0df82243-ab22-437d-b722-ebcc48f1bfc0" />


### Wokwi Simulation Link
[
[https://wokwi.com/projects/471489008441161729
](https://wokwi.com/projects/471489008441161729)](https://wokwi.com/projects/471489008441161729)

### Simulation Video



https://github.com/user-attachments/assets/4a09040c-9feb-48b2-9621-93ebbd10c73d


---

#  Physical Build

### Real Hardware Image
<img width="166" height="308" alt="Real Hardware Image" src="https://github.com/user-attachments/assets/e7648f20-e9b3-47ca-9d36-5e92e2ff829b" />

The physical circuit was built after verifying the design in Wokwi.

 Hardware Showcase:

https://github.com/user-attachments/assets/c73f943e-d28d-49f1-b9ef-c572fae152d4

---

#  How to Run

1. Upload `sketch.ino` to the ESP32 using Arduino IDE.

2. Install the required library:

- ESP32Servo

3. Connect to the ESP32 WiFi network:

```text
SSID: mathayelAP
Password: 123456789
```

4. Open your browser and enter:

```text
http://192.168.4.1
```

5. Press **Open** or **Close** to control the gate.

---

#  Technologies Used

- ESP32 Microcontroller
- Arduino IDE
- ESP32 WebServer
- WiFi Access Point Mode
- PWM Servo Motor Control
- HTML Web Interface

---

#  Project Purpose

This project demonstrates embedded systems, wireless communication, and hardware control by creating a standalone smart gate system using ESP32.

It shows how an ESP32 can host a web page, communicate wirelessly, and control physical components in real time without relying on external services.
