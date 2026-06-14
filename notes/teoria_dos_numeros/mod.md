# OBMEP - (1ⁿ + 2ⁿ + 3ⁿ + 4ⁿ) mod 5

## Ideia Principal

O valor de `n` pode ter até 100000 dígitos, então não é possível armazená-lo em tipos numéricos tradicionais.

A solução consiste em explorar os ciclos das potências módulo 5.

---

## Ciclos Encontrados

### 1ⁿ mod 5

Sempre:

```text
1
```

---

### 2ⁿ mod 5

Ciclo de tamanho 4:

```text
2, 4, 3, 1
```

Índice obtido por:

```text
n mod 4
```

---

### 3ⁿ mod 5

Ciclo de tamanho 4:

```text
3, 4, 2, 1
```

Índice obtido por:

```text
n mod 4
```

---

### 4ⁿ mod 5

Ciclo de tamanho 2:

```text
4, 1
```

Índice obtido por:

```text
n mod 2
```

---

## Conceitos Aprendidos

### 1. Ciclos em Potenciação Modular

Potências módulo `m` eventualmente repetem valores.

Exemplo:

```text
2¹ mod 5 = 2
2² mod 5 = 4
2³ mod 5 = 3
2⁴ mod 5 = 1
2⁵ mod 5 = 2
```

---

### 2. Encontrar n mod 2 em números gigantes

Basta observar o último dígito.

Exemplo:

```text
1234567 mod 2

7 mod 2 = 1
```

Código:

```cpp
int mod2 = (numero.back() - '0') % 2;
```

---

### 3. Encontrar n mod 4 em números gigantes

Basta observar os dois últimos dígitos.

Exemplo:

```text
123456 mod 4

56 mod 4 = 0
```

Código:

```cpp
int mod4 = stoi(numero.substr(numero.size() - 2)) % 4;
```

---

### 4. Regra do módulo na soma

Correto:

```cpp
(a + b + c + d) % m
```

ou

```cpp
((a % m) + (b % m) + (c % m) + (d % m)) % m
```

---

## Estratégia da Solução

1. Ler `n` como string.
2. Calcular:

   * `n mod 4`
   * `n mod 2`
3. Usar esses valores para indexar os ciclos.
4. Somar os resultados.
5. Aplicar `% 5`.

Complexidade:

```text
Tempo: O(1)
Memória: O(1)
```

(apenas leitura dos últimos dígitos da string)

---

## Ponto Mais Importante

Quando o expoente é gigantesco:

```text
aⁿ mod m
```

geralmente não é necessário calcular a potência.

Procure primeiro o ciclo das potências e depois use:

```text
n mod tamanho_do_ciclo
```

para descobrir diretamente o resultado.

## OBMEP - Como Pensar na Solução Ideal

### O Erro Natural

Ao ler:

```text
(1ⁿ + 2ⁿ + 3ⁿ + 4ⁿ) mod 5
```

a primeira ideia costuma ser calcular cada potência usando ciclos.

Isso funciona e passa, mas ainda estamos resolvendo um problema maior do que o necessário.

Em programação competitiva, após encontrar uma solução correta, devemos procurar padrões que simplifiquem ainda mais o problema.

---

### Passo 1 - Trabalhar Módulo 5

Como o resultado final é:

```text
mod 5
```

só importa o comportamento dos números módulo 5.

Temos:

```text
1 ≡  1 (mod 5)
2 ≡  2 (mod 5)
3 ≡ -2 (mod 5)
4 ≡ -1 (mod 5)
```

Logo:

```text
1ⁿ + 2ⁿ + 3ⁿ + 4ⁿ
=
1ⁿ + 2ⁿ + (-2)ⁿ + (-1)ⁿ
```

---

### Passo 2 - Procurar Simetria

Observe:

```text
2ⁿ + (-2)ⁿ
```

Se n for ímpar:

```text
2ⁿ - 2ⁿ = 0
```

Se n for par:

```text
2ⁿ + 2ⁿ = 2·2ⁿ
```

Não resolve sozinho, mas mostra que existe simetria.

---

### Passo 3 - Testar Pequenos Casos

Calcule:

```text
n = 1

1 + 2 + 3 + 4 = 10
10 mod 5 = 0
```

```text
n = 2

1 + 4 + 4 + 1 = 10
10 mod 5 = 0
```

```text
n = 3

1 + 3 + 2 + 4 = 10
10 mod 5 = 0
```

```text
n = 4

1 + 1 + 1 + 1 = 4
```

Surge a tabela:

| n mod 4 | resposta |
| ------- | -------- |
| 0       | 4        |
| 1       | 0        |
| 2       | 0        |
| 3       | 0        |

---

### Passo 4 - Entender o Motivo

Potências módulo 5:

```text
2:
2 4 3 1

3:
3 4 2 1
```

Os ciclos são complementares.

Para qualquer n > 0:

```text
2ⁿ + 3ⁿ ≡
5, 8, 5, 2
(mod 5)
```

que resulta em:

```text
0, 3, 0, 2
(mod 5)
```

Agora observe:

```text
1ⁿ + 4ⁿ
```

gera:

```text
0, 2, 0, 2
(mod 5)
```

Somando os dois grupos:

```text
0, 0, 0, 4
```

Portanto a resposta depende apenas de:

```text
n mod 4
```

---

### O Insight Principal

Não precisamos descobrir:

```text
2ⁿ mod 5
3ⁿ mod 5
4ⁿ mod 5
```

Separadamente.

Precisamos descobrir apenas:

```text
qual informação mínima influencia a resposta?
```

Nesse problema:

```text
n mod 4
```

é suficiente.

---

### Solução Final

Calcular:

```text
n mod 4
```

usando apenas os dois últimos dígitos da string.

Se:

```text
n mod 4 == 0
```

resposta:

```text
4
```

Caso contrário:

```text
0
```

---

### Aprendizado para Problemas Futuros

Quando aparecer:

```text
aⁿ mod m
```

seguir a ordem:

1. Procurar ciclos.
2. Procurar simetrias entre termos.
3. Testar pequenos casos.
4. Tentar reduzir a resposta para depender apenas de:

   * n mod k
   * paridade
   * último dígito
   * últimos dois dígitos
5. Só implementar após descobrir a menor informação necessária.

Muitas questões de teoria dos números são resolvidas não calculando a expressão, mas descobrindo de qual pequena informação ela realmente depende.
