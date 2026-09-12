¿Qué algoritmos lograste implementar con mayor facilidad gracias al apoyo de Copilot?

Bubble sort, Selection sort e Insertion sort, además del menú y la lógica de generación aleatoria.

¿En qué casos Copilot te dio soluciones correctas de inmediato y en cuáles tuviste que corregir o ajustar la propuesta?

Dio soluciones inmediatas en bucles e intercambios simples. Se tuvo que corregir en Merge Sort y Quick Sort para que respetaran la firma exacta vector<T>& usando funciones auxiliares internas en lugar de requerir límites en los parámetros públicos.

¿Consideras que Copilot te ayudó a ahorrar tiempo o más bien te obligó a pensar más sobre cómo funciona el algoritmo?

Ahorró tiempo en sintaxis repetitiva, pero requirió análisis detallado para registrar comparaciones e intercambios sin alterar los algoritmos recursivos y para estructurar la medición en nanosegundos.

Escribe un ejemplo concreto donde Copilot no resolvió el problema directamente y tuviste que razonar la solución:

Al armar las funciones recursivas de Merge Sort y Quick Sort, Copilot generaba llamadas que pedían índices left y right, incumpliendo la firma estándar requerida por la rúbrica; se tuvieron que implementar wrappers para encapsular la recursión.

¿Qué hubieras hecho diferente si no hubieras tenido acceso a Copilot para esta actividad?

Habría consultado en youtube, paginas de internet o notas de otras clases para escribir manualmente los casos base de recursión y la sintaxis de plantillas genéricas.