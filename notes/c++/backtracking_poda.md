# Aprendizados - Backtracking e Poda

## Não restringir a busca sem justificativa

Evitar assumir que um elemento específico pertence à solução ótima.

```cpp
compativeis.insert(1); // pode eliminar soluções válidas
```

Preferir:

```cpp
max_profundidade(compativeis, 0, n, blacklist, melhor);
```

---

## Evitar soluções repetidas

Gerar candidatos apenas após o último escolhido.

```cpp
for (int i = ultimo + 1; i <= n; i++)
```

Assim, conjuntos equivalentes não são explorados múltiplas vezes.

---

## Utilizar poda otimista

Se nem no melhor cenário for possível superar a melhor solução encontrada, interromper a busca.

```cpp
if (atual + restantes <= melhor_global)
    return;
```

---

## Compartilhar o melhor resultado global

Atualizações encontradas em um ramo devem ser conhecidas pelos demais.

```cpp
void busca(..., int& melhor_global)
```

---

## Simplificar verificações

Quando uma relação é simétrica, basta consultar um único lado.

```cpp
blacklist[a].insert(b);
blacklist[b].insert(a);
```

Depois:

```cpp
if (blacklist[a].count(b))
```

---

## Escolher estruturas compatíveis com o uso

Quando apenas inserções, remoções e iteração são necessárias:

```cpp
vector<int> atual;
```

Quando consultas rápidas são frequentes:

```cpp
unordered_set<int>
```

ou

```cpp
vector<vector<bool>>
```

---

## Validar com casos extremos

Testar situações onde:

* a solução ótima não contém o primeiro elemento;
* existe apenas um elemento na solução;
* todos são compatíveis;
* ninguém é compatível.

Esses casos costumam revelar erros de modelagem e poda.

---

## Regra prática

Antes de otimizar:

1. Garantir que todas as soluções válidas podem ser geradas.
2. Garantir que nenhuma poda remove soluções válidas.
3. Só então buscar melhorias de desempenho.
