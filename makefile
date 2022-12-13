INPUT = poohWComment.ppm
OUTPUT = output.ppm

BINARIES = main

all: build

build:
	gcc -Wall driver.c ppm.c EncodeDecode.c string.c -o main

clean:
	rm -f ${BINARIES} *.o

run: all
	./main ${INPUT} ${OUTPUT}

toJpg:
	convert ${OUTPUT} art.jpg