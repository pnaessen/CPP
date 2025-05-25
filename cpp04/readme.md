# Module 04 - Exercise 03 : Interface & Recap

## 🏗️ Architecture Overview

### Schéma d'héritage

```
                    ┌─────────────────┐
                    │   AMateria      │
                    │   (abstract)    │
                    │                 │
                    │ + getType()     │
                    │ + clone() = 0   │
                    │ + use()         │
                    └─────────────────┘
                            ▲
                            │
                 ┌──────────┴──────────┐
                 │                     │
        ┌─────────────────┐   ┌─────────────────┐
        │      Ice        │   │      Cure       │
        │   (concrete)    │   │   (concrete)    │
        │                 │   │                 │
        │ + clone()       │   │ + clone()       │
        │ + use()         │   │ + use()         │
        └─────────────────┘   └─────────────────┘
```

### Interfaces et Implémentations

```
     ┌─────────────────┐              ┌─────────────────┐
     │  ICharacter     │              │ IMateriaSource  │
     │  (interface)    │              │  (interface)    │
     │                 │              │                 │
     │ + getName()=0   │              │ + learn()=0     │
     │ + equip()=0     │              │ + create()=0    │
     │ + unequip()=0   │              │                 │
     │ + use()=0       │              │                 │
     └─────────────────┘              └─────────────────┘
             ▲                                ▲
             │                                │
     ┌─────────────────┐              ┌─────────────────┐
     │   Character     │              │ MateriaSource   │
     │  (concrete)     │              │  (concrete)     │
     │                 │              │                 │
     │ - _name         │              │ - _materia[4]   │
     │ - _inventory[4] │              │                 │
     └─────────────────┘              └─────────────────┘
```

## 🔄 Relations et Flux de données

### Pattern Factory (MateriaSource)

```
     User Code                MateriaSource              Concrete Classes
         │                         │                           │
         │ learnMateria(new Ice()) │                           │
         ├────────────────────────►│                           │
         │                         │ m->clone()                │
         │                         ├──────────────────────────►│
         │                         │                    new Ice(*this)
         │                         │◄──────────────────────────┤
         │                         │ delete m                  │
         │                         │                           │
         │ createMateria("ice")    │                           │
         ├────────────────────────►│                           │
         │                         │ _materia[i]->clone()      │
         │                         ├──────────────────────────►│
         │                         │                    new Ice(*this)
         │                         │◄──────────────────────────┤
         │◄────────────────────────┤                           │
```

### Character Inventory Management

```
     Character::equip(materia)
         │
         ▼
     Find first empty slot [0-3]
         │
         ▼
     _inventory[i] = materia
     
     Character::use(idx, target)
         │
         ▼
     Check if _inventory[idx] != NULL
         │
         ▼
     _inventory[idx]->use(target)
         │
         ▼
     Polymorphic call to Ice::use() or Cure::use()
```

## 📋 Checklist d'implémentation

### ✅ Classes abstraites et interfaces

- [ ] **AMateria** : Classe abstraite avec `clone() = 0`
- [ ] **ICharacter** : Interface pure (toutes méthodes virtuelles pures)
- [ ] **IMateriaSource** : Interface pure
- [ ] **Destructeurs virtuels** dans toutes les interfaces

### ✅ Classes concrètes

- [ ] **Ice** : Hérite d'AMateria, type = "ice"
- [ ] **Cure** : Hérite d'AMateria, type = "cure"  
- [ ] **Character** : Implémente ICharacter
- [ ] **MateriaSource** : Implémente IMateriaSource

### ✅ Forme canonique de Coplien

Chaque classe concrète doit avoir :
- [ ] Constructeur par défaut
- [ ] Constructeur de copie (deep copy!)
- [ ] Destructeur
- [ ] Opérateur d'affectation (deep copy!)

### ✅ Gestion mémoire

- [ ] **learnMateria()** : Clone l'input et delete l'original
- [ ] **createMateria()** : Retourne un clone (nouvelle allocation)
- [ ] **equip()** : Stocke le pointeur directement
- [ ] **unequip()** : Met à NULL, ne delete PAS
- [ ] **Destructeurs** : delete toutes les materias stockées

## 🧪 Séquences de test critiques

### Test 1: Basic Functionality
```cpp
src->learnMateria(new Ice());     // Clone + delete temporaire
tmp = src->createMateria("ice");  // Clone depuis stockage
me->equip(tmp);                   // Stockage direct du pointeur
me->use(0, *bob);                 // Appel polymorphe Ice::use()
```

**Appels attendus :**
1. `Ice()` constructor
2. `Ice(const Ice&)` copy constructor (clone)
3. `Ice` destructor (temporaire)
4. `Ice(const Ice&)` copy constructor (create)
5. `Ice::use(ICharacter&)` (polymorphisme)

### Test 2: Deep Copy Character
```cpp
Character original("test");
original.equip(src->createMateria("ice"));
Character copy(original);         // Deep copy required!
```

**Vérifications :**
- `copy` a ses propres materias (pas les mêmes pointeurs)
- Modifier `copy` n'affecte pas `original`
- Les deux peuvent utiliser leurs materias indépendamment

### Test 3: Memory Management
```cpp
me->equip(src->createMateria("ice"));
me->unequip(0);                   // Materia devient "au sol"
// Il faut gérer cette materia manuellement !
```

## 🚨 Pièges courants

### 1. **learnMateria() mal implémentée**
```cpp
// ❌ FAUX
if(_materia[i]) {           // Cherche slot occupé !
    _materia[i] = m;        // Pas de clone !
}

// ✅ CORRECT  
if(!_materia[i]) {          // Cherche slot libre
    _materia[i] = m->clone(); // Clone obligatoire
}
delete m;                   // Nettoyer l'originale
```

### 2. **Shallow copy au lieu de deep copy**
```cpp
// ❌ FAUX
_inventory[i] = obj._inventory[i];  // Même pointeur !

// ✅ CORRECT
_inventory[i] = obj._inventory[i]->clone();  // Nouveau pointeur
```

### 3. **Formats d'affichage**
```cpp
// ✅ CORRECT (avec les étoiles !)
"* shoots an ice bolt at " + name + " *"
"* heals " + name + "'s wounds *"
```

## 🎯 Points de validation pour la défense

1. **Expliquer le polymorphisme** : Comment `me->use(0, *bob)` appelle la bonne méthode
2. **Deep vs Shallow copy** : Pourquoi `clone()` est essentiel
3. **Pattern Factory** : Comment MateriaSource crée des objets sans connaître leur type exact
4. **Gestion mémoire** : Qui est responsable de delete quoi et quand
5. **Interfaces en C++98** : Pourquoi utiliser des classes purement abstraites

## 🔧 Commandes de test

```bash
# Compilation
make

# Test basique
./Program

# Test mémoire (critique !)
valgrind --leak-check=full --show-leak-kinds=all ./Program

# Test avec plusieurs runs pour vérifier la stabilité
for i in {1..5}; do echo "Run $i:"; ./Program; done
```

## 📊 Output attendu (test basique)

```
* shoots an ice bolt at bob *
* heals bob's wounds *
```

**Note** : Les messages de constructeurs/destructeurs peuvent varier selon votre implémentation, mais l'output principal doit être exactement celui-ci.

---

*Ce README vous donne une vue d'ensemble complète pour vérifier que votre implémentation respecte tous les concepts du module 04 !*