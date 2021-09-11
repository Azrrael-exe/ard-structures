#include <bufferCircular.h>
#include <stdio.h>
#include <stdlib.h>

Buffer::Buffer(int size)
{
    this->list = new int[size];
    this->in_index = 0;
    this->out_index = 0;
    this->size = size;
    this->free_slots = size;
}
bool Buffer::add(int value)
{
    this->list[this->in_index] = value;
    if (this->free_slots > 0)
    {
        this->free_slots--;
    }
    else
    {
        this->free_slots = 0;
    }
    // Aumentar el indice de entrada
    if ((this->in_index + 1) == this->size)
    {
        this->in_index = 0;
    }
    else
    {
        this->in_index++;
    }
    // Contar espacios libres
    if (this->free_slots == 0)
    {
        this->out_index = this->in_index;
    }
    return true;
}

int Buffer::remove()
{
    if (this->free_slots < this->size)
    {
        int value = this->list[this->out_index];
        if (this->out_index + 1 == this->size)
        {
            this->out_index = 0;
        }
        else
        {
            this->out_index++;
        }

        this->free_slots++;
        return value;
    }
    else
    {
        return -1;
    }
}

int Buffer::inIndex()
{
    return this->in_index;
}

int Buffer::outIndex()
{
    return this->out_index;
}

int Buffer::freeSlots()
{
    return this->free_slots;
}

float BufferStat::avg()
{
    float average = 0.0;
    for (int i = 0; i < this->size; i++)
    {
        average += this->list[i]; // Sumamos todos los valores
    }
    return average / this->size; // Sacamos el promedio
}

int BufferStat::max()
{
    int maximo = this->list[0]; // Iniciamos el maximo como el primer valor
    for (int i = 0; i < this->size; i++)
    {
        if (maximo < this->list[i])
        {
            maximo = this->list[i]; // Guardamos el mayor por el momento
        }
    }
    return maximo;
}

int BufferStat::min()
{
    int minimo = this->list[0]; // Iniciamos el minimo como el primer valor
    for (int i = 0; i < this->size; i++)
    {
        if (minimo > this->list[i])
        {
            minimo = this->list[i]; // Guardamos el menor por el momento
        }
    }
    return minimo;
}

// Compara los valores para luego ordenar
int funcionQueCompara(const void *a, const void *b)
{
    // Castear a enteros
    int aInt = *(int *)a;
    int bInt = *(int *)b;
    // Al restarlos, se debe obtener un número mayor, menor o igual a 0
    // Con esto ordenamos de manera ascendente
    return bInt - aInt;
}

int BufferStat::moda()
{
    int count = 0;
    int maxCount = 0;
    int valModa = this->list[0];
    for (int i = 0; i < this->size; i++)
    {
        count = 0;
        for (int j = 0; j < this->size; j++)
        {
            if (this->list[i] == this->list[j] && i != j)
            {
                count += 1;
            }
        }
        if (count >= maxCount)
        {
            maxCount = count; //guardamos el mayor por el momento
            valModa = this->list[i];
        }
    }
    return valModa;
}

void BufferStat::intercambiar(int *a, int *b)
{
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int* BufferStat::burbuja()
{
    int* arreglo = this->list; // Se crea copia para no desordenar el buffeer circular
    for (int i = 0; i < this->size; i++)
    {
        // Recuerda que el -1 es porque no queremos llegar al final ya que hacemos
        // un indiceActual + 1 y si fuéramos hasta el final, intentaríamos acceder a un valor fuera de los límites
        // del arreglo
        for (int indiceActual = 0; indiceActual < this->size - 1;
            indiceActual++)
        {
            int indiceSiguienteElemento = indiceActual + 1;
            // Si el actual es mayor que el que le sigue a la derecha...
            if (arreglo[indiceActual] > arreglo[indiceSiguienteElemento])
            {
                // ...intercambiarlos, es decir, mover el actual a la derecha y el de la derecha al actual
                intercambiar(&arreglo[indiceActual], &arreglo[indiceSiguienteElemento]);
            }
        }
    }
    return arreglo;
}

int BufferStat::median()
{
    int* arreglo = burbuja(); // Ordenamos la lista
    int mitad = this->size / 2;
    float mediana;
    // Después vemos si la longitud es par
    if (this->size % 2 == 0) {
        // Debemos promediar los valores del centro
        mediana = (arreglo[mitad - 1] + arreglo[mitad]) / 2;
    } else {
        mediana = arreglo[mitad];
    }
    return mediana;
}