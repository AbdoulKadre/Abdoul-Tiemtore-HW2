all: coordinator checker

coordinator: coordinator.c
	gcc -o coordinator coordinator.c

checker: checker.c
	gcc -o checker checker.c

clean:
	rm -f coordinator checker

package:
	zip -r Abdoul-Tiemtore-HW2.zip coordinator.c checker.c Makefile README.txt
