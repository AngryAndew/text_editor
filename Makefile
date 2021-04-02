all: 
	g++ -o editor --std=c++11 \
		controller/command/*.cpp \
		controller/observer/*.cpp \
		controller/*.cpp \
		model/*.cpp \
		view/*.cpp \
		*.cpp \
		-I controller \
		-I controller/command \
		-I controller/observer \
		-I model \
		-I view