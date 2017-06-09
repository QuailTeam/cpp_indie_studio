
Target = indie_studio

SRC = ./src/

Sources =	$(SRC)main.cpp \
		$(SRC)random.cpp \
		$(SRC)Core.cpp \
		$(SRC)Image.cpp \
		$(SRC)List.cpp \
		$(SRC)MyEventReceiver.cpp \
		$(SRC)Welcome.cpp \
		$(SRC)MainMenu.cpp \
		$(SRC)GameSelectMenu.cpp \
		$(SRC)BombermanSolo.cpp \
		$(SRC)BombermanDuo.cpp \
		$(SRC)SoloEndMenu.cpp \
		$(SRC)DuoEndMenu.cpp \
		$(SRC)Mesh.cpp \
		$(SRC)Map.cpp \
		$(SRC)AEntity.cpp \
		$(SRC)EntityManager.cpp \
		$(SRC)Bomb.cpp \
		$(SRC)Explosion.cpp \
		$(SRC)Gate.cpp \
		$(SRC)APlayer.cpp \
		$(SRC)Player1.cpp \
		$(SRC)Player2.cpp \
		$(SRC)Monster.cpp \
		$(SRC)Plane.cpp \
		$(SRC)Powerup.cpp \
		$(SRC)Box.cpp \

IRRLITCHT = ./irrlicht-1.8.4/

# general compiler settings
CPPFLAGS = -I$(IRRLITCHT)include -I/usr/X11R6/include -I./include/
CXXFLAGS = -O3 -ffast-math -g
#CXXFLAGS = -g -Wall

#default target is Linux
all: all_linux

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

# target specific settings
all_linux: LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L$(IRRLITCHT)lib/Linux -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -lsfml-audio
all_linux clean_linux: SYSTEM=Linux
all_win32: LDFLAGS = -L$(IRRLITCHT)lib/Win32-gcc -lIrrlicht
static_win32: LDFLAGS += -lgdi32 -lopengl32 -ld3dx9d -lwinmm -lm
static_win32: CPPFLAGS += -D_IRR_STATIC_LIB_
static_win32 all_win32 clean_win32: SYSTEM=Win32-gcc
static_win32 all_win32 clean_win32: SUF=.exe
# name of the binary - only valid for targets which set SYSTEM
DESTPATH = $(Target)$(SUF)

all_linux all_win32 static_win32:
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux clean_win32
	$(warning Cleaning...)

clean_linux clean_win32:
	@$(RM) $(DESTPATH)

re:	clean all

install:
	wget "http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.4.zip"
	unzip "irrlicht-1.8.4.zip"
	make -C "irrlicht-1.8.4/source/Irrlicht/"
	rm -f "irrlicht-1.8.4.zip"
	echo "DONE: If successful run 'make'"

.PHONY: all all_win32 clean clean_linux clean_win32 static_win32 re install
