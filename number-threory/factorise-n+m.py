MAX = 100000

# Função para realizar o crivo de Eratóstenes
def sieve():
    is_prime = [True] * (MAX + 1)
    is_prime[0] = is_prime[1] = False
    primes = []
    for i in range(2, MAX + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, MAX + 1, i):
                is_prime[j] = False
    return is_prime, primes

# Pré-calcula os números primos até MAX
is_prime, primes = sieve()

# Leitura do número de casos de teste
t = int(input())

# Processamento de cada caso de teste
for _ in range(t):
    n = int(input())  # Lê o número primo n
    # Encontra o menor primo m tal que n + m não seja primo
    for m in primes:
        if not is_prime[n + m]:
            print(m)
            break
