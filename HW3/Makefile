PROJECT_DIR=.

ifeq ($(OS),Windows_NT)
	# You are using Windows
	MINGW_BIN=C:/mingw64/bin
	OPENCV_DIR=C:/opencv/build/install
	CC=${MINGW_BIN}/gcc.exe
	CXX=${MINGW_BIN}/g++.exe
	PROGRAM=main.exe
else
	# You are using Linux or MacOS
	CC=gcc
	CXX=g++
	PROGRAM=main
endif

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++11

# Using OpenCV for Visualization
OPENCV=0
OPENCV4=0
ifeq ($(OS),Windows_NT)
	ifeq ($(OPENCV), 1)
		CFLAGS+= -DOPENCV=1 -I${OPENCV_DIR}/include -std=c++11
		LDFLAGS+= -L${OPENCV_DIR}/x64/mingw/bin -lopencv_imgcodecs3413 -lopencv_core3413 -lopencv_highgui3413 -lopencv_imgproc3413
	endif
else
	ifeq ($(OPENCV), 1)
		ifeq ($(OPENCV4), 0)
			LDFLAGS+=  `pkg-config --libs opencv`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
		else
			LDFLAGS+= `pkg-config --libs opencv4`
			CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
		endif
	endif
endif

FILES=algorithms/mst.cpp graph.cpp

SRC_DIR=${PROJECT_DIR}/src/

SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})

all: 
	$(warning "You have to type one of the following commands")
	$(warning "     Type 'make qsort' to run compile and run quick sort")
	$(warning "     Type 'make msort' to run compile and run merge sort")
	$(warning "     Type 'make hsort' to run compile and run heap sort")
	$(warning "     Type 'make isort' to run compile and run intertwined sort")

qsort: ${SRC_FILES} ${SRC_DIR}/main.cpp ${SRC_DIR}sort/qsort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

hsort: ${SRC_FILES} ${SRC_DIR}/main.cpp ${SRC_DIR}sort/hsort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

msort: ${SRC_FILES} ${SRC_DIR}/main.cpp ${SRC_DIR}sort/msort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

isort: ${SRC_FILES} ${SRC_DIR}/interwined_sort.cpp ${SRC_DIR}sort/isort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

