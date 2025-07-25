# get_next_line

> 📚 42 project – Lire un fichier ligne par ligne, de manière efficace et protégée.

---

## 🧠 Objectif

Écrire une fonction `get_next_line` qui lit et retourne une ligne depuis un descripteur de fichier (`fd`).
Elle doit être capable de lire n’importe quelle source : fichiers, entrée standard, etc.

---

## ✅ Fonction demandée

```c
char *get_next_line(int fd);
```

- Retourne la prochaine ligne lue depuis fd, avec le \n s’il existe.
- Retourne NULL si plus rien à lire ou en cas d’erreur.
- Fonction réutilisable entre plusieurs appels, même sur différents fichiers (bonus)

---

## ⚙️ Utilisation

### Compilation :

```bash
make        # compile la version obligatoire
make bonus  # compile la version avec multi-fd
```

### Exemple :

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📁 Fichiers rendus

| Fichier                       | Rôle                                   |
|-------------------------------|----------------------------------------|
| `get_next_line.c`             | Logique principale                     |
| `get_next_line.h`             | Prototype + structures                 |
| `get_next_line_utils.c`       | Fonctions auxiliaires                  |
| `get_next_line_bonus.c`       | (bonus) version multi-fd               |
| `get_next_line_bonus.h`       | (bonus) header associé                 |
| `get_next_line_utils_bonus.c` | (bonus) utilitaires version bonus      |
| `Makefile`                    | Compilation avec règles obligatoires   |


---

## 🛠️ Contraintes

- ✅ Autorisé : read, malloc, free
- ❌ Interdit : lseek, libft, variables globales
- ✅ Une seule variable static autorisée
- 📌 BUFFER_SIZE défini au moment de la compilation (-D BUFFER_SIZE=...)

---

## 🧪 Tests conseillés

- Fichier vide
- Fichier sans \n final
- stdin (fd = 0)
- BUFFER_SIZE = 1, 42, 9999, etc.
- Appels alternés sur plusieurs fd (bonus)
- Descripteur invalide

---

## 🎯 Objectif bonus

- 🔁 Lire plusieurs fichiers en parallèle
- 📦 Utiliser une seule variable statique

---

## ✍️ Auteurs

- dcastor – [42 student]

