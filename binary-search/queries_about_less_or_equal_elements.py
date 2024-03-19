# Implementação em Python para resolver o problema proposto

def queries_less_or_equal(a, b):
    # Ordenar a lista 'a' para as buscas binárias
    a.sort()

    # Função para contar elementos em 'a' que são menores ou iguais a 'x'
    def binary_search(x):
        lo, hi = 0, len(a)
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] <= x:
                lo = mid + 1
            else:
                hi = mid
        return lo

    # Lista para manter os resultados
    result = []
    # Para cada elemento em 'b', faz a busca binária em 'a'
    for x in b:
        result.append(binary_search(x))

    return result

# Lendo os tamanhos das listas a e b
n, m = map(int, input().split())

# Lendo os elementos das listas a e b
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# Executando a função e imprimindo os resultados
results = queries_less_or_equal(a, b)
print(' '.join(map(str, results)))