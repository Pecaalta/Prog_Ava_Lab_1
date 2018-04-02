
OBJETOS 	= objet/Fecha.o objet/DtSocio.o objet/DtClase.o objet/DtSpinning.o objet/DtEntrenamiento.o objet/Clase.o objet/Inscripcion.o objet/Spinning.o objet/Entrenaminto.o objet/Socio.o Funciones.o
FUENTES 	= main.cpp \ objet/Fecha.cpp objet/Fecha.h \ objet/DtSocio.cpp objet/DtSocio.h \ objet/DtClase.cpp objet/DtClase.h \ objet/DtSpinning.cpp objet/DtSpinning.h \ objet/DtEntrenamiento.cpp objet/DtEntrenamiento.h \ objet/Clase.cpp objet/Clase.h \ objet/Inscripcion.cpp objet/Inscripcion.h \ objet/Spinning.cpp objet/Spinning.h \ objet/Entrenaminto.cpp objet/Entrenaminto.h \ objet/Socio.cpp objet/Socio.h \ Funciones.cpp Funciones.h

CC 		= g++
OPCIONES 	= -Wall

ifeq ($(OS),Windows_NT)
	LIBS	= -L "C:/MinGW/lib" -I "C:/MinGW/include" -static-libgcc
	Nombre	= "Ejecutable.exe"
	RM 	= cmd /C del /s /q *.o *.exe *.out
else
	LIBS	=
	Nombre	= "Ejecutable.out"
	RM 	= rm -f $(OBJETOS) "main.o" $(Nombre) "Ejecutable.exe" "Primer Obligatorio.exe"
endif

$(Nombre): $(OBJETOS) main.o Makefile
	$(CC) $(OPCIONES) $(OBJETOS) main.cpp -o $(Nombre)

main.o: main.cpp $(OBJETOS)
	$(CC) -c main.cpp -o main.o $(LIBS)

objet/Fecha.o: objet/Fecha.cpp objet/Fecha.h
	$(CC) -c objet/Fecha.cpp -o objet/Fecha.o $(LIBS)

objet/DtSocio.o: objet/DtSocio.cpp objet/DtSocio.h
	$(CC) -c objet/DtSocio.cpp -o objet/DtSocio.o $(LIBS)

objet/DtClase.o: objet/DtClase.cpp objet/DtClase.h datos.h
	$(CC) -c objet/DtClase.cpp -o objet/DtClase.o $(LIBS)

objet/DtSpinning.o: objet/DtSpinning.cpp objet/DtSpinning.h objet/DtClase.o
	$(CC) -c objet/DtSpinning.cpp -o objet/DtSpinning.o $(LIBS)

objet/DtEntrenamiento.o: objet/DtEntrenamiento.cpp objet/DtEntrenamiento.h objet/DtClase.o
	$(CC) -c objet/DtEntrenamiento.cpp -o objet/DtEntrenamiento.o $(LIBS)

objet/Inscripcion.o: objet/Inscripcion.cpp objet/Inscripcion.h objet/Fecha.o objet/DtSocio.o
	$(CC) -c objet/Inscripcion.cpp -o objet/Inscripcion.o $(LIBS)

objet/Clase.o: objet/Clase.cpp objet/Clase.h datos.h objet/Inscripcion.o objet/Fecha.o
	$(CC) -c objet/Clase.cpp -o objet/Clase.o $(LIBS)

objet/Spinning.o: objet/Spinning.cpp objet/Spinning.h objet/Inscripcion.o objet/Clase.o
	$(CC) -c objet/Spinning.cpp -o objet/Spinning.o $(LIBS)

objet/Entrenaminto.o: objet/Entrenaminto.cpp objet/Entrenaminto.h objet/Inscripcion.o objet/Clase.o
	$(CC) -c objet/Entrenaminto.cpp -o objet/Entrenaminto.o $(LIBS)

objet/Socio.o: objet/Socio.cpp objet/Socio.h
	$(CC) -c objet/Socio.cpp -o objet/Socio.o $(LIBS)

Funciones.o: Funciones.cpp Funciones.h
	$(CC) -c Funciones.cpp -o Funciones.o $(LIBS)

clean:
	$(RM)

limpiar:
	$(RM)

reconstruir:
	make clean
	make

rebuild:
	make clean
	make
