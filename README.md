# TDAVector

## Descarga el repo

Para clonar el repo en tu computadora con `git`:
- Abrir una terminal
- Poner el comando: `git clone https://github.com/fiubaAlgo2/compilacion`
- Hacer `git checkout branchName`, con `branchName` el nombre de la branch que se desee usar

## Descargar el repo sin `git`

Situate en la branch y descarga el repo como .zip

## Branches:

- **initial-implementation**

	Implementacion del codigo inspirado en `std::vector`, con el concepto de `capacity`

- **operators-override**

	`initial-implementaton` + sobrecarga de operadores

- **simpler-implementation**

	Realoca memoria siempre que aumenta el tamanio del vector (mas costoso)


## Compilar el proyecto por terminal

```
g++ *.cpp -Werror -Wall -Wconversion
```

## Chequeo con valgrind

```
valgrind --leak-check=full          --show-leak-kinds=all          --track-origins=yes          --verbose          --log-file=valgrind-out.txt          ./a.out
```

