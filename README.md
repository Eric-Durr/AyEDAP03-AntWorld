# AyEDA P03 - Mundo Hormiga

Es un programa en C++ que implementa una versión clásica del autómata celular conocido como la Hormiga de Langton.

## Uso

### **Compilación del ejecutable**

```bash
$ make
```

### **Ejecución del programa**

### **Lanzamiento de los tests**

```bash
$ make test
```

Se compila y ejecuta el conjunto de tests para luego ejecutarlos, de suceder satisfactoriamente debe aparecer lo siguiente por terminal:

```bash
Making tests: hormiga_langton_test
g++ -o hormiga_langton_test ./src/entorno.cpp ./src/hormiga.cpp ./test/includer.test.cpp
./hormiga_langton_test
===============================================================================
All tests passed (38 assertions in 2 test cases)
```

También se puede ejecutar un despliegue detallado de los tests si ya se ha lanzado el comando anterior:

```bash
$ ./hormiga_langton_test -s
```

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Autoría

- Eric Dürr Sierra - [alu0101027005](alu0101027005@ull.edu.es)
