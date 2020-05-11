import sys
from numpy import *

LIMIT = 101


def zero_Matrix(rows, cols):
    M = []
    while len(M) < rows:
        M.append([])
        while len(M[-1]) < cols:
            M[-1].append(0.0)

    return M


if __name__ == '__main__':
    sys.stdin = open('test.txt')

    while True:
        ligne = map(int, raw_input().strip().split())
        if ligne[0] == 0 and ligne[1] == 0:
            break
        nodes = list(set(ligne))
        nodes.sort()
        del nodes[0]
        nNodes = len(nodes)

        # Utilisation de numpy pour generer un type de matrice specifique
        # ici la matrice et vide puis chaque valeur est remplace par la valeur
        # limite
        graph = zeros((nNodes, nNodes), dtype=int)
        graph.fill(LIMIT)

        n = len(ligne) / 2 - 1
        for i in range(n):
            x = nodes.index(ligne[i * 2])
            y = nodes.index(ligne[i * 2 + 1])
            graph[x, y] = 1
            graph[x, x] = 0

        # floyd algorithme
        for k in range(nNodes):
            for i in range(nNodes):
                for j in range(nNodes):
                    graph[i, j] = min(graph[i, j], graph[i, k] + graph[k, j])

        resultat = sum(graph)
        # Affichage des resultat
        moyenne = resultat * 1.0 / (nNodes ** 2 - nNodes)
        print 'taille moyenne entre chaque page = %.3f clicks' % moyenne
