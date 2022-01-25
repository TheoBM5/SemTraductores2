
  # Analizador Lexico #
  
  En base a la anterior practica sobre el mini generador lexico se tenia que hacer un analizador lexico con mas tokens.

[![Analizador-Lexico.png](https://i.postimg.cc/KjxQnJHH/Analizador-Lexico.png)](https://postimg.cc/gXtvpqdV)

Para realizar esta practica se tomo como referencia la siguiente tabla:


| Simbolo        | Tipo           |   |
| ------------- |:-------------:| -----:|
| Identificador | 0 | |
| Entero      |  1  |    |
| Real |  2  |    |
| Cadena | 3 |
| Tipo | 4 | int, float , void |
| opSuma | 5 | + , - |
| opMul | 6 | * , / |
| opRelac | 7 | <, <=, >, >= |
| opOr | 8 | || |
| opAnd | 9 | && |
| opNot | 10 | ! |
| opIgualdad | 11 | == , != | 
| Punto y coma ; | 12
| Coma , | 13
| Parantesis ( | 14
| Parantesis ) | 15
| LLave { | 16
| LLave } | 17
| Asignacion = | 18
| Palabra reservada if | 19
| Palabra reservada while | 20
| Palabra reservada return | 21
| Palabra reservada else | 22
| Fin de la cadena $ | 23

  # Proceso #
  
  El analizador funciona correctamente, se validaron todos lo caracteres que se mencionan en la tabla 
  tengo simplificar u ordenar el codigo creo que quedo muy disperso, ademas la salida parace algo desordenada. 
  
