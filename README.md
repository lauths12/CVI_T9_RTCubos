Ray Tracing para varios Cubos
====================================================================================================

| ![RT in One Weekend][cover1] | ![RT The Next Week][cover2] | ![RT The Rest of Your Life][cover3] |
|:----------------------------:|:---------------------------:|:-----------------------------------:|
|   [In One Weekend][book1]    |   [The Next Week][book2]    |   [The Rest of Your Life][book3]    |

## 🎨 Créditos

Este proyecto se basa en los libros de **Peter Shirley**:

- **Ray Tracing in One Weekend**
- **Ray Tracing: The Next Week**
- **Ray Tracing: The Rest of Your Life**

El código original fue escrito en 2016 por **Peter Shirley** (<ptrshrl@gmail.com>) y liberado al **dominio público** bajo la licencia **CC0**.

> Este software se distribuye **sin ninguna garantía**.  
> Más información sobre la licencia: [Creative Commons CC0 1.0](http://creativecommons.org/publicdomain/zero/1.0/)

---

## 📂 Código Fuente

Todo el código del proyecto se encuentra en: src/InOneWeekend


---

## ⚡ Cómo construir y correr el programa

1. Generar los archivos de construcción:

```bash
cmake -B build
```

2. Compilar el proyecto:

```bash
cmake --build build --target inOneWeekend
```

3. Ejecutar el programa y guardar la imagen generada:

```bash
cmake --build build --config Release

build/Release/inOneWeekend > imagen.ppm
```


---

## 🖼️ Visualización de la imagen

El programa genera un archivo de imagen en formato `.ppm`.  
Puedes visualizar el archivo de las siguientes formas:

- Con un visor de imágenes que soporte `.ppm` directamente.
- Usando un visor online. Recomiendo:

🔗 [Visor PPM Online](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html)

---
