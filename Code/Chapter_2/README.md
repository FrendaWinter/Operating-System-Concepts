### Kernel hello world

List all `lsmod`

1. Run `cd ./Kernel_hello_world`
2. Run `make`
3. Run `sudo insmod *.ko`
4. Run `dmesg`

To look up the message  `dmesg | grep Hello`

5. Remove modules `sudo rmmod linux_kernel_hello` -> re-check with `lsmod`

