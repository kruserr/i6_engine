# i6 Straight-Six Engine

## Run

### Linux
```
git clone placeholder
cd placeholder
mkdir build
cd build
cmake ..
cmake --build .
./i6_engine
```

<br>

### Windows
```

```

<br>

## Linux Install

### Prerequisites
```
sudo dnf install @development-tools glm-devel cmake libpng-devel wayland-devel \
libpciaccess-devel libX11-devel libXpresent libxcb xcb-util libxcb-devel libXrandr-devel \
xcb-util-keysyms-devel xcb-util-wm-devel python git qt qt5-qtwebengine-devel

groupinstall "X Software Development"
```

<br>

Make sure to have a driver that has vulkan support installed on your system. to check look for files in these dirs:
```
ls /etc/vulkan/icd.d/
ls /usr/share/vulkan/icd.d/
```

<br>

### Install Vulkan

download SDK Tarball from:
(Vulkan.lunarg)[https://vulkan.lunarg.com/sdk/home#linux]

<br>

```
tar -xzf vulkansdk-linux-x86_64-1.1.121.1.tar.gz
cd 1.1.121.1
./vulkansdk all
cd x86_64/bin
./vkcube
```

<br>

Test if vulkan works
```
su
./vkvia
```
if not
```
su
export VULKAN_SDK=/home/ragnar/Downloads/temp3/1.1.121.1/x86_64
export PATH=$VULKAN_SDK/bin:$PATH
export LD_LIBRARY_PATH=$VULKAN_SDK/lib:$LD_LIBRARY_PATH
export VK_LAYER_PATH=$VULKAN_SDK/etc/vulkan/explicit_layer.d
./vkvia
```

<br>

Move vulkan to public system dirs
```
su

cp -r $VULKAN_SDK/include/vulkan/ /usr/local/include/
cp -P $VULKAN_SDK/lib/libvulkan.so* /usr/local/lib/
cp $VULKAN_SDK/lib/libVkLayer_*.so /usr/local/lib/
mkdir -p /usr/local/share/vulkan/explicit_layer.d
cp $VULKAN_SDK/etc/vulkan/explicit_layer.d/VkLayer_*.json /usr/local/share/vulkan/explicit_layer.d
ldconfig
```

<br>

## Windows Install
```

```
