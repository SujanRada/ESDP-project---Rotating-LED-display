# Rotating LED Display

## Abstract

- Compact, disc-sized device  
- Rotates using CD/BLDC motor  
- Uses 56 RGB LEDs to display images, time, weather, and data from the internet  
- Wirelessly powered  
- Controlled via user-friendly web interfaces  
- Uses ESP-32 and RP-2040 microcontrollers
  
### BOM:
https://iith-my.sharepoint.com/:x:/g/personal/ee23btech11220_iith_ac_in/Eb25p-EQcuBLmObKBZ19a6YB39MDdF6vqVOBd3wfBGQ2Pw?e=q3nKKc

## Description of the Device

- Two primary units:
  - Power supply unit (stationary)
  - Display board (rotates)

- Wireless power using inductive coupling  
- Display board is rotated using a DC motor  
- Energy is wirelessly transmitted from the power supply unit to the display board, eliminating the use of wired connections  
- Display board has a row of 56 LEDs used for display. As the board rotates, the LEDs light up to create full images using the POV (Persistence of Vision) effect  
- LED operations are controlled by the RP-2040  
- ESP32 controls the display content, image decoding, and Wi-Fi connectivity (maintains an internet connection)  
- Images are stored on a microSD card  
- Web interface hosted by ESP32 (mini web server). Users can access it via any browser to:
  - Enter/change Wi-Fi credentials
  - Upload and manage files
  - Modify display settings

## Operating Modes

### BOOT Behavior and Wi-Fi Setup

- On startup, the device tries connecting to a known Wi-Fi network.
- If no valid credentials are found, it enters **Access Point (AP) mode**.

  **AP Mode Details:**
  - **SSID:** ESDP40  
  - **Password:** *(None — open network)*

- To configure:
  1. Connect your PC or mobile device to the `ESDP40` Wi-Fi network.
  2. Open a web browser and navigate to the IP address shown on the device display.

#### Web Interface (Hosted by ESP32)

- Enter Wi-Fi credentials
- View the device's IP address (if connected to local Wi-Fi)
- Upload images and modify display configurations
- Switch between available display modes
- Manage files stored on the SD card

### Display Modes

- **LOGO Clock Mode:**  
  Displays an analog clock face along with a customizable logo or image

- **Analog Clock Mode:**  
  Shows a traditional clock face with customizable visuals

- **Weather and Time Mode:**  
  Displays current time, weather information, and charging status

### Mode Configuration

All display modes and system settings can be configured via the web user interface.

## Mechanical Design

- The mechanical design consists of two main assemblies:
  - **Power Supply Board** (stationary)
  - **Display Board** (rotating)

- A potentiometer is included to control the rotation speed.

- **Wireless Power Alignment:**
  - The secondary coil on the back of the rotating board aligns with the primary coil on the base.
  - Power is transferred inductively (eliminates twisting wires).

- **Symmetrical Component Placement:**
  - Ensures smooth rotation and proper balance.
  - Aligns the center of mass (COM) with the rotational axis.
  - Any imbalance in materials can cause the disc to wobble, affecting display clarity and mechanical durability.

### LED Specifications

- 56 rectangular RGB LEDs, each approximately **1.6 mm wide**  
- Placed on a **2 mm pitch/grid**  
- The LED row is shifted by **0.5 mm** (not centered)

**Why the 0.5 mm shift?**

- When the disc spins 180°, the 0.5 mm offset causes the LED row to align in between the previous positions, effectively reducing the radial pitch from 2 mm to 1 mm.
- This creates a **rotational interlacing effect**:
  - **Doubles the radial resolution** (from 2 mm to 1 mm)
  - **Doubles the effective frame rate** by smoothly overlapping alternating frames

### Image Synchronization

- The software requires precise rotational phase information to display images correctly.

- A **Hall sensor** detects the "zero" or **home position** and generates a trigger pulse to indicate the start of a new frame.

**Trigger Pulse Function:**

- Resets the angular position counter to **0°**
- Starts a new frame/image rendering
- Controller updates LEDs at **precise angular intervals** until the next pulse, ensuring stable and synchronized visuals

> ⚠️ If the trigger pulse is noisy or misaligned, it may result in flickering or wobbly visuals.

## Electronics Architecture

- A **12–24V DC input** powers the entire system.

### Components

- **Variable Step-Down Converter**  
  - Adjusts voltage to drive the motor that spins the display.

### Receiving End (on Rotating Display Board)

- AC from wireless coil → **Rectified to DC** → Passed through:
  1. 5V step-down DC converter
  2. 3.3V step-down DC converter  
  → Powers **microcontrollers** and **LEDs**

---

## Display Assembly

### LED Path Control

- 56 RGB LEDs managed using **7 × 24-bit shift registers**
  - Each shift register controls 8 RGB LEDs  
    (3 colors × 8 LEDs = 24 bits per register)

### RP2040 Microcontroller

- Interfaces with shift registers via **SPI**
- Sends data and clock signals to control LEDs
- Uses **hall sensor** input to trigger LED updates at precise angular positions

### Image Generation Path

- **ESP32-S3 Microcontroller**:
  - Connects to the internet via Wi-Fi
  - Reads image data from a **microSD card**
  - Sends image frames to RP2040 over SPI

### Synchronization

- A **hall-effect sensor** detects fixed positions each rotation
- Sends a **trigger signal** to the RP2040 to:
  - Reset angular position
  - Ensure correct image alignment and smooth refresh

---

### Flow Summaries

#### 🔌 Power Flow:
12–24V DC → Wireless Power Supply → Wireless Coil → Rectifier → 5V/3.3V Regulators → Electronics

#### 🔄 Data Flow
ESP32 → SPI → RP2040 → SPI → Shift Registers → LEDs

#### ⏱️ Timing Flow
Hall Sensor → Trigger → RP2040 → Synchronized LED Updates


---

## Power Supply Unit

*Content coming soon...*

