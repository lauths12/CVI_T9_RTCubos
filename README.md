Ray Tracing para varios Cubos
====================================================================================================

| In One Weekend (0°) | In One Weekend (45°) |
|:---------------------------------:|:---------------------------------:|
| ![image (11)](https://github.com/user-attachments/assets/09e258f6-4e34-4467-9961-5fa504e6a1ba) | ![image (8)](https://github.com/user-attachments/assets/42692eaf-ce5c-47ac-ac92-71f1deadf068) |


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

Todo el código del proyecto se encuentra en: 

```bash
src/InOneWeekend
```
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
