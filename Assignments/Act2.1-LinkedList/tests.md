# Evidencias de Pruebas - Linked List ADT

**Prueba 1: Creación de Lista y Datos Aleatorios**
- Entrada: Tipo 1 (int), Llenado 2 (Aleatorio)
- Salida esperada: Estructura de datos válida con 5 elementos.
- Resultado: `83 -> 86 -> 77 -> 15 -> 93 -> NULL` (Éxito)

**Prueba 2: addFirst (Opción 1)**
- Entrada: Valor = 10
- Resultado: `10 -> 83 -> 86 -> 77 -> 15 -> 93 -> NULL` (Éxito)

**Prueba 3: addLast (Opción 2)**
- Entrada: Valor = 99
- Resultado: `10 -> 83 -> 86 -> 77 -> 15 -> 93 -> 99 -> NULL` (Éxito)

**Prueba 4: insert (Opción 3)**
- Entrada: Índice = 2, Valor = 50
- Resultado: `10 -> 83 -> 50 -> 86 -> 77 -> 15 -> 93 -> 99 -> NULL` (Éxito)

**Prueba 5: deleteData (Opción 4)**
- Entrada: Valor a borrar = 77
- Resultado: Imprime "Borrado exitoso" (Regresa Verdadero). La lista queda: `10 -> 83 -> 50 -> 86 -> 15 -> 93 -> 99 -> NULL` (Éxito)

**Prueba 6: deleteAt (Opción 5)**
- Entrada: Índice = 0 (Borrar el 10)
- Resultado: Imprime "Borrado exitoso" (Regresa Verdadero). La lista queda: `83 -> 50 -> 86 -> 15 -> 93 -> 99 -> NULL` (Éxito)

**Prueba 7: getData y findData (Opciones 6 y 9)**
- Entrada: Índice = 2 para getData, Valor = 93 para findData.
- Resultado: `getData` arrojó `86`. `findData` arrojó índice `4`. (Éxito)

**Prueba 8: updateData y updateAt (Opciones 7 y 8)**
- Entrada: En updateData (viejo=83, nuevo=8). En updateAt (índice=3, valor=20).
- Resultado: Ambos actualizan con éxito. La lista cambia a `8 -> 50 -> 86 -> 20 -> 93 -> 99 -> NULL`. (Éxito)

**Prueba 9: Sobrecarga operador [ ] y operador = (Opciones 10 y 11)**
- Entrada: Actualizar índice 1 con `[]` (nuevo valor=55) y duplicar lista.
- Resultado: Al duplicar, se imprime la copia exacta en otra dirección de memoria: `8 -> 55 -> 86 -> 20 -> 93 -> 99 -> NULL`. (Éxito)

**Prueba 10: Validación y Excepciones Out_Of_Range**
- Entrada: Intentar `deleteData(100)` (no existe) e intentar `getData(20)`.
- Resultado: `deleteData` regresa Falso. `getData` lanza la excepción e imprime `Excepcion Out_Of_Range capturada: Indice fuera de rango`. El programa continúa corriendo. (Éxito)