# 2d_robot_kinematics_simulator

## **Project Description**

I've become interested in robotics lately and thought this would be a great introduction project to learn more about the basics. In the future, I'd like to extend this to be able to control an actual robotic arm. For now, though, It implements and visualizes forward and inverse kinematics for a 2-degree-of-freedom (2-DoF) planar robotic arm and allows a user to visualize it in a GUI. If you only wish to run the simulator, you can follow the installation steps, omitting the Google Test setup. However, if you plan to extend or modify the program, then installing Google Test as per the instructions will be necessary for testing setup.

## AI use
AI is here to stay, it seems, and I think it's important to be transparent about its use in my work. This project, for me, was about exploring robotics and getting to write more lines of my favorite language - C++. I have little-to-no interest in frontend web design, so I used AI (Claude) to generate the web-based GUI files (everything in src/frontend) for this project. This allowed me to concentrate on what I'm genuinely interested in learning: the robotics algorithms, kinematics math, and C++ backend implementation. The frontend serves as a functional interface, but my focus and learning efforts went into the robotics programming side.

## **Features**

- Forward Kinematics (FK): Calculate the end-effector's position given the joint angles of the 2-DoF planar arm.

- Inverse Kinematics (IK): Determine the required joint angles to reach a specified target position for the end-effector.

- 2D Visualization: Graphical representation of the robotic arm's configuration and movement within a 2D plane.

- User Interaction: Allow dynamic input for joint angles (FK) or target positions (IK) to observe real-time arm responses.

## **Setup & Building**

To get the 2D Robotic Arm Kinematics Simulator up and running on your local machine, follow these steps:

### **Prerequisites**

Make sure you have the following installed:

- C++ Compiler: (e.g., GCC, Clang, MSVC)

- CMake: A cross-platform build system.

- Download CMake

- Git: For cloning repositories.

### **Recommended VS Code Extensions (if using VS Code)**

- CMake Tools

- C/C++ extension

### **Installation Steps**

Clone the Repository: Navigate to the directory where you want to store the project and clone the 2d_robot_kinematics_simulator repository:

- `git clone https://github.com/your-username/2d_robot_kinematics_simulator.git`
- `cd 2d_robot_kinematics_simulator`

Clone GoogleTest: Google Test is used for the project's unit and integration tests. Clone the Google Test repository directly into your project's root directory:

- `git clone https://github.com/google/googletest.git`

Build with CMake: Create a build directory, navigate into it, and use CMake to configure and build your project. This will generate the necessary build files and compile the source code.

- `mkdir build`
- `cd build`
- `cmake ..` # Configures the project and generates build files
- `cmake --build . ` # Compiles the project

## **Usage**

After successfully building the project, your executable (robot_simulator on Linux/macOS or robot_simulator.exe on Windows) will be located in the build/bin directory.

To run the application:

- `./bin/robot_simulator`

Or on Windows:

- `.\bin\robot_simulator.exe`

The simulator will launch a 2D window displaying the robotic arm.

- Forward Kinematics Mode: (Describe how to input joint angles, e.g., "Use Q and A to control Joint 1, W and S to control Joint 2.") The arm will update its position based on these angles, and the end-effector coordinates will be displayed.

- Inverse Kinematics Mode: (Describe how to set a target, e.g., "Click anywhere on the screen to set a target (X, Y) position for the end-effector.") The arm will attempt to move to this position, and the calculated joint angles will be displayed.

- Switching Modes: (If applicable, describe how to switch between FK and IK modes, e.g., "Press M to toggle between FK and IK modes.")

## **Running Tests**

The project includes unit and integration tests using Google Test. After building with CMake, you can run all tests using ctest from your build directory:

- `cd build`
- `ctest` # Use --verbose to see detailed test output

You can also run tests directly from the VS Code Test Explorer sidebar after the CMake Tools extension has configured the project.

## **License**

This project is licensed under the MIT License. See the LICENSE file for details.

## **Cloning Dependencies**

This project relies on specific versions of [Asio](https://think-async.com/) and [WebSocket++](https://github.com/zaphoyd/websocketpp). If you're not using a package manager, follow the steps below to manually clone these libraries.

---

I used a shallow clone of Asio 1.10.8 to reduce download size and ensure compatibility.

```bash
cd ThirdPartyLib 

# Clone version 1.10.8 only (shallow clone)
git clone --depth 1 --branch asio-1-10-8 https://github.com/chriskohlhoff/asio.git

git clone https://github.com/zaphoyd/websocketpp.git
```

## **Contributing**

Contributions are welcome! If you find a bug or have an idea for an improvement, please open an issue or submit a pull request.
