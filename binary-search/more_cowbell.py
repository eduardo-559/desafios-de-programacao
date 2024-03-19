def pode_distribuir(cowbells, k, s):
    caixas_usadas = 0
    i = 0  # Índice para o sino de menor tamanho que não foi alocado
    j = len(cowbells) - 1  # Índice para o sino de maior tamanho que não foi alocado

    while i <= j:
        # Se só resta um sino ou se o menor e maior sino cabem na caixa, coloque ambos na mesma caixa
        if i == j or cowbells[i] + cowbells[j] <= s:
            i += 1
            j -= 1
        else:
            # Senão, coloque apenas o maior sino na caixa
            j -= 1
        # Uma caixa foi usada
        caixas_usadas += 1

        # Se o número de caixas usadas excede k, então o tamanho s não é suficiente
        if caixas_usadas > k:
            return False

    # Se todas as vacas foram alocadas sem exceder o número de caixas, o tamanho s é suficiente
    return True

def encontrar_menor_tamanho_caixa(n, k, cowbells):
    # Inicializa o tamanho mínimo da caixa como o maior sino e o máximo como a soma de todos os sinos
    esquerda, direita = max(cowbells), sum(cowbells)

    # Realiza a busca binária para encontrar o tamanho mínimo da caixa
    while esquerda < direita:
        meio = (esquerda + direita) // 2
        if pode_distribuir(cowbells, k, meio):
            direita = meio
        else:
            esquerda = meio + 1

    # Retorna o tamanho mínimo da caixa
    return esquerda

def main():
    n, k = map(int, input().split())
    cowbells = list(map(int, input().split()))
    print(encontrar_menor_tamanho_caixa(n, k, cowbells))

if __name__ == "__main__":
    main()