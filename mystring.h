/**
 *  MYSTRING.H
 *
 *  Librería básica de manejo de cadenas.
 *
 *  Autor: Jardón Fonseca Bruno
 *  https://github.com/bjardon
 *
 */

#ifndef PRACTICA01_MANEJOCADENAS_MYSTRING_H
#define PRACTICA01_MANEJOCADENAS_MYSTRING_H

/** DEPENDENCIAS **/

// Requerido para la alocación de memoria
#include <stdio.h>
#include "stdlib.h"

/** ALIAS **/

// Definición del alias string
typedef char * string;

/** PROTOTIPOS **/

// Inicialización de una cadena
void str(string *);
// Cálculo de la longitud de una cadena
int str_length(string);
// Copia de una cadena origen a una cadena destino
void str_copy(string, string);
// Concatenación de una cadena origen a una cadena destino
void str_concat(string, string);
// Extracción de un prefijo de longitud dada de una cadena origen a una cadena destino
void str_prefix(string, string, int);
// Extracción de un sufijo de longitud dada de una cadena origen a una cadena destino
void str_suffix(string, string, int);
// Extracción de una subcadena dadas las longitudes del prefijo y el sufijo a una cadena destino
void str_substr(string, string, int, int);
// Obtención de una subsecuencia
void str_subseq(string, string, char [], int);
// Inversión del orden de una cadena origen a una cadena destino
void str_invert(string, string);
// Determina si un arreglo de n elementos contiene un elemento dado
int arr_contains(char, char [], int);

/** DEFINICIÓN DE FUNCIONES **/

/**
 * Inicialización de una cadena
 *
 * Recibe:
 *  str [string]:
 *   Referencia a la cadena que se va a inicializar
 *
 * Retorna:
 *  [void]
 */
void str(string * str) {
    *str = (string)malloc(255);
}

/**
 * Cálculo de la longitud de una cadena
 *
 * Recibe:
 *  str [string]:
 *   Cadena a la que se le calculará la longitud
 *
 * Retorna:
 *  [int]:
 *   Longitud de la cadena
 */
int str_length(string str) {
    int i = 0;
    while (*(str + i) != 0)
        i++;
    return i;
}

/**
 * Copia de una cadena origen a una destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *
 * Retorna:
 *  [void]
 */
void str_copy(string destination, string origin) {
    int i = 0;
    while (*(origin + i) != 0) {
        *(destination + i) = *(origin + i);
        i++;
    }
    *(destination + i) = 0;
}

/**
 * Concatenación de una cadena origen a una destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *
 * Retorna:
 *  [void]
 */
void str_concat(string destination, string origin) {
    int i = 0;
    int j = str_length(destination);
    while (*(origin + i) != 0) {
        *(destination + j) = *(origin + i);
        i++;
        j++;
    }
}

/**
 * Extracción de un prefijo de longitud dada de una cadena origen a una destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *  prefix_length [int]:
 *   Longitud del prefijo
 *
 * Retorna:
 *  [void]
 */
void str_prefix(string destination, string origin, int prefix_length) {
    int i;
    if(prefix_length > str_length(origin) || prefix_length < 0) {
        str_copy(destination, "[El prefijo no pudo ser generado]");
        return;
    }
    for (i = 0; i < prefix_length; ++i) {
        *(destination + i) = *(origin + i);
    }
}

/**
 * Extracción de un sufijo de longitud dada de una cadena origen a una destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *  suffix_length [int]:
 *   Longitud del sufijo
 *
 * Retorna:
 *  [void]
 */
void str_suffix(string destination, string origin, int suffix_length) {
    int i, j = 0;
    if(suffix_length > str_length(origin) || suffix_length < 0) {
        str_copy(destination, "[El sufijo no pudo ser generado]");
        return;
    }
    for (i = str_length(origin) - suffix_length; i < str_length(origin); ++i) {
        *(destination + j) = *(origin + i);
        j++;
    }
}

/**
 * Extracción de una subcadena dadas las longitudes del prefijo y el sufijo a una cadena destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *  offset_left [int]:
 *   Longitud del prefijo
 *  offset_right [int]:
 *   Longitud del sufijo
 *
 * Retorna:
 *  [void]
 */
void str_substr(string destination, string origin, int offset_left, int offset_right) {
    int i, j = 0;
    if(offset_left < 0 || offset_right < 0 || offset_left +  offset_left > str_length(origin))
        return;
    for (i = offset_left; i < str_length(origin) - offset_right; ++i) {
        *(destination + j) = *(origin + i);
        j++;
    }
}


/*
 * Obtención de una subsecuencia de una cadena
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *  remove [char_arr]:
 *   Arreglo de elementos a quitar
 *  length [int]:
 *   Tamaño del arreglo de elementos a quitar
 *
 * Retorna:
 *  [void]
 */
void str_subseq(string destination, string origin, char remove[], int length) {
    int i, offset = 0;

    for (i = 0; i < str_length(origin); ++i)

        if (arr_contains(*(origin + i), remove, length))
            offset++;
        else
            *(destination + i - offset) = *(origin + i);

    *(destination + i) = 0;
}

/*
 * Inversión del orden de una cadena origen a una cadena destino
 *
 * Recibe:
 *  destination [string]:
 *   Cadena destino
 *  origin [string]:
 *   Cadena origen
 *
 * Retorna:
 *  [void]
 */
void str_invert(string destination, string origin) {
    int i, j = 0;
    for (i = str_length(origin) - 1; i >= 0; --i) {
        *(destination + j) = *(origin + i);
        j++;
    }
}

/*
 * Determina si un caracter se encuentra en un arreglo de caracteres
 *
 * Recibe:
 *  character [char]:
 *   caracter a comparar
 *  array [char_arr]:
 *   arreglo de caracteres
 *  length [int]:
 *   longitud del arreglo
 *
 * Retorna:
 *  [bool]
 */
int arr_contains(char character, char array[], int length) {
    int i;
    for(i = 0; i < length; ++i) {
        if(array[i] == character)
            return 1;
    }
    return 0;
}


#endif //PRACTICA01_MANEJOCADENAS_MYSTRING_H
