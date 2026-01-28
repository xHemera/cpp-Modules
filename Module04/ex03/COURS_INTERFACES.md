# 📚 Cours : Interfaces et Classes Abstraites en C++

## 🎯 But de l'exercice

Cet exercice t'apprend à **concevoir une architecture logicielle** en utilisant :
- **Des interfaces** (contrats)
- **Des classes abstraites** (bases partielles)
- **Le polymorphisme** (une référence parente peut pointer vers des enfants différents)
- **La gestion mémoire** (deep copies, allocation dynamique)

**Objectif concret** : Créer un système de "magie" où :
- Des **Personnages** peuvent équiper et utiliser des **sorts** (Materias)
- Une **Source de Magie** peut apprendre et créer des sorts

---

## 📖 1. Qu'est-ce qu'une Interface ?

### Définition
Une **interface** est un **contrat** : elle définit **QUOI** faire, sans dire **COMMENT**.

En C++, une interface est une classe qui contient **uniquement** :
- Des méthodes **virtuelles pures** (`= 0`)
- Un destructeur virtuel

```cpp
class ICharacter  // I = Interface
{
public:
    virtual ~ICharacter() {}  // Destructeur virtuel obligatoire
    virtual std::string const & getName() const = 0;  // = 0 = méthode pure
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

### Pourquoi utiliser une interface ?

✅ **Séparation contrat/implémentation**
```cpp
// main.cpp ne connaît que l'interface
ICharacter* bob = new Character("bob");  // Polymorphisme
bob->getName();  // On sait que ça existe, sans savoir comment c'est codé
```

✅ **Flexibilité**
```cpp
// Plus tard, tu peux créer NPC, Monster, etc.
class NPC : public ICharacter { ... };  // Autre implémentation
class Monster : public ICharacter { ... };
```

✅ **Testabilité** : Tu peux créer des "fausses" implémentations pour tester.

---

## 📖 2. Classe Abstraite vs Interface

| Concept | Interface | Classe Abstraite |
|---------|-----------|------------------|
| **Attributs** | ❌ Aucun | ✅ Possible |
| **Méthodes implémentées** | ❌ Aucune | ✅ Possible |
| **Méthodes pures** | ✅ Toutes | ✅ Au moins 1 |
| **But** | Contrat pur | Base partielle |

### Exemple : AMateria (classe abstraite)

```cpp
class AMateria  // A = Abstract
{
protected:
    std::string _type;  // Attribut commun

public:
    AMateria(std::string const & type);  // Constructeur implémenté
    virtual ~AMateria();

    std::string const & getType() const;  // Méthode implémentée
    virtual AMateria* clone() const = 0;  // Méthode PURE (= interface partielle)
    virtual void use(ICharacter& target); // Méthode implémentée (peut être override)
};
```

**Pourquoi abstraite ?**
- On ne veut **pas** créer un `AMateria` directement (quel type ?)
- On veut **factoriser** du code commun (getType, attribut _type)
- Les enfants (`Ice`, `Cure`) **doivent** implémenter `clone()`

---

## 📖 3. Convention de nommage

| Préfixe | Signification | Exemple |
|---------|---------------|---------|
| **I** | **Interface** (pur contrat) | `ICharacter`, `IMateriaSource` |
| **A** | **Abstract** (base partielle) | `AMateria` |
| *(rien)* | Classe concrète | `Character`, `Ice`, `Cure` |

**Pourquoi ?**
- **Clarté** : En lisant `ICharacter`, tu sais que c'est une interface
- **Convention** : Utilisée dans l'industrie (Microsoft, Java, C#)
- **Séparation** : Interface = API publique, Implémentation = détails cachés

---

## 📖 4. Architecture de l'exercice

```
┌─────────────────────────────────────────────────┐
│            SYSTÈME DE MAGIE                     │
└─────────────────────────────────────────────────┘

