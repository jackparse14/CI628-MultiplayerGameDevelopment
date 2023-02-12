See https://github.com/jackparse14/CI628-MultiplayerGameDevelopment-server for the server side program with this project

# CI628-PongClient
A simple multiplayer pong client in C++.

### Build

The project is configured to be developed on Windows, so it only includes Windows-specific SDL versions.

To build, you will need:

* [CMake](https://github.com/Kitware/CMake/releases/download/v3.18.4/cmake-3.18.4-win64-x64.zip) 3.16+
* Visual Studio 2019

1. Download this repository by clicking "Code" -> Download zip.
2. Extract the zip file and rename `CI628-PongClient-master` to `CI628`.

Open the command line (via Git Bash):

```
cd CI628
mkdir build
cd build

// Note: if running on Uni machines, it's /c/Program\ Files/CMake/bin/cmake rather than just cmake
// Note: if running on Uni machines from Command Prompt, it's "C:\Program Files\CMake\bin\cmake.exe" rather than just cmake
// OR see further below how to make cmake visible globally

cmake .. -G "Visual Studio 16 2019"

```

After this, a ".sln" will be generated in `build/`.

1. Open the ".sln" file with Visual Studio 2019.
2. Right click on MyGame in project explorer and select as startup project.
3. Right click on MyGame again and select Properties.
4. In the properties window, Linker -> System and change SubSystem to Console.

Before running the demo, ensure that the [CI628-server application](https://github.com/AlmasB/CI628-PongServer/releases) is running. You can now run the demo from Visual Studio via Local Windows Debugger.

#### Globally accessible cmake

1. Close git bash if open.
2. Go to `C:\Users\your_user_name` and open (or create) a file with **exact** name `.bash_profile`.
3. Add to file:

```
export CMAKE_HOME=/c/Users/... <-- path to cmake directory (i.e. where you downloaded/extracted cmake to)
export PATH=$PATH:$CMAKE_HOME/bin
```

4. Open git bash and check cmake works by typing:

```
cmake --version
```
