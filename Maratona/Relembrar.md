# Dicas
### Tomar cuidado com os tipos
Tipos de variáveis podem causar erros difíceis de perceber.

### Passar vetor por referência
Exemplo:
Faça:
int get_size(vector<int> &a) {
  return (int)a.size();
}
em vez de:
int get_size(vector<int> a) {
  return (int)a.size();
}
Pois passando o vetor no segundo caso requer O(n) (vai fazer uma copia do vetor) e pode dar erro de memória se o vetor for muito grande e estivermos fazendo várias chamadas recursivas, enquanto passando por referência (primeiro caso) requer O(1)

### Complexidade
O programa demora ~1 segundo para ~10^9 operações. Com isso, prestar atenção nos TLE (Time Limit Exceeded) das questões.

### map e unordered_map
Podemos iterar pelo map (ordenado) e unordered_map (não ordenado) com um iterador ou for (auto &it: map) (pair<>). Porém, tome cuidado, pois ao checar um elemento i que não existe no map ainda: "if (mp[i])", por exemplo, o elemento i é adicionado no map e nesse caso também passaríamos por ele. Para fazer isso sem adicionar o elemento i no map podemos fazer:
if (mp.find(i) != mp.end()) {

}

### ordered/unordered set
              insertion/deletion
set                 O(logn)  
unordered_set       O(1) (average)

### lower/upperbound
lower_bound: returns an iterator to the least element greater than or equal to some element k. O(logn)
upper_bound: returns an iterator to the least element strictly greater than some element k.    O(logn)
Funciona para set, map, vetor ordenado
Exemplo:
1 1 1 1 1 1 2
^           ^   para 1
lb          ub

### Otimizadores IO
	ios::sync_with_stdio(false);
	cin.tie(NULL);
ao usá-los, não misture estilos de print do C e C++ (não utilizar cout e printf no mesmo código nesse caso)

### gcd, lcm
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
lcm(a,b)= a * (b / gcd(a,b))

### statisticsTree (sweepline)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// note que esta ordenando do menor para o maior e so tem 1 elemento de cada
// para mais de um elemento coloque pair<int, int> ou algo assim
typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;

usagem:
    auto f = [&](vector<pair<int, int>> lines) {
        sort(lines.begin(), lines.end());
        statisticsTree ord;
        for (auto &p: lines) {
            // verifica qual posicao p.second esta
            max_slices += ord.order_of_key(p.second);
            ord.insert(p.second);
        }
        return;
    };