# Hydra: 6-DOF Robotic Arm

Hydra is a 6 degrees-of-freedom robot arm for exploring manipulator frameworks in ROS@ such as Moveit 2. This project is focused on analyzing the state of the art path planning and trajectory control algorithms used for manipulator controls. Its modular design and advanced motion capabilities make it ideal for tasks such as pick-and-place, object manipulation, and trajectory planning.

## Robot assembly:**


https://github.com/user-attachments/assets/17b3ea7c-a54a-45a5-91e5-415c16c06757


## Features

- **Depth-camera:**  Integrated sipeed maxisense A02 depth camera for perception and mapping the obstacles.
- **High-torque servo motors:** Arm was assembled with 4 DS3240 servo motors with 40kg torque and 2 Mg995 servos for the gripper controls.
- **Controller:** Uses an arduino microcontroller with PWM servo driver for expanding output pins.
- **Enclosure:** Custom 3D printed design to work with moderately weighted objects.

## Controls through joint state publisher
[Screencast from 01-12-2025 06_22_35 PM.webm](https://github.com/user-attachments/assets/91d9965e-447f-4bde-a219-e661b6d40cff)

## Moveit path planning

## Prerequisites

- ROS2 humble
- Gazebo 
- Python/ C++
