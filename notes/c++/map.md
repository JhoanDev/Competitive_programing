# std::map

Árvore Red-Black. Mantém chaves únicas ordenadas (crescente por padrão).

- **Busca, inserção e remoção:** $O(\log N)$
- **Iteração completa:** $O(N)$

## Operações Principais

| Operação                       | Retorno                                | Complexidade |
| ------------------------------ | -------------------------------------- | ------------ |
| `m[key]` / `m.at(key)`         | Referência ao valor                    | $O(\log N)$  |
| `m.insert({k, v})`             | `pair<iterator, bool>`                 | $O(\log N)$  |
| `m.erase(key)` / `m.erase(it)` | Qtd removida (0/1) / iterador seguinte | $O(\log N)$  |
| `m.find(key)`                  | Iterador (ou `m.end()`)                | $O(\log N)$  |
| `m.count(key)`                 | 1 se existe, 0 se não                  | $O(\log N)$  |
| `m.lower_bound(k)`             | Iterador $\ge k$                       | $O(\log N)$  |
| `m.upper_bound(k)`             | Iterador $> k$                         | $O(\log N)$  |

## Dicas

- **Não use `m[key]` para checar existência**, pois isso cria a chave na árvore (com valor zero/vazio) se ela não existir. Isso custa tempo temporário extra de $O(\log N)$ e incha o mapa com chaves inúteis. Use sempre `m.count(key)` ou `m.find(key) != m.end()`.
- **Iteração com auto (C++17):** Iterar sobre um map é muito facilitado usando Structured Bindings: `for (const auto& [k, v] : m) { ... }`. Prefira `const auto&` se não for modificar os valores, para evitar cópias não intencionais e pesadas (como copiar strings).
- **Evite usar map sempre que puder usar array/vector:** O tempo de execução e a memória limitante de um `std::map` (RB-Tree alocando ponteiros duplos) são significativamente piores comparados a um array linear contíguo na cache RAM local. Se suas chaves forem pequenos números inteiros (como $N \le 10^7$) limitados, use um simples `vector<int> freq(10000005, 0)`: constantes lineares matam $O(\log N)$ fácil!
- **Acelere as inserções:** Se você souber a localização perfeitamente exata onde um item deveria estar, forneça um iterador "_hint_" no inserto: `m.insert(hint_iterator, {key, value})`. O tempo de inserção pode cair de $O(\log N)$ em direção a amortizado $O(1)$.
- **Preservação de validade (Iteradores Re-alocáveis):** Ao contrário dos `vector`s, apagar ou inserir elementos dispersos num `map` não invalida as referências/iteradores de outros elementos já listados nele. Exceto o elemento explicitamente sendo destruído.
- **Tratando `upper_bound` no último:** `m.upper_bound(key)` retornará `m.end()` se nenhum elemento for mais alto no limite. Sempre verifique o iterador contra `m.end()` antes de pegar `->second`, senão o juiz vai apontar SegFault / RTE sem choro.
- **Nodes/Objetos Customizados:** Mapear classes em chaves requer fornecer por padrão uma `std::less` comparável. Sua `struct Node` precisa implementar o `bool operator<(const Node& other) const;` respeitando ordem fracas bem rigorosas ("Strict Weak Ordering").
