# Analizador sintactico #
En esta practica se implemento el codigo del analizador sintactico, se siguio el algoritmo visto en clase donde segun la regla se ingresaban
valores a la pia o se desapilaban.

Una vez que se llegaba a la parte de desapilar lo que realice fue llamar a una funcion reglas en la cual se tiene un switch
con clases de cada una de las reglas que contiene los archivos proporcionados. 
Por cada regla se creo una clase que heredaba de la clase nodo. cada uno de de estos apuntaban al nodo nodo o reglar anterior, como una lista simplemente
ligada, una vez que todo el proceso fue realizado se llama al metodo muestra, haciendo uso de polimorfismo se logro que en cada llamada al metodo muestre 
se imprimiera de acuerdo a su regla

[![Sintactico.png](https://i.postimg.cc/RVccTqNK/Sintactico.png)](https://postimg.cc/F7HdrrbH)
