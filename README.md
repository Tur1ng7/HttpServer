# HttpServer

![C++](https://img.shields.io/badge/C++-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A simple, lightweight HTTP server built from scratch using C++ to understand the fundamentals of web servers, routing, handling HTTP requests, and responses. This server supports basic routing, serving dynamic HTML content, and can be extended to serve static files (if needed in the future).

## Features

- Basic HTTP server functionality with support for dynamic routing.
- A custom thread pool to handle multiple client requests concurrently.
- Logging system to track client connections and responses.
- Lightweight and easy to extend for further learning and experimentation.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Resources Used](#resources-used)

## Installation

### Prerequisites

- C++ compiler (G++ or Clang)
- CMake (version 3.10 or later)
- Make
- Linux or macOS for development, Windows (with WSL or similar) should work as well.

### Steps to Build and Run

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/Tur1ng7/HttpServer.git
   cd HttpServer
   ```

2. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```

4. Build the project using Make:
   ```bash
   make
   ```

5. After the build is complete, you can run the server:
   ```bash
   ./HttpServer
   ```

The server will start running on port 8080 by default. You can access it in your browser or via curl:
```bash
curl http://localhost:8080
```

## Usage

Once the server is running, you can interact with it by visiting the following endpoints in your browser:

- `http://localhost:8080/` – Returns a simple greeting message.
- `http://localhost:8080/hello` – Returns a welcome message on the `/hello` route.

### Example Request

```bash
curl http://localhost:8080/hello
```

This will return a response with the message: "Welcome to the /hello endpoint!"

## Resources Used

- **[man Command](https://www.ibm.com/docs/en/aix/7.1?topic=m-man-command&mhsrc=ibmsearch_a&mhq=man%20command)**
- **[MDN Web Docs](https://developer.mozilla.org/en-US/)**
- **[cppreference](https://en.cppreference.com/w/)**
- **[CMake](https://cmake.org/)**

