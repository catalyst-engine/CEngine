# Catalyst engine

## Setup
1. Install [vcpkg](https://vcpkg.io/en/getting-started) with elevation
   >  git clone https://github.com/Microsoft/vcpkg.git "C:\src\vcpkg"
   >  cd "C:\src\vcpkg"
   > .\vcpkg\bootstrap-vcpkg.bat
   > vcpkg integrate install
2. Setup toolchain CLion 
   1. File -> Settings -> Build, Execution, Deployment -> Toolchains
   2. Create a new toolchain using 
      1. Build type: `Debug`
      2. Toolchain: `Visual Studio`
      3. Generator: `NMake Makefiles`
      4. CMake options: `-DCMAKE_TOOLCHAIN_FILE=C:\src\vcpkg\scripts\buildsystems\vcpkg.cmake`
3. Go to `CMakeLists.txt` and click the debug button on the side of the first line
4. Select the `catalyst` configuration that will appear in the `Configurations` dropdown on the top bar
   1. Or go to the main.cpp file and click the execute button there