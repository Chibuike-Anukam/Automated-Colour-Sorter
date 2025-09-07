# Automated Colour Sorter

An automated machine designed to sort objects by their colour, specifically targeting LEGO pieces for building projects.

## Overview
This project addresses the need for efficient colour sorting of LEGO pieces. As a LEGO enthusiast, I often want to build creations with specific colours (like grey pieces for stone walls), which requires sorting through mixed collections. The machine was designed to be portable with a foldable base, detachable components, and carrying handle.

### Key Features:
- Automated colour detection and sorting
- Portable design with foldable base and handle
- Multi-container sorting system
- Arduino-based control system
- Conveyor mechanism for continuous operation

Inspiration: Based on Dejan's tutorial from 'How To Mechatronics' YouTube channel

## Design Specifications
- Target Objects: LEGO pieces and small colored objects (tested with pony beads)
- Detection Method: TCS3200 colour sensor for RGB identification
- Sorting Mechanism: Servo-controlled rotating platform directing objects to containers
- Portability: Foldable base design with detachable components
- Power: External power jack with on/off switch

## System Components
### Electronics:
- TCS3200 Colour Sensor for colour detection
- 2 Servo motors (conveyor and sorting mechanism)
- Elegoo Arduino Nano microcontroller
- Power jack and switch
- Jumper wires for connections
### Mechanical Components:
- Cardboard frame and structure
- Straws for conveyor guides
- Pipe cleaners and skewers for mechanical linkages
- Cardstock for platforms and containers
- Magnets for detachable connections
- Hot glue for assembly

## System Operation
1. Object Detection: TCS3200 sensor reads RGB values of objects on conveyor
2. Colour Analysis: Arduino processes sensor data to identify colour
3. Sorting Action: Bottom servo rotates to align with appropriate container
4. Object Direction: Conveyor mechanism guides object to selected container
5. Continuous Operation: Process repeats for next object in queue

## Results
The prototype successfully demonstrated the core sorting concept:
- Functional Sorting: When colour sensor worked correctly, objects were directed to appropriate containers
- Mechanical Performance: Conveyor system and servo mechanisms operated smoothly
- Object Handling: Pony beads fit well in the conveyor system
- Challenge Identified: TCS3200 sensor proved finicky with inconsistent colour readings
### Key Learning Outcomes:
- Extensive troubleshooting experience with colour sensors
- Developed patience and perseverance in engineering problem-solving
- Understanding of RGB colour detection principles
- Mechanical design experience with portable systems

## Future Improvements
### Planned Enhancements
- Dual Sensor System: Add second colour sensor for automatic colour calibration
- User Interface: Implement keypad and LCD display for user control
- Menu System: Allow users to specify number of colours and sorting preferences
- Enhanced Accuracy: Improve colour detection reliability and consistency

### Commercial Potential
- First prototype demonstrates proof of concept
- Market potential for hobbyists and educational applications
- Scalable design for larger sorting operations
- Modular upgrades for enhanced functionality

## Project Development
### Design Approach:
- Research-based design inspired by existing tutorials
- Focus on portability and user-friendly operation
- Iterative development with hands-on troubleshooting
- Emphasis on learning through practical implementation
### Development Resources:
- Tutorial: [How To Mechatronics Arduino Color Sorter](https://howtomechatronics.com/projects/arduino-color-sorter-project/)
- Video Guide: [YouTube Tutorial](https://youtu.be/g3i51hdfLaw)
- The referenced website includes: 
  - Arduino code for colour detection and servo control
  - Circuit diagram
  - Mechanical assembly instructions
  - Troubleshooting guide for colour sensor issues
  - Design sketches and component specifications


This project demonstrates the integration of electronics and mechanical design for automated sorting applications. While challenges were encountered with sensor reliability, the core concept was successfully validated and provides a foundation for future development.

Project Creator: Chibuike

Acknowledgment: Special thanks to Dejan from 'How To Mechatronics' for the excellent tutorial and inspiration!
