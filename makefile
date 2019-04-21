ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = /usr/local/Cellar/mingw-w64/6.0.0/bin/i686-w64-mingw32-g++
endif

ifeq ($(debug), true)
	DEBUG_FLAG =-g
endif


OBJS = textbox.o label.o main.o


all: $(OBJS)
	$(CXX) $(DEBUG_FLAG) -o main.exe $(OBJS) 
clean:
	rm -f