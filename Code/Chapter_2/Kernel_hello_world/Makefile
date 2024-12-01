obj-m += linux_kernel_hello.o

all:
	make -C /lib/modules/6.12.1-arch1-1/build M=$(PWD) modules

clean:
	make -C /lib/modules/6.12.1-arch1-1/build M=$(PWD) clean