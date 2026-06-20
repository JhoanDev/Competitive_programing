# Busca Binária na Resposta (Double) — Dividindo a Coca

## 1. Conceito e Monotonicidade

Quando a resposta a um problema físico ou matemático é **monótona** (ex: aumentar a altura sempre aumenta o volume) e não é simples isolar a variável algebricamente, usa-se **busca binária no espaço da resposta**.

* **Objetivo:** Encontrar a altura do líquido $h_{liq}$ tal que $V(h_{liq}) = V_{alvo}$, onde $V_{alvo} = \frac{\text{ml}}{\text{pessoas}}$.
* **Monotonicidade:** Conforme $h_{liq} \uparrow$, o volume $V(h_{liq}) \uparrow$.

---

## 2. Modelagem Matemática (Tronco de Cone)

| Componente | Descrição / Fórmula |
| :--- | :--- |
| **Raio da base inferior ($b$)** | Raio do fundo do copo |
| **Raio da base superior ($B$)** | Raio da boca do copo |
| **Altura total ($H$)** | Altura máxima do copo |
| **Raio intermediário ($r$)** | $r = b + \frac{B - b}{H} \cdot h_{liq}$ (por semelhança de triângulos) |
| **Volume ($V$)** | $V = \frac{\pi \cdot h_{liq}}{3}(b^2 + b \cdot r + r^2)$ |

---

## 3. Implementação (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

// Calcula o volume do líquido com base na altura atual
double calcula_volume(double h_liq, double b, double B, double H) {
    double r = b + (B - b) * h_liq / H;
    return M_PI * h_liq * (b * b + b * r + r * r) / 3.0;
}

void solve() {
    int pessoas, ml;
    double b, B, H;
    cin >> pessoas >> ml >> b >> B >> H;

    double v_alvo = (double)ml / pessoas;
    double low = 0.0, high = H, mid;

    for (int i = 0; i < 100; ++i) {
        mid = low + (high - low) / 2.0;
        if (calcula_volume(mid, b, B, H) >= v_alvo) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(2) << high << "\n";
}
```

---

## 4. Melhores Práticas para Busca Binária em Reais

### Critério de Parada: EPS vs. Iterações Fixas

1. **Número Fixo de Iterações (Preferível):**
   * Usar um loop `for` de $80$ a $100$ iterações elimina qualquer risco de loop infinito decorrente de problemas de representação do `double` e alcança precisão máxima suportada pelo hardware.
2. **Precisão Absoluta (EPS):**
   * Se optar por `while (high - low > EPS)`, certifique-se de que o `EPS` seja pelo menos $100$ vezes menor do que a precisão exigida pelo problema (ex: se o problema pede precisão de $10^{-5}$, use $EPS = 10^{-7}$).

### Complexidade

* **Tempo:** $O(I \cdot f(x))$, onde $I$ é o número de iterações ($\approx 80 \text{ a } 100$) e $f(x)$ é o custo de avaliar a função (neste caso, $O(1)$).
* **Espaço:** $O(1)$.
