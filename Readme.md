# 🧠 Competitive Programming Notes & Solutions

Este repositório consolida meus estudos, anotações de sintaxe e resoluções de problemas focados em **Programação Competitiva** e algoritmos computacionais. O objetivo é criar uma base sólida de conhecimento para maratonas de programação e otimização de código.

## 🗂 Estrutura do Repositório

O cofre do repositório está organizado nas seguintes diretrizes:

- **`beecrownd/`**: Diretório principal de soluções da plataforma Beecrowd, divididas exatamente pela matriz original: Iniciante, Ad-Hoc, Strings, Estruturas e Bibliotecas, Matemática, Paradigmas, Grafos, Geometria Computacional e SQL.
- **`notes/`**: Manuais táticos e super compactos contendo dicas pesadas de C++ (STL, Estruturas de Dados e truques algorítmicos contra perda de performance).
- **`posniak/`**: Baterias focadas de exercícios, incluindo treinamentos de juízes privados (padrão BOCA).
- **`programacao_paralela/`**: Estudos independentes e densos atrelados ao paralelismo de alto desempenho, cobrindo implementações físicas e de rede aplicadas em `CUDA`, `MPI` e `OpenMP`.
- **`teamplate.cpp`**: O molde primário padronizado que já contém as macros e a estrutura básica do `main()` para rodar resoluções limpas na linguagem C++.

## 💻 Tecnologias Empregadas

- **C++**: Linguagem núcleo. Aproveita agressivamente recursos de `bits/stdc++.h` e o controle máximo do fluxo do compilador para desviar de _Time Limit Exceeded_ (TLE).
- **C**: Utilizado em rotinas estruturais mais antigas que invocam raízes puras sem orientação a objeto.
- **Python**: Aplicado cirurgicamente como scripts de teste ou para resolver gigantescos entraves de manipulações de Strings absurdas.
- **Bibliotecas de Cluster**: Ferramentas de segmentação Multi-Thread e processamentos de Kernel Gráfico presentes na subpasta de paralelelismo.

## ⚙️ Como Utilizar os Dados

1. Procure pelas categorias e compare implementações.
2. Na pasta de `notes/`, revise comportamentos complexos com a cache do sistema, ataques limitadores aos _Hash Maps_ e formas de fugir deles.
3. Para compilar e testar os modelos usando o _Gnu Compiler Collection_ (GCC) de fundo, empregue sua linha de base:

```bash
g++ -O2 -Wall -std=c++17 solução.cpp -o run
./run
```

## 🤝 Colaborações e Melhorias

Caso identifique caminhos algorítmicos com complexidades assintóticas melhores que nas resoluções expostas, peço abertamente a abertura de **Issues** demonstrando a otimização de forma descritiva e se sinta à vontade para puxar **Pull Requests**. Seu conhecimento é vastamente bem-vindo.
