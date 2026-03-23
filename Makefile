.PHONY: build run all clean format

build:
	cmake -G Ninja -S . -B build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build/

run:
	./build/bin/Chess

all: build run

clean:
	rm -rf build/

format:
    format:
	find src -type f \( -name "*.cpp" -o -name "*.hpp" \) -not -path "*/build/*" -print0 | xargs -0 clang-format -i -style=Microsoft
