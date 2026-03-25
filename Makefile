.PHONY: build run all format clean release compile

compile:
	cmake -G Ninja -S . -B build/ -DCMAKE_BUILD_TYPE=Release
	cmake --build build

play: compile
	./build/bin/Chess

build:
	cmake -G Ninja -S . -B build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

run:
	./build/bin/Chess

all: build run

format:
	clang-format -i src/main.cpp
	clang-format -i src/functionality/*.hpp

format_assets:
	clang-format -i src/assets/*.h

clean:
	rm -rf build/
