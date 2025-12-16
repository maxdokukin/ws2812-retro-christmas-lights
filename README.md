# Arduino FastLED Flickering C9 Christmas Lights Effect

This project creates a realistic, vintage C9-style flicker effect on any addressable RGB LED strip or string supported by the [FastLED](https://fastled.io/) library. It simulates classic incandescent C9 Christmas bulbs using Perlin noise for smooth, independent flickering on every pixel.

The example is configured for WS2812 / WS2812B (NeoPixel) LEDs, but it can be adapted to any addressable LED chipset that FastLED supports (SK6812, APA102, WS2801, and more) and to any compatible microcontroller platform (Arduino Uno, Nano, Mega, ESP32, ESP8266, Teensy, STM32, etc.).

---

## Features

- Realistic flicker using FastLED's `inoise8` (Perlin noise) for smooth brightness variation.  
- Per-pixel noise offsets so every “bulb” flickers independently.  
- Classic C9 color palette: red, orange, green, blue, and warm white.  
- Designed for 120 LEDs by default, but easily configurable for any strip length.  
- Compatible with all FastLED-supported addressable LED types (RGB and RGBW).  
- Platform-agnostic: runs on any board that can compile and run FastLED.

---

## Compatibility

### Supported LED Types

This flickering C9 Christmas lights effect works with any addressable LED chipset supported by FastLED, including but not limited to:

- WS2812 / WS2812B (NeoPixel)  
- SK6812  
- APA102 (DotStar)  
- WS2801  
- Many other addressable RGB / RGBW LED strips and pixel strings

To adapt the sketch to a different LED type, change the FastLED controller line to match your chipset and color order. As long as your LEDs are supported by FastLED, this effect will work.

### Supported Boards / Platforms

The project is designed to be highly portable. It will run on any microcontroller platform that:

1. Is supported by the Arduino IDE (or a compatible environment).  
2. Can install and run the FastLED library.  
3. Can drive your chosen addressable LEDs.

Common boards and platforms include:

- Arduino Uno, Nano, Pro Mini, Mega  
- Arduino Leonardo, Micro  
- ESP8266 (NodeMCU, Wemos D1 mini, etc.)  
- ESP32 development boards  
- Teensy boards  
- Many other AVR and ARM-based boards supported by the Arduino ecosystem and FastLED

If your board can run FastLED examples, it can run this C9 flicker effect.

---

## Hardware Setup

1. **Connect your LED strip or string**
   - LED data input → microcontroller digital pin (default: pin 3 in the example).  
   - LED 5 V → stable 5 V power supply (sized for your LED count).  
   - LED GND → shared ground with:
     - Power supply ground  
     - Microcontroller GND  

2. **Set the LED count**  
   - In the sketch, set `NUM_LEDS` to match the actual number of LEDs in your strip or string.

3. **Optional: Change data pin**  
   - Adjust the `DATA_PIN` definition in the code if you are using a different digital pin than the default.

4. **Recommended protection components**  
   - 330–470 Ω resistor in series with the data line.  
   - 1000 µF capacitor across 5 V and GND at the LED strip input.  
   - These components help protect both the LEDs and the microcontroller and improve stability.

---

## Arduino IDE: Quick Setup and Upload

### 1. Install the Arduino IDE

- Download and install the latest Arduino IDE for your operating system from the official Arduino website.  
- Launch the Arduino IDE after installation.

### 2. Install the FastLED Library

1. Open the Arduino IDE.  
2. Navigate to: **Sketch → Include Library → Manage Libraries…**  
3. In the Library Manager search bar, type `FastLED`.  
4. Install the library named `FastLED` by Daniel Garcia and Mark Kriegsman.

### 3. Create and Configure the Sketch

1. Go to **File → New** to create a new sketch.  
2. Paste the provided FastLED flickering C9 effect code into the sketch editor (from this repository).  
3. Save the sketch with a name such as `FastLED_Flickering_C9`.  
4. Adjust configuration values in the sketch as needed:
   - `NUM_LEDS` for your LED strip length.  
   - `DATA_PIN` for your wiring.  
   - The FastLED LED type and color order to match your LEDs.  
   - Optional: global brightness via `FastLED.setBrightness(...)`.

### 4. Select Board and Port

1. Connect your board via USB.  
2. In the Arduino IDE:  
   - Go to **Tools → Board** and select your board (e.g., "Arduino Uno", "ESP32 Dev Module").  
   - Go to **Tools → Port** and select the correct COM/serial port for your board.

### 5. Verify and Upload

1. Click the **Verify** button (checkmark) to compile the sketch.  
2. If compilation completes successfully, click the **Upload** button (right arrow).  
3. After the upload finishes, your LEDs should begin showing the independent C9-style flicker effect.

---

## Customization

Even though the project is focused on compatibility, it is also easy to customize:

- **Flicker speed**: Adjust the speed variable and/or the frame delay in the sketch to make the flicker slower or faster.  
- **Color palette**: Modify the C9 color map array to change or extend the colors used.  
- **Brightness**: Use `FastLED.setBrightness()` to control maximum brightness globally, which is useful for power-limited installations.

These changes do not affect cross-platform compatibility; the effect remains portable across all boards and LED types supported by FastLED.

---

## SEO / Keywords

This project is suitable if you are looking for:

- Arduino FastLED Christmas light effects  
- Arduino WS2812B C9 flicker animation  
- NeoPixel vintage C9 incandescent-style LEDs  
- ESP32 / ESP8266 addressable LED Christmas lights  
- FastLED Perlin noise flickering effect  
- Cross-platform FastLED holiday lighting sketch  
- Addressable LED C9 string light effect

Because the code relies strictly on the FastLED API and does not use any board-specific features, it is highly compatible and portable. As long as your platform supports FastLED and your LEDs are in the list of supported chipsets, this flickering C9 effect will work without major changes.
