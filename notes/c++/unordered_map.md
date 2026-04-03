# std::unordered_map

Tabela Hash. Não mantém a ordem das chaves. Ideal caso ordenação não seja necessária.

- **Busca, inserção e remoção:** $O(1)$ na média, pior caso $O(N)$ devido a muitas colisões.

## Operações Principais

| Operação           | Descrição                          | Complexidade Média |
| ------------------ | ---------------------------------- | ------------------ |
| `um[key]`          | Acessa valor ou insere a chave     | $O(1)$             |
| `um.insert({k,v})` | Insere chave-valor (sem overwrite) | $O(1)$             |
| `um.erase(key)`    | Remove chave                       | $O(1)$             |
| `um.count(key)`    | Existe(1) ou não(0)                | $O(1)$             |

## Dicas

- **Riscos reais de Hash Collision Attacks de TLE:** Juízes de competições sérias (_Codeforces_, _SPOJ_) permitem que problemas implementem Hackings intencionais ou geradores automáticos contra hashes determinísticos padronizados do `<unordered_map>`. Aquivos inteiros com testes contra casos anti-Hash corrompem sua estrutura derrubando todo o desempenho ao famigerado pior-caso degenerado de espalhamento concentrado de colisão resultando de $O(1)$ para constantes estagnadas absurdas de insert/acesso $O(N^2)$ forçando lentidão, finalizando com sonoro fracasso de juiz no Time Limit Exceeded (TLE).
- **Escudo Tático (O Custom Hash):** Quando se arriscando numa Hash de C++ nas instâncias Codeforces sem usar Vector ou _Map Natural_, anexe incondicionalmente Time_Since Epoch XOR para as tabelas na Struct, neutralizará inteiramente colisões intencionais e tornará acessos caóticos imbatíveis na tabela:

```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> um_protegido;
```

- **Alocação Exclusiva Limitante Prévia:** Independentemente da tática de Custom Hash de anti-colisões da competição do competidor adversário de Codeforces, Hash Tables ainda sim tem de readaptar limites de redimensionamento na memória bruta. Previna essas instâncias de sobrecarga de rehashing massiva ativando previamente o seu Teto global esperado sem cerimônias de expansões da tabela em _Runtime C++_: aplique forte `um.reserve(N_Total_Esperado);` na inicialização do main antes da leitura das variáveis para travar estaticamente em constantes perfeitamente isoladas a sua grade sem perda de cache RAM.
- **For loop nas varreduras do Hash Table?** Desempenho letal ruim de `for` e caos contínuo nos Prints sem garantia da ordem.
- **Efetividade vs Vector** Mesmo $O(1)$ em Hash e o seu hash customizado super seguro sendo excelente, uma variável instancial Indexante via num `vector<int>` continuará sempre sendo centenas de microsegundos matemáticos a mais rápido sem os gargalos ocultos. Nunca subestime arrays nativos caso seus limitantes perfeitamente esparsos das chaves caibam ($N < 10^7$).
