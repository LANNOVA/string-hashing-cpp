# String Hashing in C++

This repository contains a C++ program that explores the collision problem in string hashing and its impact on banned domain name detection. The program generates a set of banned domain names and calculates their hash values using a string hash function. It then checks if all the hash values are the same, indicating a collision in the hash function.

## Dependencies

- C++11 or later
- CMake 3.0 or later

## Build Instructions

1. Clone this repository
2. Navigate to the root directory of the project
3. Create a build directory: `mkdir build && cd build`
4. Run CMake to generate build files: `cmake ..`
5. Build the project: `cmake --build .`

## Usage

After building the project, navigate to the build directory and run the `string-hashing-cpp` executable. The program will generate a set of banned domain names and calculate their hash values. If all the hash values are the same, the program will output "Success: All hash values are the same". Otherwise, it will output "Error: Hash collision detected".

## License

This project is licensed under the [MIT License](LICENSE).
