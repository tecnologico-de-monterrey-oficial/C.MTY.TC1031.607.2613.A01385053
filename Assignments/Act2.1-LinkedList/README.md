# Implementación de Linked List con Templates en C++

## Prompts utilizados

1. "Ayúdame a agregar la sobrecarga del operador `[]` (para obtener y para actualizar) y la sobrecarga del operador `=` para que duplique la lista copiando los nodos sin apuntar a la misma memoria."
2. "Hazme una estructura de switch-case para el main que pregunte si quiero una lista de ints o de strings, y me dé la opción de llenarla con 5 datos aleatorios o dejarla vacía para capturar a mano."

## Reflexión

**¿Qué parte del código te propuso la IA que aceptaste tal cual y por qué era correcta?**
Acepté tal cual la lógica base del operador `=` (copy assignment operator) y el destructor. Era correcta porque manejaba bien la limpieza de la memoria previa con un método `clear()` antes de copiar los nodos nuevos, evitando memory leaks, lo cual es muy tedioso de escribir desde cero.

**¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?**
Modifiqué la sobrecarga del operador `[]`. La IA propuso dos métodos diferentes (uno getter y un setter separado), pero lo cambié para que devolviera una referencia `T& operator[](int index)`. Verifiqué que era mejor probando en el menú: con una sola función pude hacer `list[0]` para leer y `list[0] = 5` para escribir sin tener código duplicado. También ajusté el generador aleatorio para strings porque me daba caracteres raros no imprimibles.

**¿Dónde se equivocó la IA (si ocurrió) y cómo lo detectaste?**
Se equivocó en el manejo de excepciones de los índices. Al principio, si le pedías el índice 10 en una lista de 3, el programa hacía crash porque intentaba acceder a un puntero nulo (`temp->data`). Lo detecté corriendo las pruebas del menú. Lo arreglé agregando un `if (!temp) throw std::out_of_range(...)`.

**¿Qué harías diferente si no tuvieras Copilot/ChatGPT?**
Habría tardado bastante más en armar el esqueleto completo del menú y las validaciones de tipos. Probablemente habría implementado el Template solo para enteros y luego habría batallado al querer adaptarlo a strings. El uso de la IA me ayudó a tener la estructura rápida para enfocarme en probar que los apuntadores realmente funcionaran.