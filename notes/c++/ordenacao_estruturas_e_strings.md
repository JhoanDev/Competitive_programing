# Ordenação de Estruturas e Processamento de Texto

## 1. Sobrecarga de Operador para Ordenação Customizada

Para ordenar objetos de uma classe ou estrutura utilizando `std::sort`, é necessário sobrecarregar o `operator<`. O operador deve ser marcado como `const` para garantir que a comparação não altere o estado dos objetos.

```cpp
struct Registro {
    string data;
    int km;
    bool enter;

    // Construtor simples
    Registro(string d, int k, bool e) : data(d), km(k), enter(e) {}

    // Ordenação cronológica (ordem alfabética da string data)
    bool operator<(const Registro& outro) const {
        return data < outro.data;
    }
};
```

Para ordenar um vetor desses objetos:

```cpp
vector<Registro> registros;
// ...
sort(registros.begin(), registros.end()); // Usa a regra definida no operator<
```

---

## 2. Agrupamento e Ordenação Automática com `std::map`

O `std::map` é ideal para agrupar elementos sob uma determinada chave (como o nome de uma categoria ou placa) mantendo as chaves ordenadas automaticamente por ordem alfabética/crescente.

```cpp
// Agrupa os registros associando cada placa ao seu histórico correspondente
map<string, vector<Registro>> registros_por_placa;

// Acesso ou inserção direta
registros_por_placa[placa].push_back(reg);

// Iteração ordenada pela chave (placa)
for (auto& par : registros_por_placa) {
    string placa = par.first;
    vector<Registro>& historico = par.second;
    // Processamento ordenado dos dados...
}
```

---

## 3. Processamento de Texto e Strings

### Extração de Dados com `stringstream`

Quando os valores em uma linha estão separados por espaços, podemos ler a linha inteira via `getline` e ler os tipos de dados formatados com segurança usando um `stringstream`.

```cpp
string linha;
getline(cin, linha);
stringstream ss(linha);

string texto;
int numero;
ss >> texto >> numero;
```

### Conversão e Substrings

Para processar partes específicas de datas ou textos de tamanho fixo:

* `substr(pos, len)`: Extrai um pedaço da string começando em `pos` com comprimento `len`.
* `stoi(str)`: Converte uma string/substring numérica diretamente para inteiro.

```cpp
// Extrai dois caracteres a partir da posição 6 e converte para inteiro
int hora = stoi(data.substr(6, 2));
```

### Busca de Padrões

Para validar a presença de um trecho específico dentro de uma string de forma simples:

```cpp
bool contem_texto = (linha.find("palavra_chave") != string::npos);
```

---

## 4. Rastreamento de Estado Pareado usando Ponteiros

Ao parear eventos do tipo início/fim (ex: check-in/check-out), podemos usar um ponteiro temporário para manter o estado do último evento de abertura ativo.

```cpp
Registro* ultimo_inicio = nullptr;

for (auto& r : registros) {
    if (r.enter) {
        ultimo_inicio = &r; // Atualiza a referência de abertura
    } else {
        if (ultimo_inicio != nullptr) {
            // Processa o intervalo fechado (ultimo_inicio -> r)
            int delta = r.km - ultimo_inicio->km;
            
            // Consome o estado para evitar reuso incorreto
            ultimo_inicio = nullptr; 
        }
    }
}
```

---

## 5. Formatação Decimais e Tratamento de Entrada

### Precisão de Decimais

Para exibir números reais de forma padronizada (duas casas decimais, por exemplo):

```cpp
#include <iomanip>
cout << fixed << setprecision(2) << valor << endl;
```

### Limpeza de Linhas Vazias entre Casos de Teste

Para evitar ler strings de formatação erradas ou vazias ao lidar com múltiplos casos de teste com espaçamentos variáveis:

```cpp
string linha;
// Pula todas as linhas em branco até a primeira linha com conteúdo útil
do {
    getline(cin, linha);
} while (linha.empty());

// Lê e processa bloco de texto até encontrar uma linha em branco (fim do caso de teste)
while (getline(cin, linha) && !linha.empty()) {
    // Processamento linha a linha...
}
```
