# linux-kernel-module

Simple examples of Linux Kernel Modules.

### Building the Module
make

The module is compiled to `lkm_oper.ko`.

### clean the Module
make clean

### Installing / Uninstalling

```sh
# Install without parameters :
sudo insmod lkm_oper.ko

# Install with parameters:
sudo insmod lkm_oper.ko a=11 b=15
sudo insmod lkm_oper.ko a=11
sudo insmod lkm_oper.ko b=15

# view output of executed program :
dmesg

# Uninstall
sudo rmmod lkm_oper
