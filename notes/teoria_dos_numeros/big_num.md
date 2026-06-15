# Teoria dos Números: Aritmética Modular & Grandes Números

Resumo Teórico & Prático para Programação Competitiva.

## Visão Geral

Em problemas de programação competitiva, quando lidamos com números que crescem exponencialmente (como a sequência de repetições do dígito $1$: $1, 11, 111, 1111, \dots$), é inviável representá-los usando tipos primitivos (`long long`).
**A chave é:** Raramente precisamos do número inteiro em si, mas sim do seu **resto módulo $N$**.

## Fundamentação Matemática

### 1. Construção Incremental de Dígitos

Ao adicionar um dígito $d$ ao final de um número $x$, a nova representação numérica é dada por:
$$x_{\text{novo}} = x \cdot 10 + d$$

Pelas propriedades da aritmética modular, o resto módulo $N$ pode ser calculado incrementalmente sem overflow:
$$x_{\text{novo}} \pmod N = \left( (x \pmod N) \cdot 10 + d \right) \pmod N$$

### 2. Espaço de Estados Limitado (Princípio da Casa dos Pombos)

Se processamos os restos sucessivamente, existem apenas $N$ possíveis estados para o resto:
$$S = \{0, 1, 2, \dots, N-1\}$$

* **Garantia de Término / Ciclo:** Se o processo rodar por mais de $N$ iterações sem encontrar o resto $0$, obrigatoriamente um resto se repetirá, indicando um ciclo infinito (caso o resto $0$ não seja alcançável).

## Implementação Direta (C++)

Exemplo típico: Encontrar o menor número composto apenas por dígitos `1` que é divisível por $N$.

```cpp
#include <iostream>

using namespace std;

// Retorna a quantidade de dígitos do menor múltiplo de N formado apenas por '1's.
// Retorna -1 se não existir.
int menor_multiplo_de_uns(int N) {
    int resto = 0;
    for (int digitos = 1; digitos <= N; ++digitos) {
        resto = (resto * 10 + 1) % N;
        if (resto == 0) return digitos;
    }
    return -1; // Se não achar em N iterações, entra em ciclo infinito
}
```

## Aplicações Comuns

| Cenário | Estratégia |
| :--- | :--- |
| **Verificar Divisibilidade de String Gigante** | Ler caractere por caractere da esquerda para a direita e atualizar com a expressão: `resto = (resto * 10 + (c - '0')) % N;`. |
| **BFS em Espaço de Restos** | Em problemas de caminhos mínimos onde os nós representam restos de um número módulo $N$ (ex: menor número usando apenas $\{3, 7\}$ divisível por $K$). |
| **Encontrar Ciclos Modulares** | Usar um vetor de visitados `visited[resto]` para detectar ciclos ao construir o número. |

## Pergunta de Ouro

> *"Eu preciso do valor exato do número ou apenas do seu comportamento modular (resto)?"*
