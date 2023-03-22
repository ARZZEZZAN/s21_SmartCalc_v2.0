CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -UQT_MACRO -c
GCOV=--coverage
OUTNAME=tests
APP = build/ArmenianCalculator2022.app 


all: build static

.PHONY: qmake
qmake:
	mkdir -p build && cd build && qmake .. 

.PHONY: build
build: qmake
	cd build && make

.PHONY: static
static:
	ar rc calculator.a ./build/CalculatorModel.o ./build/controller.o
	ranlib calculator.a

.PHONY: tests
tests:
	gcc ./Unit_Test/unit_tests.cc ./Model/CalculatorModel.cc -lstdc++ -lgtest -std=c++17 -Wall -Werror -Wextra -o tests
	cd ./Unit_Test
	./tests
	
.PHONY: install
install: build
	@mkdir $(HOME)/Desktop/SmartCalc_v2.0/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc_v2.0/
	make clean

.PHONY: clean
clean:
	rm -rf build ./*.o ./*.a ./a.out ./*.tar ./*.gcno ./*.gcda ./gcov_report *.info ./*.info tests

.PHONY: uninstall
uninstall:
	@rm -rf build*
	@rm -rf $(HOME)/Desktop/SmartCalc_v2.0


.PHONY: dist
dist:
	mkdir SmartCalc_v2.0/
	mkdir SmartCalc_v2.0/src
	cp Makefile Controller/* Info/* Model/* Unit_Test/* View/* *.pro *.user *.cpp *.h SmartCalc_v2.0/src/
	tar cvzf SmartCalc_v2.0.tgz SmartCalc_v2.0/
	mv SmartCalc_v2.0.tgz $(HOME)/Desktop/
	rm -rf SmartCalc_v2.0/

.PHONY: dvi
dvi:
	open ./Info/info.html
	# pdflatex ./Info/info.html