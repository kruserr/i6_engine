# i6_engine

Straight-Six Engine

<br>

# Deps

```
sudo dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel
```

<br>

# Install

```
git clone https://github.com/kruserr/i6_engine.git
cd i6_engine
./run.sh

```

<br>

# ref

https://www.willusher.io/sdl2%20tutorials/2013/08/18/lesson-3-sdl-extension-libraries


# WINDOWS CONFIGURATION OF SDL2.
```
Step 1:
Download and install vcpkg in root folder of windows. by using git bash, and powershell.

Step 2:
After installing vcpkg: open powershell and type:
.\vcpkg search sdl2
.\vcpkg install sdl2

Step 3:
Open visual studio and include sdl2 by typing
#include <SDL2/SDL.h>

Step 4:
Fix linker errors, goto   Project Propeties->Configuratio Properties->Linker->Input->Aditional dependencies
and type opengl32.lib; at the end of the string.

Step 5:
Before the int main{}
add:
#undef main	// Have to undefine main, because main is already defined in another place.



```
<br>
