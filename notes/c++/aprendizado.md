# Aprendizado C++ (Resumo)

- **For-each:** `const auto &x` (leitura) ou `auto &x` (modificação) para evitar cópias desnecessárias.
- **Vectors:** Use `v.reserve(n)` antes de múltiplos `push_back(x)` para melhor performance.
- **Sort:** `sort(v.begin(), v.end())`. Use `greater<type>()` como terceiro argumento para ordem decrescente.
- **Entrada:** `getline(cin, x)` para strings com espaços. Use `cin.ignore()` após um `cin >>` se for ler uma linha em seguida.
