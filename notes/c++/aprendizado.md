# Aprendizado C++ (Resumo)

- **For-each:** `const auto &x` (leitura) ou `auto &x` (modificação) para evitar cópias desnecessárias.
- **Vectors:** Use `v.reserve(n)` antes de múltiplos `push_back(x)` para melhor performance.
- **Sort:** `sort(v.begin(), v.end())`. Use `greater<type>()` como terceiro argumento para ordem decrescente.
- **Entrada:** `getline(cin, x)` para strings com espaços. Use `cin.ignore()` após um `cin >>` se for ler uma linha em seguida.
- **Priority Queue / Min-Heap:** É Max-Heap por padrão. Para Min-Heap com structs customizadas, inverta a lógica do `operator<` (retorne `true` se `this->val > outro.val`). Para atualizar elementos no topo (que é read-only): copie, dê `pop()`, modifique localmente e reinsira com `push()`.
