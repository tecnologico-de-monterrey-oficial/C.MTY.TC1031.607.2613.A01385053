# Reflexión Personal - Evidencia 2: Actividad Integral de Estructuras de Datos Lineales

## 1. Aprendizajes Clave
El desarrollo de esta actividad integradora me permitió consolidar de manera práctica los conceptos teóricos relacionados con las estructuras de datos dinámicas y el manejo de memoria en C++. Implementar desde cero elementos fundamentales como nodos, listas simplemente ligadas, pilas, colas y, de manera primordial, la **lista doblemente ligada**, me brindó un entendimiento profundo sobre cómo operan los apuntadores a nivel de bajo nivel. 

Asimismo, aprendí a valorar la importancia de la eficiencia algorítmica al procesar grandes volúmenes de datos no estructurados o semi-ordenados (como los archivos de *logs* de red). Comprender cómo transformar cadenas de texto en marcas de tiempo (`timestamps`) numéricas para facilitar comparaciones precisas demostró ser una habilidad indispensable en el desarrollo de software orientado al rendimiento.

## 2. Justificación de las Estructuras de Datos en la Aplicación
Dentro de la arquitectura del procesador de *logs*, cada estructura cumple un rol específico justificado por su comportamiento operativo:

*   **Lista Doblemente Ligada (`DoublyLinkedList`):** Es la estructura vertebral del sistema. A diferencia de una lista simple, los nodos cuentan con un apuntador adicional hacia atrás (`prev`), lo que permite el recorrido bidireccional de los registros. Esto es especialmente crítico para la **Opción 4 (mostrar registros por IP en orden descendente)**, ya que permite iniciar la lectura desde el final de la lista (`tail`) hacia el principio (`head`) de forma directa y eficiente sin necesidad de invertir estructuras auxiliares o realizar múltiples recorridos complejos.
*   **Ventajas y desventajas de la lista doblemente ligada:** Su principal **ventaja** es la flexibilidad de navegación en ambas direcciones y la facilidad para realizar operaciones de inserción o eliminación si se cuenta con la referencia del nodo. Su principal **desventaja** radica en el uso adicional de memoria, ya que cada nodo requiere almacenar un apuntador extra por elemento en comparación con una lista simple.

## 3. Complejidad Algorítmica y Rendimiento de Ordenamiento
El procesamiento de los archivos de *logs* requirió el uso de algoritmos de ordenamiento basados en cronología. Analizando el comportamiento del algoritmo utilizado (como `std::sort` basado en IntroSort / QuickSort/HeapSort) y su relación con la complejidad:

*   **Profundidad de la pila de llamadas:** En algoritmos divide y vencerás (como Merge Sort o Quick Sort), la profundidad máxima de la recursión está estrechamente relacionada con la altura del árbol de llamadas, operando típicamente en una complejidad de orden $O(\log n)$. 
*   **Impacto del pivote:** En implementaciones de Quick Sort, la elección del pivote determina el rendimiento general. Si el pivote divide el conjunto de datos de manera equitativa, la complejidad se mantiene en $O(n \log n)$ con una profundidad de recursión acotada. Sin embargo, en escenarios donde los datos presentan cierto desorden asimétrico (como los registros desfasados de múltiples servidores en `log607-1.txt`), un mal pivote podría degradar el rendimiento hacia el peor de los casos $O(n^2)$, incrementando drásticamente el número de comparaciones y la profundidad de la pila de llamadas, lo que justifica el uso de estrategias híbridas de ordenamiento para mitigar este impacto.

## 4. Conclusión y Mejora Continua
Esta actividad integradora me permitió visualizar la relación directa entre la teoría de estructuras de datos y la resolución de problemas de ingeniería del mundo real. Como mejora para futuros proyectos, considero valioso implementar desde las primeras etapas pruebas de rendimiento automatizadas para comparar de manera empírica el comportamiento de diferentes algoritmos de ordenamiento frente a conjuntos de datos masivos.