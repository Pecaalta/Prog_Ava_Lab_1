# Informacion a saber
	> #ifdef linux , WIN32, _WIN32
Semejante a if en tiempo de compilación.
Linux, WIN32, _WIN32 son predefinido de la marca del sistema.
Se utilizan en los .h para no compilar un mismo archivo, de no estar declarada la declara abajo para no volver a entrar al mismo código.
Además de las librerías estando se importó en el caso de Linux sys/ioctl.h para poder utilizar winsize, ioctl, TIOCGWINSZ encargadas en conseguir el tamaño de la consola y poder ajustar el ancho de los títulos a este, además "\033]0;" y "\007" consiguen en Linux ubicar el título de la consola.

## Funciones
Los objetos fueron realizados en archivos separados.
Las funciones de la letra fueron realizadas en los archivos Funciones.h / Funciones.cpp

* 	Crea un nuevo socio en el sistema.
	Booleano lleno determina si existió oportunidad de registrar al nuevo socio.
	De encontrar id levanta la excepción invalid_argument

	> void agregarSocio(string ci, string nombre);

* 	Se elaboró una sobrecarga para lograr aceptar los dos subtipos de clase.
	Se utiliza el mismo método que la función anterior añadiendo la destrucción de la clase argumento DtSpinning o DtEntrenamiento.
	
	> void agregarClase(DtClase& clase);

* 	Recorrerá todas las clases y socios buscando coincidencias, de no hacerlo levantará la correspondiente excepción (La búsqueda se realiza por el id/ci).
	Antes de la creación de la nueva inscripción se verifica una inscripción previa y/o cupos llenos.
	Si esta disponible para inscribirse se procede la inscripción.  
	
	> void agregarInscripcion(string ciSocio, int dClase, Fecha fecha);

* 	Recorrerá todas las clases buscando el id correcto, levantando excepción si no la encuentra o si no existe un socio inscripto a la clase encontrada.
	
	> void borrarInscripcion(string ciSocio, int dClase);

* 	Buscará la clase de encontrarla llamará a la operación deleteInscripcion la cual tendrá un método diferente para cada hijo debido a las limitaciones de cupos. 

	> DtSocio* *  obtenerInfoSociosPorClase (int dClase, int cantSocios);
	
* 	Busca la clase señalada, si no la encuentra o la cantidad de registros solicitada excede a los cupos levantara excepción, si no solicita a la clase esos registros de inscripciones.

	> DtClase& obtenerClase(int idClase);

*	Recorre todas las clases, crea y retorna un objeto DtClase con los datos de la clase seleccionada.
Una observación a destacar es q la compilación retorna una advertencia por devolver una dirección de memoria.

## Pruebas Superadas
* Socios
	* Creación
	* Verificar duplicados
	* Listado
	* No haber Socios
* Clases
	* Creación
	* Verificar duplicados
	* Listado
	* Verificar de limites
* Inscripciones
	* Creación
		* id invalido
		* ci invalido
		* Exceder cupos
	* Verificar duplicados
	* Borrado
	* Listado
	* Errores
		* día>31
		* día<01
		* mes>12
		* mes<01
		* año<1900
	* Mostrar inscriptos por clases
	* Otros errores
		* No haber inscripciones
		* Solicitar mas registros q los cupos
		* Borrado del primer registro
		* Borrado del último registro
		* Borrado de registro rondón
		* Borrado de registros consecutivos
* Listado de Socios
* Listado de Clases
* Salir.