┌──────────────┐         ┌──────────────┐
│ ICharacter   │         │ AMateria     │
│ (interface)  │◄────────│ (abstraite)  │
└──────────────┘         └──────────────┘
       △                        △
       │                        │
       │                  ┌─────┴─────┐
       │                  │           │
┌──────┴──────┐     ┌─────┴──┐  ┌────┴───┐
│ Character   │     │  Ice   │  │  Cure  │
│ (concrète)  │     │(concrète)│ │(concrète)│
└─────────────┘     └────────┘  └────────┘

┌──────────────────┐
│ IMateriaSource   │
│ (interface)      │
└──────────────────┘
         △
         │
┌────────┴─────────┐
│ MateriaSource    │
│ (concrète)       │
└──────────────────┘
```

---

## 📖 5. Polymorphisme en action

### Exemple 1 : Inventaire polymorphe

```cpp
class Character {
private:
    AMateria* _inventory[4];  // Peut contenir Ice OU Cure !
};
```

**Magie du polymorphisme** :
```cpp
_inventory[0] = new Ice();    // OK : Ice hérite de AMateria
_inventory[1] = new Cure();   // OK : Cure hérite de AMateria

_inventory[0]->use(target);   // Appelle Ice::use()
_inventory[1]->use(target);   // Appelle Cure::use()
```

### Exemple 2 : Interface comme type

```cpp
void battle(ICharacter* attacker, ICharacter* defender) {
    attacker->use(0, *defender);  // Marche avec Character, NPC, Monster, etc.
}

ICharacter* hero = new Character("Link");
ICharacter* boss = new Monster("Ganon");  // Si tu l'implémentais
battle(hero, boss);  // Polymorphisme !
```

---

## 📖 6. Gestion mémoire : Pourquoi `clone()` ?

### Problème : Shallow copy (copie superficielle)

```cpp
AMateria* original = new Ice();
AMateria* copy = original;  // ❌ Même pointeur !

delete original;
// copy pointe maintenant vers une zone mémoire libérée → CRASH
```

### Solution : Deep copy avec `clone()`

```cpp
AMateria* original = new Ice();
AMateria* copy = original->clone();  // ✅ Nouvel objet indépendant

delete original;
// copy est toujours valide ✅
```

**Dans l'exercice** :
```cpp
void MateriaSource::learnMateria(AMateria* m) {
    _templates[i] = m->clone();  // On clone pour éviter de partager le pointeur
    delete m;  // On delete l'original qu'on nous a passé
}
```

---

## 📖 7. Le pattern "Factory" (MateriaSource)

### Problème
Comment créer un objet sans connaître son type exact au moment de la compilation ?

```cpp
// Je ne veux PAS écrire :
if (type == "ice")
    return new Ice();
else if (type == "cure")
    return new Cure();
// Imagine avec 50 types de sorts !
```

### Solution : Factory avec templates

```cpp
class MateriaSource {
private:
    AMateria* _templates[4];  // "Moules" pour créer des sorts

public:
    void learnMateria(AMateria* m) {
        _templates[i] = m->clone();  // Apprendre un nouveau "moule"
    }

    AMateria* createMateria(std::string const & type) {
        // Chercher le bon moule et le cloner
        for (int i = 0; i < 4; i++)
            if (_templates[i]->getType() == type)
                return _templates[i]->clone();
        return NULL;
    }
};
```

**Utilisation** :
```cpp
MateriaSource* factory = new MateriaSource();
factory->learnMateria(new Ice());    // Apprendre le "moule" Ice
factory->learnMateria(new Cure());   // Apprendre le "moule" Cure

AMateria* spell1 = factory->createMateria("ice");   // Créer un Ice
AMateria* spell2 = factory->createMateria("cure");  // Créer un Cure
AMateria* spell3 = factory->createMateria("ice");   // Encore un Ice
```

**Avantage** : Le main ne connaît pas `Ice` ni `Cure` directement !

---

## 📖 8. Forward Declarations : Éviter les dépendances circulaires

### Problème
```cpp
// AMateria.hpp
#include "ICharacter.hpp"  // AMateria a besoin de ICharacter

