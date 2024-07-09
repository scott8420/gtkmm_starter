# GENERIC MAKEFILE FOR GTK PROJECT

# PROPERTIES
PROG=starter
CXX=g++
CXXFLAGS=`pkg-config --cflags gtkmm-4.0` -Iinclude/ -Irsc/ -std=c++17 -g
LIBS=`pkg-config --libs gtkmm-4.0`
SRCS=$(wildcard src/*.cc)
OBJS=$(SRCS:.cc=.o)
BIN=bin/
RES=rsc/
OBJ=obj/

# RULES
.SUFFIXES: .o .cc

.cc.o:
	$(CXX) -c $(CXXFLAGS) -o $(subst src/,obj/,$@) $<

all: clean $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $(BIN)$(PROG) $(subst src/,obj/,$(OBJS)) $(LIBS) 

clean:
	rm -fR $(OBJ)*.o $(BIN)starter 

install:
	rm -rf /usr/local/share/starter
	mkdir /usr/local/share/starter
	cp -f bin/starter /usr/local/share/starter/starter
	cp -f rsc/starter.png /usr/local/share/starter/starter.png
	cp -f rsc/starter.svg /usr/local/share/starter/starter.svg
	cp -f rsc/starter.desktop /usr/share/applications/starter.desktop

uninstall:
	rm -rf /usr/local/share/starter
	rm -f /usr/share/applications/starter.desktop