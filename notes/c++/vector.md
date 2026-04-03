# std::vector

Array dinâmico contíguo na memória, o mais usado em CP.

- Iteração lineares amigáveis à cache CPU.
- Mais versátil e performático em acessos.

## Operações Principais

| Operação                          | Descrição                                      | Complexidade                      |
| --------------------------------- | ---------------------------------------------- | --------------------------------- |
| `v.push_back(x)` / `v.pop_back()` | Opera no último elemento                       | Amortizado $O(1)$                 |
| `v[i]` / `v.front()` / `v.back()` | Acesso a valores                               | $O(1)$                            |
| `v.resize(N, val)`                | Fixo no tamanho `N`, com o valor default `val` | $O(N)$                            |
| `v.clear()`                       | Remove todos                                   | Lógico de memória                 |
| `v.insert()` / `v.erase()`        | Meio do vetor - evita                          | $O(N)$ (cópia dos demais memmove) |

## Dicas

- **Cópia Assassina do TLE nas chamadas Locais do Iterador:** Erros fatais bobos do competidor novato causam o acoplamento do C++ para alocar Strings/Vectors gigantes clonando em memórias passadas inteiramente pra as variáveis locais por causa de desatenções elementares de tipagem de sintaxe: Troque severamente em loops pesados as leituras de valores forçadas `for (auto text : my_vector_gigante)` pra uma tipagem estática blindada de referencial local livre de perdas `for (const auto& text : my_vector_gigante)`.
- **Pré-Alocação sem Desculpas de Custo Extra:** Esconda do escopo o método `.push_back()`. Quando tu queres carregar um array com variáveis prontas estáticas pelo console Cín/Cout, use instancia original reservada do Array para limar o "Resizing Array Estouro Limites Limitadores da RAM". Declare de cara `vector<long long> prefix(N);` e preencha referenciando indíces em leituras em `N` tempo com o `cin >> prefix[i];`. Caso precise inserir a exastão pra ignorar contadores num loops indeterminados _While Cins_, evite expansões e realocações na tabela local e cante o limitante teto pro alocador na prévia: `v.reserve(100100);`.
- **Aniquilação da Ordem Limpa com Pop e Swap:** `v.erase()` corrompe o TLE re-arrastando todo vector à esquerda em $O(N)$. Deseja extrair um índice isolado, com complexidade cirúrgica instantanêa imbatível de apenas um único $O(1)$, e esquecer ordem pra longe? Invoque o canivete suiço de substituição limpa com último valor da fila atrelada para cobrir buracos soltos no topo: `swap(v[Index_Delecao], v.back()); v.pop_back();`. Apenas um corte sem sequer relocar o array!
- **Array Adj de Vector Simples para Grafos Super-Sônicos:** Não hesite declarar Listas de Vértices para BFS/DFS em competições cruéis limitadíssimas ao se esquivar do vector 2D puro limitante generalizado `vector<vector<int>> g`. Reduza a memória contígua da ram caindo numa instancia nativa do C fixada de Vértices: `vector<int> adj[MAXN]`. É muito mais responsivo por eliminar ponteiros abstratos do head local.
- **Apagão Tático nas Limpezas de Grafos Sem Limite Multi-Test**: Em testes pesados paralelos repetidos pelo Loop (`while(TestCases--)`) não ouse preencher zeros pra aniquilar todas entradas nas chaves completas fixadas até o 10.000 limitantes nas árvores fixas `memset(g, 0)`. Ou loops com `.clear()` de $0$ até estourar estagnado na faixa massiva total. Execute a faxina unicamente restrita da área percorrida recém infectada contada pelos N limitados das passagens na entrada lida no Case particular exato: `for(int i=0; i < N_Vértices_Válidos_Atuais_Lidos; i++) g[i].clear();`. Somente esvazie alocadas marcadas, reduza os `1.50 sec` do problema aos ínfimos cravados relógios do juiz de `0.02s` na velocidade da luz do C++!
- **A Armadilha Oculta Invisível do `vector<bool>`:** `vector<bool>` não é como seu vizinho de compilações em bytes nativos de 8 bits reais (`bool`). No padrão obscuro enraizado na documentação, C++ rebaixou este flag compactando em espremidos pseudo-arrays mascarados pra economia massificante (alocando num limitante Bit por Bit $1/8$ otimizado local). É divino para varreduras imensas e exessos contínuos de memória nas DP Mask. MAS TOME CUIDADO! A otimização não gera localizadores de Memória Endereçada. Você sofrerá e se debaterá não compreendo os erros compiladores travando a submissão se referenciar ou ponteirizar a variável via auto referências diretas (`auto &referencial`). Troque pra vector base puro do char e durma em paz (Exemplo: `vector<char> Visitados`) em maratonas onde bytes restritos extras passarem liso nas regras.
