# Lajotas Hexagonais - Aprendizado

## Erro Inicial

Tentar construir ou enumerar todos os caminhos.

Problemas de contagem geralmente ficam mais simples quando analisamos o último movimento.

---

## Sacada

Pergunta correta:

```text
Como um caminho termina?
```

Para chegar em `N`, o último passo só pode vir de:

```text
N - 1
N - 2
```

---

## Definição do Estado

```text
f(N) = quantidade de caminhos que terminam em N
```

---

## Construção da Recorrência

Todos os caminhos que chegam em `N`:

* vieram de `N - 1`
* ou vieram de `N - 2`

Como os conjuntos são distintos:

```text
f(N) = f(N - 1) + f(N - 2)
```

---

## Como Encontrar Esse Tipo de Solução

Sempre que o problema pedir:

```text
Quantidade de caminhos
Quantidade de formas
Quantidade de sequências
```

fazer as perguntas:

```text
Qual foi a última escolha?
Qual foi o último movimento?
De qual estado eu vim?
```

Muitas recorrências aparecem imediatamente.

---

## Padrão Importante

Se o estado atual depende de:

```text
N - 1
N - 2
```

suspeite de:

```text
Fibonacci
DP
Recorrência linear
```

---

## Lição Principal

Não tente construir todas as soluções.

Primeiro descubra:

```text
Como uma solução válida termina.
```

A recorrência normalmente nasce dessa observação.
