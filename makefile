INPUT = input/poohWComment.ppm
OUTPUT = output/encode.ppm output/resize.ppm output/negative.ppm
BINARIES = main

all: build

build:
	gcc -Wall functions/*.c -o main driver.c

clean:
	rm -f ${BINARIES} *.o

run: all
	./main ${INPUT} ${OUTPUT}	

#uses ImMagik tool
toJpg:
	convert output/encode.ppm output/encode.jpg
	convert output/resize.ppm output/resize.jpg
	convert output/negative.ppm output/negative.jpg

run+: run toJpg
