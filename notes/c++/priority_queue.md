# std::priority_queue

Fila de prioridade implementada como um Heap (Max-Heap binário por padrão). Excelente para simulações de filas, eventos cronológicos (Dijkstra, Prim) e ordenação dinâmica sob fluxo de dados.

- **Busca do topo (top):** $O(1)$
- **Inserção (push) e Remoção (pop):** $O(\log N)$

## Operações Principais

| Operação | Descrição | Complexidade |
| :--- | :--- | :--- |
| `pq.push(val)` / `pq.emplace(...)` | Insere elemento na fila de prioridade | $O(\log N)$ |
| `pq.pop()` | Remove o elemento do topo (maior prioridade) | $O(\log N)$ |
| `pq.top()` | Retorna uma referência constante ao elemento do topo | $O(1)$ |
| `pq.empty()` | Retorna `true` se a fila estiver vazia | $O(1)$ |
| `pq.size()` | Retorna o número de elementos | $O(1)$ |

## Dicas

- **Inversão de Sentido para Min-Heap (Primitivos):** Por padrão, a `priority_queue` é um Max-Heap (maior valor no topo). Para criar um Min-Heap (menor no topo) com tipos primitivos, declare explicitamente o container interno (`std::vector`) e a função de comparação `std::greater`:

  ```cpp
  priority_queue<int, vector<int>, greater<int>> pq;
  ```

- **Min-Heap com Structs Customizadas (Sobrecarga de Operador):** Quando estiver simulando eventos dinâmicos (como no problema do `supermercado`), use structs com o `operator<` sobrecarregado. Como a `priority_queue` ordena em ordem decrescente baseada no operador menor que (`<`), você deve **inverter** a lógica de comparação dentro da sobrecarga:

  ```cpp
  struct Caixa {
      int tempo_ate_terminar;
      int id;
      int tempo_por_item;

      // Sobrecarga invertida para funcionar como Min-Heap
      bool operator<(const Caixa& outro) const {
          if (tempo_ate_terminar == outro.tempo_ate_terminar)
              return id > outro.id; // Menor ID ganha prioridade
          return tempo_ate_terminar > outro.tempo_ate_terminar; // Menor tempo ganha prioridade
      }
  };
  ```

- **Mutabilidade Indireta no Topo (Extrair-Alterar-Reinserir):** O topo da fila (`pq.top()`) é estritamente *read-only* (`const T&`) para garantir que você não altere valores internamente e quebre a integridade da árvore heap. Se precisar atualizar o estado de um elemento (como avançar o tempo de um caixa com novos clientes), a receita padrão é copiar o topo, removê-lo da fila com `pop`, aplicar as modificações localmente e reinseri-lo com `push`:

  ```cpp
  Caixa c = caixas.top(); // Copia o topo
  caixas.pop();          // Remove da estrutura
  c.tempo_ate_terminar += clientes.front() * c.tempo_por_item; // Modifica localmente
  caixas.push(c);        // Insere atualizado
  ```

- **Evitando Cópias Inúteis com Emplace:** Use `pq.emplace(arg1, arg2...)` em vez de `pq.push(T(arg1, arg2))` em C++11+ para construir elementos complexos diretamente no container, economizando cópias temporárias que podem degradar a performance sob limites rígidos de tempo de execução.
- **Comparadores Externos via Functor:** Se a struct já possui um `operator<` para ordenação geral (como `std::sort`) ou se você preferir não alterar a struct original, defina uma estrutura comparadora separada (functor) passando como terceiro argumento de template:

  ```cpp
  struct ComparaCaixa {
      bool operator()(const Caixa& a, const Caixa& b) {
          if (a.tempo_ate_terminar == b.tempo_ate_terminar)
              return a.id > b.id;
          return a.tempo_ate_terminar > b.tempo_ate_terminar;
      }
  };
  priority_queue<Caixa, vector<Caixa>, ComparaCaixa> pq;
  ```
