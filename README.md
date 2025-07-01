# CSE-406-IOT lab 2
to show update of my CSE 406 work update
1 july report of lab 2 
Arduino Water Level Sensor Project Report
1. Project Objective
The primary objective of this project was to design and implement an Arduino-based system for real-time water level detection and visual indication. The system aims to provide clear feedback on water levels (Low, Medium, High, or Empty) using a set of indicator LEDs.

2. Components Used
The following hardware components were utilized for this project:

Arduino Uno R3: Microcontroller board for processing sensor data and controlling outputs.

Analog Water Level Sensor: To detect the presence and relative level of water.

LEDs (Red, Yellow, Green): Visual indicators for different water levels.

220 Ohm Resistors (x3): Essential for current limiting with each LED to prevent damage.

Jumper Wires: For connecting components on a breadboard to the Arduino.

3. Methodology
The project involved both hardware setup and software programming:

3.1 Hardware Setup
Water Level Sensor:

The Signal (S) pin of the water level sensor was connected to Arduino's Analog Pin A0.

The VCC (+) pin of the sensor was connected to the Arduino's 5V power supply.

The GND (-) pin of the sensor was connected to the Arduino's GND (Ground).

LEDs:

The Red LED (indicating Low water) was connected to Arduino's Digital Pin 2, with a 220 Ohm resistor in series.

The Yellow LED (indicating Medium water) was connected to Arduino's Digital Pin 3, with a 220 Ohm resistor in series.

The Green LED (indicating High water) was connected to Arduino's Digital Pin 4, with a 220 Ohm resistor in series.

The cathode (short leg) of each LED was connected to Arduino's GND.

3.2 Software Implementation
The Arduino IDE was used to write and upload the C++ sketch to the Arduino Uno. The core logic of the program is as follows:

Initialization (setup() function):

Serial communication was initialized at 9600 baud for debugging and calibration.

The digital pins connected to the LEDs (2, 3, 4) were configured as OUTPUT pins.

All LEDs were initially set to LOW (off).

Main Loop (loop() function):

The analogRead() function was used to continuously read the analog value from the water level sensor connected to A0.

Sensor Calibration: Crucially, the project involved calibrating the sensor by observing its analogRead values when dry, at low water, medium water, and high water levels using the Serial Monitor. This allowed for the definition of accurate thresholds:

YOUR_LOW_THRESHOLD (e.g., 250)

YOUR_MEDIUM_THRESHOLD (e.g., 400)

YOUR_HIGH_THRESHOLD (e.g., 600)

Conditional Logic: A series of if-else if-else statements were used to compare the sensorValue against these calibrated thresholds.

If sensorValue was greater than or equal to YOUR_HIGH_THRESHOLD, the Green LED was turned ON, and others OFF.

If sensorValue was greater than or equal to YOUR_MEDIUM_THRESHOLD (but less than high), the Yellow LED was turned ON, and others OFF.

If sensorValue was greater than or equal to YOUR_LOW_THRESHOLD (but less than medium), the Red LED was turned ON, and others OFF.

Otherwise (sensor value below YOUR_LOW_THRESHOLD), all LEDs were turned OFF, indicating an "Empty" or "Very Low" state.

A small delay(200) was included to ensure stable readings and prevent rapid flickering of LEDs.

4. Results
Upon successful wiring and uploading the calibrated code, the Arduino water level sensor system performed as intended. The LEDs accurately reflected the water level changes:

Red LED: Illuminated when the water level was detected as "Low."

Yellow LED: Illuminated when the water level was detected as "Medium."

Green LED: Illuminated when the water level was detected as "High."

All LEDs Off: When the water level was "Empty" or "Very Low."

The use of 220 Ohm resistors ensured the LEDs operated safely and effectively.

5. Conclusion
This project successfully demonstrates a practical application of Arduino for environmental monitoring. By combining an analog water level sensor with simple LED indicators and carefully calibrated software logic, a reliable and intuitive system for water level detection was created. This foundational project can be expanded upon for more complex applications, such as automated pumping systems or remote monitoring.
