# FPGA-Implementation-of-Smart-Water-Quality-Monitoring-System

## Overview

This project focuses on designing and implementing a Smart Water Quality Monitoring System using FPGA technology. The system integrates three types of sensors:

- **Water Level Sensor:**  Monitors the water level to assess potential flooding or inadequate water supply.
- **MQ-7 Gas Sensor:** Detects the concentration of carbon monoxide (CO), indicating potential contamination in the water or surrounding environment.
- **Temperature Sensor (LM35):** Measures the water temperature to detect irregularities that could indicate pollution or harmful environmental changes.
  
The sensor values are captured and processed using both FPGA and Arduino platforms, with a focus on FPGA for efficient hardware-level monitoring and control. The processed data is compared to specific threshold values to provide real-time feedback on water quality.

## Details

## Arduino-FPGA Sensor Integration

### 1. Water Level Sensor

- **Sensor Output Range:** 0 to 800
- **Conversion:** The analog value is converted into a percentage by dividing the output by 800.
- **Discretization:** Due to a shortage of available pins on the Arduino, we apply 10% discretization.  
  For example:
  - If the water level is 85%, it is interpreted as 80%.
  - This value is then sent as a binary number (e.g., 8) to the FPGA.
- **Display:** The water level percentage is shown on a 7-segment display.
- **LED Indicator:** 
  - If the water level crosses 50%, the LED turns ON.
  - Otherwise, it remains OFF.

### 2. Carbon Monoxide Gas Sensor

- **Sensor Output Range:** Starts from 50 ppm (parts per million) and continues up to 500 ppm.
- **Levels:** 
  - Level 1 = 50 ppm
  - Level 2 = 100 ppm  
  - ...
  - Level 10 = 500 ppm
- **Binary Conversion:** The output level is converted into a 4-bit binary number and sent to the FPGA.
- **Display:** The gas level is shown on a 7-segment display.
- **LED Indicator:** 
  - According to [Wikipedia](https://en.wikipedia.org/wiki/Carbon_monoxide), the safe level of CO is less than 50 ppm.
  - If the level is **≥ 1**, the LED turns ON to indicate dangerous levels of CO.

### 3. Temperature Sensor

- **Threshold Value:** 30°C
- **Output Logic:**
  - If temperature > 30°C → Arduino sends digital `1`
  - Else → Arduino sends digital `0`
- **LED Indicator:** 
  - LED lights up when the temperature crosses the threshold.

---

This setup allows real-time monitoring and visualization of environmental data using a combination of Arduino and FPGA logic.




