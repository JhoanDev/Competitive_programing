# Migração de Backtracking Tradicional para Bitmask

## 1. Comissão

### Antes

```cpp
unordered_set<int> compativeis;
```

### Depois

```cpp
int mask;
```

### Por quê?

Antes era necessário armazenar explicitamente todos os membros da comissão.

Com bitmask, cada bit representa um aluno.

Exemplo:

```text
mask = 10110
```

Representa:

```text
aluno 2
aluno 3
aluno 5
```

### Ganho

* Menos memória.
* Cópia extremamente barata.
* Inserção em O(1).

---

## 2. Inserção de Aluno

### Antes

```cpp
compativeis.insert(i);
```

### Depois

```cpp
mask | (1 << i)
```

### Como funciona?

```text
mask      = 00101
1 << 1    = 00010
----------------
resultado = 00111
```

Ativa o bit do aluno.

### Ganho

Sem alocação.
Sem estrutura dinâmica.

---

## 3. Remoção de Aluno

### Antes

```cpp
compativeis.erase(i);
```

### Depois

Não existe.

Cada chamada recebe uma nova máscara:

```cpp
busca(mask | (1 << i), ...)
```

### Ganho

Não precisa desfazer operações.

---

## 4. Tamanho da Comissão

### Antes

```cpp
compativeis.size()
```

### Depois

```cpp
__builtin_popcount(mask)
```

### Como funciona?

Conta quantos bits estão ligados.

```text
101101
```

Resultado:

```text
4
```

### Ganho

Operação implementada pela CPU.

---

## 5. Blacklist

### Antes

```cpp
vector<unordered_set<int>>
```

### Depois

```cpp
vector<int> conflito
```

### Como funciona?

Cada aluno possui uma máscara contendo seus conflitos.

Exemplo:

```text
aluno 1 incompatível com 2 e 4

01010
```

---

## 6. Compatibilidade

### Antes

```cpp
for (auto c : compativeis)
{
    if (blacklist[i].count(c))
        return false;
}
```

### Depois

```cpp
(mask & conflito[i]) == 0
```

### Como funciona?

Se existir algum conflito:

```text
mask        = 10110
conflito[i] = 00110

AND         = 00110
```

Resultado diferente de zero.

Logo existe conflito.

Se:

```text
AND = 00000
```

não existe conflito.

### Ganho

Antes:

```text
O(tamanho da comissão)
```

Depois:

```text
O(1)
```

---

## 7. Backtracking

### Antes

```cpp
insert
busca
erase
```

### Depois

```cpp
busca(mask | (1 << i))
```

### Ganho

Código menor.
Menos operações.

---

## 8. Cópia de Estado

### Antes

Era necessário modificar estruturas.

### Depois

```cpp
novo_mask = mask | (1 << i)
```

### Ganho

Copiar um inteiro custa praticamente nada.

---

## 9. Memória

### Antes

```cpp
unordered_set
```

Possui:

* buckets
* hashes
* ponteiros
* alocações

### Depois

```cpp
int
```

Apenas 4 bytes.

---

## 10. Complexidade Prática

### Antes

Para cada candidato:

```cpp
percorrer toda comissão
```

### Depois

Para cada candidato:

```cpp
uma operação AND
```

---

## Regra Geral

Troque:

```cpp
conjunto de elementos
```

por

```cpp
máscara de bits
```

quando:

* N é pequeno (até 20~30).
* Inserção/remoção são frequentes.
* Consultas de pertencimento são frequentes.
* Backtracking explora muitos estados.

Nesses casos, bitmask normalmente produz a maior melhoria de desempenho possível sem alterar a lógica do algoritmo.
