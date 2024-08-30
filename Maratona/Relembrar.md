# Dicas

### Tomar cuidado com os tipos
Tipos de variáveis podem causar erros difíceis de perceber.

### Passar vetor por referência
**Exemplo:**

Faça:
```cpp
int get_size(vector<int> &a) {
  return (int)a.size();
}
```
em vez de:

```cpp
int get_size(vector<int> a) {
  return (int)a.size();
}
```
Pois passando o vetor no segundo caso requer 𝑂(𝑛)
O(n) (vai fazer uma cópia do vetor) e pode dar erro de memória se o vetor for muito grande e estivermos fazendo várias chamadas recursivas, enquanto passando por referência (primeiro caso) requer 
𝑂
(
1
)
O(1).

### Complexidade
O programa demora ~1 segundo para ~
4
×
10
**8
  operações. Com isso, prestar atenção nos limites de tempos das questões para não dar TLE (Time Limit Exceeded).

### map e unordered_map
Podemos iterar pelo map (ordenado) e unordered_map (não ordenado) com um iterador ou:

```cpp
for (auto &it: map) (pair<>)
```
Porém, tome cuidado, pois ao checar um elemento i que não existe no map ainda:

```cpp
if (mp[i])
```
o elemento i é adicionado no map e nesse caso também passaríamos por ele. Para fazer isso sem adicionar o elemento i no map podemos fazer:

```cpp
if (mp.find(i) != mp.end()) {
  // código
}
```

### ordered_set / unordered_set
| Estrutura           | Inserção/Deleção |
|---------------------|------------------|
| set                 | O(log n)         |
| unordered_set       | O(1) (em média)  |

### lower_bound / upper_bound
lower_bound: retorna um iterador para o menor elemento maior ou igual a algum elemento k. 
𝑂
(
log
⁡
𝑛
)

upper_bound: retorna um iterador para o menor elemento estritamente maior que algum elemento k. 
𝑂
(
log
⁡
𝑛
)
Funciona para set, map, vetor ordenado.

Exemplo:

```plaintext
  1 1 1 1 1 1 2
  ^           ^   para 1
  lb          ub
```
### Otimizadores IO
```cpp
ios::sync_with_stdio(false);
cin.tie(NULL);
```
Ao usá-los, não misture estilos de print do C e C++ (não utilize cout e printf no mesmo código nesse caso).

### gcd, lcm
```cpp
Copiar código
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
lcm(a,b) = a * (b / gcd(a,b))
```
### statisticsTree (sweepline)

```cpp
Copiar código
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// note que está ordenando do menor para o maior e só tem 1 elemento de cada
// para mais de um elemento coloque pair<int, int> ou algo assim
typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;
```
Uso:
```cpp
auto f = [&](vector<pair<int, int>> lines) {
    sort(lines.begin(), lines.end());
    statisticsTree ord;
    for (auto &p: lines) {
        // verifica qual posição p.second está
        max_slices += ord.order_of_key(p.second);
        ord.insert(p.second);
    }
    return;
};
```
### Segment Tree
Útil para queries em range.

Exemplo:

```cpp
template <class T> class MinSegmentTree {
private:
    const T DEFAULT = numeric_limits<T>().max();
    vector<T> segTree;
    int len;

public:
    MinSegmentTree (int segTree_len) {
        len = segTree_len;
        segTree = vector<T>(len * 2, DEFAULT);
    }

    void set(int idx, T val) {
        idx += len;
        segTree[idx] = val;
        
        // update (ignoring 0)
        for (; idx > 1; idx >>= 1) {
            segTree[idx >> 1] = min(segTree[idx], segTree[idx ^ 1]);
        }
    }

    T range_min(int l, int r) {
        T min_ = DEFAULT;

        for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
            if (l & 1) min_ = min(min_, segTree[l++]);
            if (r & 1) min_ = min(min_, segTree[--r]);
        }
        return min_;
    }
};
```

### Bitset
Para utilizar operações de bits em uma string de bits com mais de 64 bits podemos usar o bitset. Ele suporta as bitwise operations e podem ser usados como vetor (por exemplo, utilizar [] para acessar, além de ser possível passar para string)
```cpp
bitset<size> variable_name;
```