// ICharacter.hpp
#include "AMateria.hpp"  // ICharacter a besoin de AMateria

// ❌ Dépendance circulaire → erreur de compilation
```

### Solution : Forward declaration

```cpp
// AMateria.hpp
class ICharacter;  // ✅ Forward declaration : "ICharacter existe"

class AMateria {
    virtual void use(ICharacter& target);  // OK : on utilise une référence
};
```

**Règle** :
- **Header (.hpp)** : Forward declaration si tu utilises un **pointeur** ou une **référence**
- **Implémentation (.cpp)** : `#include` complet si tu appelles des méthodes

```cpp
// AMateria.cpp
#include "AMateria.hpp"
#include "ICharacter.hpp"  // ✅ Maintenant on peut appeler target.getName()

void AMateria::use(ICharacter& target) {
    std::cout << target.getName();  // OK
}
```

---

## 📖 9. Destructeurs virtuels : OBLIGATOIRE !

### Problème sans destructeur virtuel

```cpp
class Base {
public:
    ~Base() { std::cout << "~Base"; }  // ❌ Non virtuel
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() { data = new int[1000]; }
    ~Derived() { delete[] data; }  // Libère la mémoire
};

Base* ptr = new Derived();
delete ptr;  // ❌ Appelle SEULEMENT ~Base() → fuite mémoire !
```

### Solution : Destructeur virtuel

```cpp
class Base {
public:
    virtual ~Base() { std::cout << "~Base"; }  // ✅ Virtuel
};

Base* ptr = new Derived();
delete ptr;  // ✅ Appelle ~Derived() PUIS ~Base() → pas de fuite
```

**Dans l'exercice** :
```cpp
ICharacter* me = new Character("me");
delete me;  // ✅ Appelle Character::~Character() car ICharacter::~ICharacter() est virtuel
```

---

## 📖 10. Résumé : Quand utiliser quoi ?

| Situation | Solution |
|-----------|----------|
| **Définir un contrat pur** | Interface (`ICharacter`) |
| **Partager du code entre enfants** | Classe abstraite (`AMateria`) |
| **Empêcher l'instanciation** | Méthode virtuelle pure (`= 0`) |
| **Cloner un objet** | Méthode `clone()` |
| **Créer des objets dynamiquement** | Factory (`MateriaSource`) |
| **Éviter la dépendance circulaire** | Forward declaration |
| **Polymorphisme avec delete** | Destructeur virtuel |

---

## 🎯 Récapitulatif de l'exercice

**Ce que tu as appris** :
1. ✅ Concevoir avec des interfaces (séparation contrat/implémentation)
2. ✅ Utiliser des classes abstraites (factorisation + contraintes)
3. ✅ Polymorphisme (un type parent peut référencer des enfants différents)
4. ✅ Deep copy (clone pour éviter les copies superficielles)
5. ✅ Factory pattern (créer des objets par leur nom en string)
6. ✅ Gestion mémoire avancée (delete, virtual destructor)
7. ✅ Organisation de code (forward declarations, .hpp/.cpp)

**Pourquoi c'est important** :
- C'est la base de l'**architecture orientée objet**
- Utilisé partout dans le monde professionnel (jeux vidéo, systèmes embarqués, etc.)
- Permet de créer du code **évolutif** et **maintenable**

---

## 💡 Exercice bonus : Étendre le système

Pour vérifier ta compréhension, essaie d'ajouter :
1. Un nouveau sort `Thunder` qui hérite de `AMateria`
2. Une classe `NPC` qui implémente `ICharacter`
3. Une méthode `Character::swapMateria(int idx1, int idx2)`
4. Gérer un "sol" pour stocker les Materias unequip (éviter la fuite mémoire)

Bon courage ! 🚀
