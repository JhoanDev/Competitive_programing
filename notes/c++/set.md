# std::set

Árvore Binária de Busca Balanceada (RB-Tree). Elementos são únicas e ordenados automaticamente em ordem crescente por padrão.

- **Busca, inserção e remoção:** $O(\log N)$

## Operações Principais

| Operação             | Descrição                                  | Complexidade      |
| -------------------- | ------------------------------------------ | ----------------- |
| `s.insert(val)`      | Insere elemento e mantém ordenado          | $O(\log N)$       |
| `s.erase(val)`       | Remove o elemento por valor se existir     | $O(\log N)$       |
| `s.erase(it)`        | Remove o elemento apontado pelo iterador   | amortizado $O(1)$ |
| `s.find(val)`        | Retorna iterador para o valor ou `s.end()` | $O(\log N)$       |
| `s.count(val)`       | Retorna 1 (existe) ou 0 (não existe)       | $O(\log N)$       |
| `s.lower_bound(val)` | Primeiro iterador $\ge val$                | $O(\log N)$       |
| `s.upper_bound(val)` | Primeiro iterador $> val$                  | $O(\log N)$       |

## Dicas

- **Cuidado com Biblioteca `<algorithm>`:** NUNCA caia no erro de utilizar `std::lower_bound(s.begin(), s.end(), val)` num std::set, pois isso rodará linearmente a travessia das sub-arvores e custará uma lentidão maciça $O(N)$. Chame exclusivamente a "Função Membro" integrada na folha interna: `s.lower_bound(val)` — para garantir buscas ágeis cravadas em $O(\log N)$ com a RB-Tree!
- **Multiset com Deleções Inteligentes:** Vai enfileirar elementos duplicados validáveis no simulador de prioridade temporal? O `std::multiset` guarda tudo. Mas O ALERTA PRINCIPAL é o _Delete/Erase_. `ms.erase(val)` expurga todas as 5 ocorrências de vez no container. Para abater uma isolada, mire pontualmente no ponteiro singular: `ms.erase(ms.find(val))`. O multiset limpa apenas este primeiro target deletado!
- **Concordâncias Inflexíveis (Contagem de Multiplicatas):** O quociente do count de `ms` é $O(\log N + K)$ onde $K$ é linear a frequência local das cópias listadas nos _balaios de nó_ equivalentes. Pode gerar TLE severos se muitos elementos de repetições imensuráveis se amontoarem.
- **Iteradores Finais (R-begin Max/Min):** Esqueça dar for num Set do fim pra trás, você já dispõe das fáceis rotas em C++: Obter o Maior Objeto em ordem do set? Desreferencie fácil em 1 clock sem remover `*s.rbegin()`. O menor obvio, em `*s.begin()`. Mas não retroceda jamais a marca incerta de `.begin()--` ou ele arrebentará no Kernel com `SegmentationFault`.
- **Compressão de Coordenadas Tática:** Ao trabalhar com grafos ou segmentos até $10^{18}$, mas de limite em $N \le 10^5$, basta jogar todas as entradas confusas com range ilimitado no Set ordenando, e então extraí-los ordenadinhos usando Iteradores num map ou array paralelo contíguo sem precisar fazer `std::unique()` e vetores chatos. Se constante de O(LogN) apertou de TLE? Volte prum array, aplique `sort` + `unique`, restrinja o acesso indexante com `erases()`. Set ganha pela beleza do raciocínio prático nas maratonas sem chance de falhas.
