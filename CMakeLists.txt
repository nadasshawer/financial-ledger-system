cmake_minimum_required(VERSION 3.14)
project(FluxSystemsEngine)

# Set C++ standard to 17 for FTXUI compatibility
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent module handles the automatic download of the FTXUI library
include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# Tell the compiler where to look for your header (.h) files
include_directories(include)

# The executable definition including every .cpp file in your project structure
add_executable(flux_engine 
    src/core/main.cpp 
    src/auth/user_info.cpp
    src/core/registration.cpp
    src/core/globals.cpp
    src/core/login.cpp
    src/core/menu_handler.cpp
    src/models/budget.cpp
    src/models/classes.cpp
    src/models/report.cpp
    src/utils/datetime.cpp
    src/utils/math_utils.cpp
    src/utils/text_utils.cpp
    src/validation/validation.cpp
)

# Link the three required FTXUI modules to your executable
target_link_libraries(flux_engine PRIVATE ftxui::screen ftxui::dom ftxui::component)