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
