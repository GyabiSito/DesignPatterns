# ☕ Design Patterns Playground

Este repo es el resultado de ir aplicando, uno a uno, los patrones de diseño que fui aprendiendo durante el curso de Java Design Patterns que me pidió IBM.

No me los fumé todos de memoria, sino que a medida que veía los videos, los iba implementando y adaptando a casos reales o ejercicios. En la mayoría está todo hecho en Java, pero algunos los tuve que resolver en C++ por cuestiones de la facu (spoiler: C++ me recuerda que la vida sin garbage collector es más dura).

---

## 🤗 Tecnologías

* **Java**: lenguaje principal para la mayor parte de los patrones
* **C++**: algunos patrones aislados implementados en este lenguaje por requerimientos universitarios
* **VSCode + IntelliJ**: IDEs utilizados

---

## 📂 Estructura

* `/Java`: todos los patrones implementados en Java
* `/Cpp`: patrones que resolví en C++

---

## 🎨 Algunos patrones que me marcaron

### 🧼 Flyweight

Imaginá un juego con una baraja de cartas española. En lugar de crear una nueva instancia cada vez que se necesita una carta —o incluso una carta boca abajo que es siempre igual—, el patrón Flyweight te permite reutilizar instancias compartidas para representar esos elementos. Así ahorrás memoria y evitás redundancia, simplemente apuntando a un objeto ya existente en memoria. Ideal para cuando tenés muchos objetos similares con estado inmutable.

### 🛡️ Method Chain

Lo usé en un ejemplo de TCG (trading card game), para que una carta tenga efectos encadenados tipo `aumentarAtaque().duplicarDaño().activarEfectoFinal()`. Clarito, expresivo, y hermoso.

### 🔐 NullLog

Ideal para situaciones donde querés evitar que el sistema crashee por no tener un logger configurado. En mi caso, lo usé para manejar logs en capas sensibles de seguridad: si no hay logger, se ignora sin drama.

### 📃 Memento

Aplicado a backups. El patrón Memento me permitió guardar snapshots de objetos complejos para restaurarlos en caso de errores. Muy útil cuando implementás "deshacer cambios".

### 👩‍🏫 Decorator

Uno de mis preferidos. Acá tuve mi epifanía con Angular: `@Component`, `@Injectable`, `@Input`, `@Output`... todo es un maldito *decorator*! Implementé versiones propias para entenderlo bien.

### 📁 Composite

Perfecto para representar carpetas y archivos. Cada carpeta puede tener archivos o subcarpetas, y todo implementa una misma interfaz. Me ayudó a entender bien la recursividad en estructuras jerárquicas.

---

## 📊 Angular y los Decorators

Angular hace uso intensivo del patrón **Decorator**, basado en la sintaxis de TypeScript. Pero ojo: no es magia negra, es simplemente una función que se ejecuta y le mete metadata a la clase que tenés debajo.

Por ejemplo, esto:

```typescript
@Component({ selector: 'mi-app', template: '...' })
class MiComponente {}
```

es lo mismo que escribir:

```typescript
class MiComponente {}
Component({ selector: 'mi-app', template: '...' })(MiComponente);
```

### 🌀 ¿De dónde sale el `@Component`?

`@Component` es un decorator: una función que recibe la clase como argumento y le mete metadata. Esa metadata la usa Angular para saber cómo renderizar el componente. Es una funcionalidad de TypeScript, inspirada en anotaciones de Java.

### 🧠 ¿Y qué es Reflect?

Angular usa `reflect-metadata`, una librería que permite asociar metadata a clases. No es parte nativa de JS, pero se usa en desarrollo para leer tipos y decoraciones.

Ejemplo:

```typescript
import 'reflect-metadata';

function Component(metadata: any) {
  return function (target: Function) {
    Reflect.defineMetadata('component:metadata', metadata, target);
  }
}

@Component({ selector: 'mi-app', template: '<h1>Hola</h1>' })
class MiComponente {}

const meta = Reflect.getMetadata('component:metadata', MiComponente);
console.log(meta); // { selector: 'mi-app', template: '...' }
```

### 🔍 ¿Cuándo se usa Reflect en Angular?

* En **desarrollo**, Angular usa `reflect-metadata` para leer la metadata de tipos y decorators.
* En **producción**, esa info se elimina porque Angular compila todo con AOT (Ahead-of-Time) y genera código estático optimizado.

Entonces:

* ✅ En tu app o librería con decorators personalizados: necesitás `reflect-metadata`
* ❌ En producción: Angular no lo usa más, ya fue reemplazado por código compilado

### 📌 Angular vs Java (Spring)

| Aspecto         | Angular (TypeScript)                 | Java (Spring)                          |
| --------------- | ------------------------------------ | -------------------------------------- |
| Sintaxis        | `@DecoratorName(...)`                | `@AnnotationName(...)`                 |
| Base técnica    | Funciones de alto orden + metadata   | Interfaces + procesadores de anotación |
| Propósito común | DI, componentes, servicios           | DI, validación, serialización, etc.    |
| Flexibilidad    | Decorar clases, propiedades, métodos | Generalmente clases, métodos, campos   |
| Personalización | Crear decorators propios fácilmente  | Más estructurado y controlado          |

La diferencia clave es que en Angular, `@Component` define **qué se renderiza**. En Java, `@Component` marca una clase como **inyectable**, sin ningún vínculo visual.

---

## ✨ Otros patrones implementados

> ⚙️ *Nota: algunos patrones como `Interpreter (243)`, `Template Method (325)`, `Adapter (class) (139)` y `Factory Method` son considerados patrones de clase, ya que definen relaciones entre clases mediante herencia. A diferencia del resto, que tienen alcance a nivel de objeto y permiten relaciones más dinámicas en tiempo de ejecución.*

* **Creacionales**: Factory, Abstract Factory, Factory Method (class), Singleton, Builder, Prototype
* **Estructurales**: Adapter (class), Bridge, Composite, Decorator, Facade, Flyweight, Proxy
* **Comportamiento**: Chain of Responsibility (MethodChain), Command, Interpreter (243), Iterator, Mediator, Memento, Observer, State, Strategy, Template Method (325), Visitor, Null Object

---

## ⚡️ Bonus: principios SOLID

Incluí también ejemplos para cada uno de los principios SOLID, porque si vamos a hablar de diseño, más vale arrancar con bases sólidas.

---

## ✍️ Nota final

Este repo no es solo una colección de patrones, es una forma de internalizarlos, no tan a profundidad y no con muchos juntos en 1 solo proyecto, sino mas bien son el primer paso para aprenderlos.

Dale que va 🚀
