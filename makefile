all: JaimePongameCinco.dat graficas.png 

%.png: %.dat graficas.png 
	python3 ultimo.py

%.dat: a.out
	./a.out

a.out: 30.cpp
	g++ 30.cpp 

clean:
	rm -rf *.x *.dat *.png
