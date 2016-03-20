CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = creature.o hero.o item.o location.o quest1.o quest2.o quest3.o quest4.o quest5.o randomshop.o healingfountain.o forrestencounter.o fieldencounter.o swampencounter.o mountainencounter.o fight.o main.o healingpotion.o elixir.o sword.o shield.o

SRCS = creature.cpp hero.cpp item.cpp location.cpp quest1.cpp quest2.cpp quest3.cpp quest4.cpp quest5.cpp randomshop.cpp healingfountain.cpp forrestencounter.cpp fieldencounter.cpp swampencounter.cpp mountainencounter.cpp fight.cpp main.cpp healingpotion.cpp elixir.cpp sword.cpp shield.cpp

HEADERS = creature.h hero.h item.h location.h quest1.h quest2.h quest3.h quest4.h quest5.h randomshop.h healingfountain.h forrestencounter.h fieldencounter.h swampencounter.h mountainencounter.h fight.h healingpotion.h elixir.h sword.h shield.h

PROGS = quest

all: ${PROGS}

quest: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o quest

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${PROGS}
	rm -f ${PROGS} ${OBJS}
