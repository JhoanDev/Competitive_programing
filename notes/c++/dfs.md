# DFS em Matriz (Existe Caminho?)

## Ideia

A função retorna:

* `true` → existe um caminho até o destino.
* `false` → não existe.

O `true` é propagado pela recursão até a chamada inicial.

---

## Exemplo

```cpp
bool dfs(int i, int j, set<pair<int,int>>& visitados)
{
    if (i == tam - 1 && j == tam - 1)
    {
        return true;
    }

    visitados.insert({i, j});

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (valido(ni, nj, visitados) &&
            dfs(ni, nj, visitados))
        {
            return true;
        }
    }

    visitados.erase({i, j});

    return false;
}
```

---

## Leitura Mental

```cpp
if (valido(...) && dfs(...))
{
    return true;
}
```

Significa:

> Se o vizinho é válido e existe um caminho a partir dele, então existe um caminho a partir da posição atual.

---

## Backtracking

Ao entrar:

```cpp
visitados.insert({i, j});
```

Ao sair:

```cpp
visitados.erase({i, j});
```

Assim cada chamada mantém apenas os vértices do caminho atual.

---

## Fluxo

```text
marca posição

se chegou ao destino
    return true

para cada vizinho
    se vizinho válido e dfs(vizinho)
        return true

desmarca posição

return false
```
