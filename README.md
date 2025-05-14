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
