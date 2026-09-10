# Smart Die

A motion-sensing six-sided die using IMU time-series data, statistical machine learning and TinyML to analyse roll states and investigate whether the final face can be predicted from its motion.

## Project Overview

The Smart Die is a physical six-sided die built around a Seeed Studio XIAO nRF52840 Sense microcontroller. Its onboard inertial measurement unit (IMU) records three-axis linear acceleration and three-axis angular velocity throughout each roll.

At each sampling time, the motion of the die is represented by:

(ax, ay, az, wx, wy, wz)

The project will use these measurements to study the state of a die roll and apply statistical and machine learning methods to the resulting time-series data.

## Objectives

- Design and 3D print the physical die.
- Record six-axis IMU data during real die rolls.
- Detect different states of a roll.
- Test the physical die for outcome bias.
- Investigate whether the final face can be predicted from its motion.
- Explore TinyML for on-device inference.
- Transmit measurements and predictions using Bluetooth Low Energy (BLE).

## Hardware

- Seeed Studio XIAO nRF52840 Sense
- Onboard 6-axis IMU
- 3.7 V LiPo battery
- Power switch
- Custom 3D-printed enclosure

## Status

🚧 Work in progress — hardware prototyping and embedded programming.
