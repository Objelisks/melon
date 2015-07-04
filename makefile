#CXX=g++
ROOT=../..
POLYCODE=Release/Linux/Framework
CXXFLAGS=-std=c++11 -I$(ROOT)/$(POLYCODE)/Core/Dependencies/include -I$(ROOT)/$(POLYCODE)/Core/Dependencies/include/AL -I$(ROOT)/$(POLYCODE)/Core/Dependencies/include/freetype2 -I$(ROOT)/$(POLYCODE)/Core/include -I$(ROOT)/$(POLYCODE)/Modules/include -I$(ROOT)/$(POLYCODE)/Modules/Dependencies/include -I$(ROOT)/$(POLYCODE)/Modules/Dependencies/include/bullet
LDFLAGS=-lrt -ldl -lpthread $(ROOT)/$(POLYCODE)/Core/lib/libPolycore_d.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/libfreetype.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/liblibvorbisfile.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/liblibvorbis.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/liblibogg.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/libopenal.so $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/libphysfs.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/libpng15.a $(ROOT)/$(POLYCODE)/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL $(ROOT)/$(POLYCODE)/Modules/lib/libPolycode2DPhysics_d.a $(ROOT)/$(POLYCODE)/Modules/Dependencies/lib/libBox2D.a $(ROOT)/$(POLYCODE)/Modules/lib/libPolycode3DPhysics_d.a $(ROOT)/$(POLYCODE)/Modules/Dependencies/lib/libBulletDynamics.a $(ROOT)/$(POLYCODE)/Modules/Dependencies/lib/libBulletCollision.a $(ROOT)/$(POLYCODE)/Modules/Dependencies/lib/libLinearMath.a -lX11

OBJS = player.o melon.o level.o sword.o

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o melon $(LDFLAGS)

clean:
	rm *.o melon
