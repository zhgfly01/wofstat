CXX=g++
OPTS=-O
CFLAGS=$(OPTS) -Wall
SRC=src
LIB=

NETSTAT_SRC=$(SRC)/netstat_util.cpp $(SRC)/string_util.cpp
MIKESTAT_SRC=$(SRC)/mikestat.cpp

ifeq ($(OS),Windows_NT)
	NETSTAT_SRC+=$(SRC)/netstat_windows.cpp
	LIB+=-lIPHlpApi -lWs2_32
else
	os=$(shell uname -s)
	ifeq ($(os),Linux)
		NETSTAT_SRC+=$(SRC)/netstat_linux.cpp
	endif
	ifeq ($(os),Darwin)
		NETSTAT_SRC+=$(SRC)/netstat_osx.cpp
	endif
	ifeq ($(os),SunOS)
		NETSTAT_SRC+=$(SRC)/netstat_solaris.cpp

		ifeq ($(shell if [ $(shell uname -r|cut	-d'.' -f2) -ge 11 ];then echo 'new';else echo 'old';fi),new)
			CFLAGS+=-D NEWSOLARIS
		endif
	endif
	ifeq ($(os),$(filter $(os),FreeBSD GNU/kFreeBSD NetBSD OpenBSD))
		NETSTAT_SRC+=$(SRC)/netstat_bsd.cpp
	endif
endif

all: mikestat

mikestat: $(NETSTAT_SRC) $(MIKESTAT_SRC)
	$(CXX) $(CFLAGS) $(NETSTAT_SRC) $(MIKESTAT_SRC) $(LIB) -o mikestat

clean:
	- rm -f mikestat mikestat.exe
