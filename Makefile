CXX = g++
CXXFLAGS = -Wall -ItemperatureOven -ItemperatureTank

SRC = main.cpp \
      temperatureOven/temperatureOven.cpp \
      temperatureTank/temperatureTank.cpp

OUT = pidControl

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
