File Edit Options Buffers Tools Makefile Help                                   
obj-m += numpipe.o

all: producer consumer
        make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

producer: producer_numbers.c
        gcc -o producer producer_numbers.c
consumer: consumer_numbers.c
        gcc -o consumer consumer_numbers.c


clean:
        make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
        rm producer consumer

