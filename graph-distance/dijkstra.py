import heapq
import sys

def dijkstra(n, adj):
    dist = [float('inf')] * (n + 1)  # distâncias infinitas
    parent = [-1] * (n + 1)  # vetor para rastrear o caminho
    dist[1] = 0  # Distância do nó 1 para ele mesmo
    pq = []  # fila de prioridade (min-heap)
    heapq.heappush(pq, (0, 1))  # (distância, nó)

    while pq:
        d, node = heapq.heappop(pq)

        if d != dist[node]:
            continue

        for neighbor, weight in adj[node]:
            if dist[node] + weight < dist[neighbor]:
                dist[neighbor] = dist[node] + weight
                parent[neighbor] = node
                heapq.heappush(pq, (dist[neighbor], neighbor))

    if dist[n] == float('inf'):
        print(-1)  # Se não houver caminho para o nó n
    else:
        path = []
        node = n
        while node != -1:
            path.append(node)
            node = parent[node]
        path.reverse()  # Inverte o caminho para começar do nó 1
        print(" ".join(map(str, path)))

def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b, w = map(int, input().split())
        adj[a].append((b, w))
        adj[b].append((a, w))  # Grafo não direcionado

    dijkstra(n, adj)

if __name__ == "__main__":
    main()
