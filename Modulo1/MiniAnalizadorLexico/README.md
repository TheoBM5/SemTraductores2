
# Mini generador léxico #


En esta primera practica se realizo un mini analizador lexico. Los tokens que validara tanto valores reales asi como identificadores. 
El numero de token de cada caracter sera de acuerdo al pdf que esta en la practica correspondiente

[![MInianalizador.png](https://i.postimg.cc/2SdTydt9/MInianalizador.png)](https://postimg.cc/dh1GSCwG)

Para validar los identificadores y los valores reales se tomo encuenta que 
> identificadores = letra(letra|digito)*

> Real = entero.entero+

# Procedimiento # 
Primero corri el codigo que proporciono el profesor, cambie la cadena de entrada para ver que mas podia dar por salida. 
Posterirormente comence a leer el codigo empezando por el .h y despues el .cpp. Comprendi la funcion de algunas de las funciones y comence 
a modificar el automata para que aceptara numeros.
Una vez que el automata funcione con numeros empece a pensar en como podria aceptar reales, por lo cual cuando el automata recibiera un punto pasaria
a otro estado donde en caso de que el siguiente caracter fuera un numero pasaria al estado de aceptacion. Por el contrario si el siguiente
caracter al punto no fuera un numero, entonces retrocederia para separar el caracter punto del resto del numero.
Para los identificadores realice algo parecido, si entra un caracter al automata pasara a otro estado, en ese estado estara validando que los caracteres
sean letras, numeros y ciertos caracteres. Cuando se ingresa un caracter no valido entonces el identificador se imprime en la salida. 
