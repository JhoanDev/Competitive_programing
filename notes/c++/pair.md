# std::pair e std::tuple

Agrupam valores. Podem ser usados livremente na maioria das estruturas de dados e contêineres padrão.

## Operações Principais

| Operação           | Descrição                                          | Complexidade |
| ------------------ | -------------------------------------------------- | ------------ |
| `pair<A, B> p`     | Elementos são acessados via `p.first` e `p.second` | $O(1)$       |
| `make_pair(a, b)`  | Inicialização. Em C++11+, prefira apenas `{a, b}`  | $O(1)$       |
| `tuple<A, B, C> t` | Acessado por `get<0>(t)`                           | $O(1)$       |

## Dicas

- **Ordenação Intuitiva (Lexicográfica):** A principal força dos pares nativos em CP. O `std::sort` já é treinado em comparar o `.first`; se as variáveis empatarem, ele desempata com precisão matemática no `.second`. É crucial para problemas de "Sweepline" geométricos, Data/Horas ou Intervalos temporais contíguos ordenados no decorrer do dia de problemas sem escrever `return a.first < b.first` manuais numa função Comparator complexa separadamente!
- **Aproveite nas Inicializações `{}`:** Abandone completamente de escrever o infame `make_pair(a,b)`. O standard do C++11 em diante trata instâncias vazias `{a,b}` naturalmente. Empurre dados via `v.push_back({x, y});`.
- **Retornos múltiplos flexíveis:** Múltiplos dados em matrizes e saídas para o Main? Pare de preencher Structs atípicas descartáveis caso de teste. Use de cara o par/tupla local.
- **Desempacotamento de Iteráveis com auto (Bindings do C++17):** Esqueça a bagunça pesada usando `.first` e `.second` que confunde as propriedades das variáveis. O código limpa absurdamente com amarrações automáticas:
  - Consumo do Queue de Pair BFS: `auto [y, x] = q.front(); q.pop();`
  - Referências destrutivas no Loop: `for(auto& [custo, alvo] : adj_matrix)` (altera os pesos locais dinamicamente se necessário).
- **Arrays englobados no Tuple:** Misturar `std::array` como base flexível é super rápido comparativamente. Se precisa estocar tuplas dinâmicas para estado de DP, usar `tuple<int, string, double> t` salva o processador.
- **Usando Tie C++11:** Se a engine não compila Binding Moderno, retorne ao excelente _"tuplador fantasma"_. Para `tuple<int, int>` chame `tie(x, y) = minha_tupla;` onde `x` e `y` foram criados pré-existentes limpos no main ou loops gerais de extração!
- **Deteção de Novo Registro do Insert (`map<>::insert`):** Quase poucos sabem que o Insert em Map retorna `pair<map<K,V>::iterator, bool>`. Inserindo itens, use o par para certificar a integridade `bool success = my_map.insert({a,b}).second;` - que confirmará (True) ou avisará por erro Duplicado bloqueado (False).
