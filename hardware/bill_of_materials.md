# Bill of Materials - 4-Bit Hardware Adder

| Qty | Component                  | Specifications                           | Notes/Purpose                                                                 |
|-----|----------------------------|------------------------------------------|-------------------------------------------------------------------------------|
| 1   | Arduino UNO R3             | ATmega328P, 5V logic                     | Main controller for LCD display                                               |
| 1   | 74LS83 IC                  | 4-bit binary full adder                  | Performs 4-bit addition (replaces discrete gates)                             |
| 1   | 74LS47 IC                  | BCD to 7-segment decoder                 | Drives 7-segment display (common anode)                                       |
| 1   | 16x2 LCD with I2C          | I2C address 0x27, 5V                     | Displays decimal results and binary output                                    |
| 1   | Common Anode 7-Segment Display | 1-digit, red                            | Shows binary output (4 bits)                                                  |
| 1   | 8-Position DIP Switch      | SPST, through-hole                       | Input for A (4 bits) and B (4 bits)                                           |
| 8   | 10kΩ Resistor              | 1/4W, 5% tolerance                       | Pull-down resistors for DIP switches                                          |
| 1   | 330Ω Resistor Pack         | 1/4W                                     | Current limiting for 7-segment display                                        |
| 1   | LED (Red)                  | 5mm, 20mA                                | Carry-out indicator                                                           |
| 1   | 330Ω Resistor              | 1/4W, 5% tolerance                       | Current limiting for carry LED                                                |
| 1   | Breadboard                 | 830 tie-points                           | Prototyping platform                                                          |
| 1   | Jumper Wire Pack           | Male-to-male, 10cm                       | Interconnections                                                              |
| 1   | 9V DC Power Supply         | 2.1mm barrel jack, center-positive       | Arduino power                                                                 |
| 1   | IC Sockets                 | 16-pin DIP (x2)                          | Safe IC installation/removal                                                  |
| -   | **Optional**               |                                          |                                                                               |
| 1   | Logic Level Shifter        | 5V↔3.3V, 4-channel                       | If using 3.3V components                                                      |
| 1   | PCB Board                  | Perfboard or custom design               | Permanent installation                                                        |
| 1   | Project Enclosure          | Plastic, 100x80x50mm                     | Protective casing                                                             |

## Key Specifications

### 74LS83 (4-bit Full Adder)
- **Function**: Performs 4-bit binary addition with carry
- **Inputs**: 
  - A0-A3 (4-bit input A)
  - B0-B3 (4-bit input B)
  - C0 (Carry-in)
- **Outputs**: 
  - Σ0-Σ3 (4-bit sum)
  - C4 (Carry-out)
- **Supply Voltage**: 5V ±5%
- **Package**: 16-pin DIP

### 74LS47 (BCD to 7-Segment Decoder)
- **Function**: Converts 4-bit binary to 7-segment outputs
- **Compatibility**: Common anode displays only
- **Features**: Lamp test, blanking input
- **Output Current**: 24mA sink capability
- **Package**: 16-pin DIP

### 7-Segment Display Connections
| 74LS47 Pin | Segment | 7-Segment Pin |
|------------|---------|---------------|
| 13         | a       | 14            |
| 12         | b       | 16            |
| 11         | c       | 13            |
| 10         | d       | 3             |
| 9          | e       | 5             |
| 15         | f       | 11            |
| 14         | g       | 15            |

## Recommended Suppliers
1. **IC Components**:
   - [Mouser Electronics](https://www.mouser.com) (74LS83, 74LS47)
   - [Digi-Key Electronics](https://www.digikey.com) (resistors, displays)
2. **Arduino & Accessories**:
   - [Arduino Official Store](https://store.arduino.cc)
   - [Adafruit](https://adafruit.com) (LCDs, displays)
3. **Bulk Components**:
   - [Amazon Electronics](https://amazon.com/electronics)
   - [AliExpress](https://aliexpress.com) (wire packs, DIP switches)

## Estimated Cost
- **Basic Version**: $15-25 USD
- **Professional Version (with PCB/enclosure)**: $30-45 USD
